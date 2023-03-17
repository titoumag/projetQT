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

     auto* label = new QLabel("Puissance 4");
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label, 0, 0, 1, 2);


    auto *vbox = new QVBoxLayout();
    layout->addLayout(vbox, 1, 2, 2, 1);
    listeParam = new Param*[]{
            new Param("Nb de colonne :", 5, 15,10),
            new Param("Nb de joueur :", 2,4,2),
            new Param("Nb de pion a aligner :", 3,6,4)
    };
    vbox->addWidget(new QLabel("Paramètres :"));
    for (int i = 0; i < 3; ++i) {
        vbox->addWidget(listeParam[i]);
    }

    newGameButton = new QPushButton("Nouvelle partie");
    connect(newGameButton, &QPushButton::pressed, this, &Windows::newGame);
    vbox->addWidget(newGameButton);
    vbox->addStretch();


    board = new Board(2, 4, 10);
    board->setFixedSize(500, 400);
    layout->addWidget(board, 1, 0, 1, 1);

//    buttonCol = std::vector<QPushButton*>();
    hbox = new QHBoxLayout();
    layout->addLayout(hbox, 3, 0, 1, 1);

    setWindowTitle("Puissance 4");
    newGame();

}

void Windows::newGame() {
    int width = listeParam[0]->getVal();
    board->newGame(listeParam[1]->getVal(),listeParam[2]->getVal(),width);

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

