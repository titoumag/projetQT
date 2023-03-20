//
// Created by titou on 11/03/2023.
//

#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <iostream>
#include "Windows.h"
#include "Param.h"

Windows::Windows() {
//    auto* widgetCentral = new QWidget();
//    setCentralWidget(widgetCentral);
//    auto* layout = new QGridLayout(widgetCentral);
//    widgetCentral->setLayout(layout);
//    widgetCentral->resize(550, 450);
    auto* layout = new QGridLayout(this);
    tempsTimer=0;

    label = new QLabel("Puissance 4");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("QLabel { font: 18pt; }");
    layout->addWidget(label, 0, 0, 1, 1);

    lcdTimer = new QLCDNumber();
    lcdTimer->setSegmentStyle(QLCDNumber::Flat);
    lcdTimer->setDigitCount(5);
    lcdTimer->display(tempsTimer);
    layout->addWidget(lcdTimer, 0, 1, 1, 1);

    auto *vbox = new QVBoxLayout();
    layout->addLayout(vbox, 1, 1, 2, 1);
    listeParam = new Param*[NB_PARAM]{
            new Param("Nb de joueur :", 2,4,2),
            new Param("Nb de pion a aligner :", 3,6,4),
            new Param("Nb de colonne :", 5, 15,10),
            new Param("Nb de ligne :", 5, 12,8),
            new Param("Vitesse descente pion :",40,200,80),
            new Param("Timer (=temps par coups) :",5,100,20)
    };
//    vbox->addWidget(new QLabel("Paramètres :"));
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


    board = new Board();
    layout->addWidget(board, 1, 0, 1, 1);
    connect(board,SIGNAL(win(Color)),this,SLOT(gagne(Color)));
    connect(board,SIGNAL(addPieceOk()),this,SLOT(addPieceOk()));

    hbox = new QHBoxLayout();
    layout->addLayout(hbox, 3, 0, 1, 1);

    setWindowTitle("Puissance 4");
    newGame();
}

void Windows::newGame() {
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
        connect(button, &QPushButton::pressed, this, [=](){board->addPiece(i);});
    }
}

int Windows::getVal(int i) const {
    return listeParam[i]->getVal();
}

void Windows::gagne(Color joueur) {
    label->setText("Le joueur " + QString::number((int)joueur+1) + " a gagné !");
}

void Windows::addPieceOk() {
    std::cout << "addPieceOk" << std::endl;
}

