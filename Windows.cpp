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
    int nbcol=10;

     auto* label = new QLabel("Puissance 4");
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label, 0, 0, 1, 2);


    auto *vbox = new QVBoxLayout();
    layout->addLayout(vbox, 1, 2, 2, 1);
    vbox->addWidget(new QLabel("Paramètres :"));
    vbox->addWidget(new Param("Nb de colonne :", 5, 15,10));
    vbox->addWidget(new Param("Nb de joueur :", 2,4,2));
    vbox->addWidget(new Param("Nb de pion a aligner :", 3,6,4));
    newGameButton = new QPushButton("Nouvelle partie");
    connect(newGameButton, &QPushButton::pressed, this, &Windows::newGame);
    vbox->addWidget(newGameButton);
    vbox->addStretch();


    board = new Board(2, 4, 10);
    board->setFixedSize(500, 400);
    layout->addWidget(board, 1, 0, 1, 1);

//    buttonCol = std::vector<QPushButton*>();
    auto *hbox = new QHBoxLayout();
    layout->addLayout(hbox, 3, 0, 1, 1);
    for (int i = 0; i < nbcol; i++) {
        auto* button = new QPushButton(QString::number(i+1));
        button->setFixedHeight(40);
        button->setFixedWidth(41);
        hbox->addWidget(button);
        connect(button, &QPushButton::pressed, this, [=](){board->addPiece(i);});
//        buttonCol.push_back(button);
    }

    setWindowTitle("Puissance 4");
}

void Windows::newGame() {
    board->newGame(2,4,10);
}

