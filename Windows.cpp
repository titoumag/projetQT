#include "reseau/Reseau.h"
#include <iostream>
#include <QSlider>
#include <QTimer>
#include <QLabel>
#include <unistd.h>
#include <QCheckBox>
#include "Param.h"
#include "Windows.h"

Windows::Windows() {
    auto* layout = new QGridLayout(this);
    tempsTimer=0;
    timerActif=false;

    label = new QLabel("Puissance 4");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("QLabel { font: 18pt; }");
    layout->addWidget(label, 0, 0, 1, 1);

    labelMessage = new QLabel("--");
    labelMessage->setAlignment(Qt::AlignCenter);
    layout->addWidget(labelMessage, 1, 0, 1, 1);

    lcdTimer = new QLCDNumber();
    lcdTimer->setSegmentStyle(QLCDNumber::Flat);
    lcdTimer->setDigitCount(5);
    lcdTimer->display("--:--");
    lcdTimer->setFixedWidth(100);
    layout->addWidget(lcdTimer, 0, 1, 1, 1);


    auto *vbox = new QVBoxLayout();
    layout->addLayout(vbox, 1, 1, 4, 1);
    addWidgetDroite(vbox);


    board = new Board(this);
    board->setFixedSize(500,400);
    layout->addWidget(board, 2, 0, 1, 1);
    connect(board,SIGNAL(win(Color)),this,SLOT(gagne(Color)));
    connect(board,SIGNAL(addPieceOk(int)),this,SLOT(addPieceOk(int)));

    hbox = new QHBoxLayout();
    layout->addLayout(hbox, 3, 0, 1, 1);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    setWindowTitle("Puissance 4");
//    newGame();
}

void Windows::addWidgetDroite(QVBoxLayout* vbox){
    listeParam = new Param*[NB_PARAM]{
            new Param("Nb de joueur :", 2,4,2),
            new Param("Nb de pion a aligner :", 1,6,4),
            new Param("Nb de colonne :", 5, 25,10),
            new Param("Nb de ligne :", 5, 15,8),
            new Param("Vitesse descente pion :",20,200,80),
            new Param("Timer (=temps par coups) :",5,100,20)
    };
    for (int i = 0; i < NB_PARAM; ++i) {
        listeParam[i]->setFixedWidth(200);
        vbox->addWidget(listeParam[i]);
    }

    auto* timerBool = new QCheckBox("Activer le timer");
    vbox->addWidget(timerBool);
    connect(timerBool,SIGNAL(stateChanged(int)),this,SLOT(changeModeTimer(int)));

    newGameButton = new QPushButton("Nouvelle partie");
    newGameButton->setFixedWidth(200);
    connect(newGameButton, &QPushButton::pressed, this, &Windows::newGame);
    vbox->addWidget(newGameButton);

    auto* resertParam = new QPushButton("Réinitialiser les paramètres");
    resertParam->setFixedWidth(200);
    connect(resertParam, &QPushButton::pressed, [=](){
        for (int i = 0; i < NB_PARAM; ++i) {
            listeParam[i]->defautParam();
        }
    });
    vbox->addWidget(resertParam);
    vbox->addStretch();

    reseau = new Reseau(this);
    vbox->addWidget(reseau);
}

void Windows::changeModeTimer(int mode){
    timerActif= mode==2;
}

void Windows::newGame() {
    if (!reseau->isConnected)
        label->setText("Le joueur 1 commence");
    reseau->envoieNouvellePartie();
    int width = getVal(WIDTH);
    board->newGame(getVal(NB_JOUEUR), getVal(PUISSANCE), width, getVal(HEIGTH), getVal(VITESSE));

    while (hbox->count() > 0) {
        auto* item = hbox->takeAt(0);
        delete item->widget();
        delete item;
    }
    for (int i = 0; i < width; i++) {
        auto* button = new QPushButton(QString::number(i+1));
        button->setFixedHeight(40);
        button->setFixedWidth(41);
        hbox->addWidget(button);
        connect(button, &QPushButton::pressed, this, [=](){if (coupAutorise()) board->addPiece(i);});
    }

    tempsTimer= tempsPartie = getVal(TEMPS)*100;
    if (timerActif){
        lcdTimer->display(tempsTimer);
        timer->start(10);
    }else {
        lcdTimer->display("--:--");
        timer->stop();
    }
}

void Windows::updateTimer() {
    tempsTimer--;
    char t[5];
    sprintf(t,"%d:%d%d",tempsTimer/100,tempsTimer/10%10,tempsTimer%10);
    lcdTimer->display(t);
    if (tempsTimer<500){
        if (tempsTimer/50%2==1)
            lcdTimer->setStyleSheet("color: red; border-color:red; border-style: solid;border-width: 2px;");
        else
            lcdTimer->setStyleSheet("color: none;border-color:white;");
    }
    if (tempsTimer==-1){
        timer->stop();
        addPieceOk(-2);
        board->changeJoueur();
        sleep(1);
    }
}

int Windows::getVal(int i) const {
    return listeParam[i]->getVal();
}

void Windows::gagne(Color joueur) {
    timer->stop();
    if (reseau->isConnected) {
        if (((int) reseau->isServeur + board->joueurActuel()) % 2 == 1) label->setText("Vous avez gagné !");
        else label->setText("Vous avez perdu !");
    }else
        label->setText("Le joueur " + QString::number((int)joueur+1) + " a gagné !");
}

void Windows::addPieceOk(int col) {
    if (timerActif){
    tempsTimer= tempsPartie;
    timer->start();
    }
    lcdTimer->setStyleSheet("color: none;border-color:white");
    reseau->envoieCoup(col);
    if (reseau->isConnected) {
        if (((int) reseau->isServeur + board->joueurActuel()) % 2 == 1) label->setText("A l'adversaire de jouer");
        else label->setText("A vous de jouer");
    }else
        label->setText("Au tour du joueur " + QString::number(((int)board->joueurActuel()+1)%board->getNbJoueur()+1));
}

void Windows::nouvellePartieReseau() {
    for (int i = 0; i < NB_PARAM; ++i) {
        listeParam[i]->defautParam();
    }
    newGame();
    if (reseau->isServeur) label->setText("Connecté au client - A vous de jouer");
    else label->setText("Connecté au serveur - Au tour de l'adversaire");
}

void Windows::addPieceReseau(int i) {
    if (i==-1) newGame();
    else board->addPiece(i);
}

bool Windows::coupAutorise() const {
    return !reseau->isConnected || (board->joueurActuel()==0  && reseau->isServeur) || (board->joueurActuel()==1  && !reseau->isServeur);
}
