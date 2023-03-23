#include "reseau/Reseau.h"
#include <iostream>
#include <QSlider>
#include <QTimer>
#include <QLabel>
#include "Param.h"
#include "Windows.h"

Windows::Windows() {
    auto* layout = new QGridLayout(this);
    tempsTimer=0;

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
    lcdTimer->display(tempsTimer);
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
            new Param("Nb de colonne :", 5, 15,10),
            new Param("Nb de ligne :", 5, 12,8),
            new Param("Vitesse descente pion :",40,200,80),
            new Param("Timer (=temps par coups) :",5,100,20)
    };
    for (int i = 0; i < NB_PARAM; ++i) {
        listeParam[i]->setFixedWidth(200);
        vbox->addWidget(listeParam[i]);
    }

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
    tempsPartie= getVal(TEMPS)*10;
    tempsTimer= tempsPartie;
    lcdTimer->display(tempsTimer);
    timer->start(100);
}

void Windows::updateTimer() {
    tempsTimer--;
    char t[5];
    snprintf(t,tempsTimer>=100?5:tempsTimer>=10?4:3,"%f",tempsTimer/10.0);
    lcdTimer->display(t);
    if (tempsTimer==0){
        timer->stop();
        addPieceOk(-2);
        board->changeJoueur();
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
    tempsTimer= tempsPartie;
    timer->start();
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
