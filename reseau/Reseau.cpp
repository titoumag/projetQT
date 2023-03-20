//
// Created by titou on 20/03/2023.
//

#include <QLineEdit>
#include <QNetworkInterface>
#include "Reseau.h"
#include "QLabel"
#include "QPushButton"

Reseau::Reseau(Windows *windows) : windows(windows) {
    isServeur = false;
    isConnected = false;
    IP = "";
    newGame = true;

    auto *layout = new QGridLayout(this);
    setLayout(layout);

    auto* boutonServeur = new QPushButton("Serveur");
    layout->addWidget(boutonServeur,0,0);
    QObject::connect(boutonServeur, SIGNAL(clicked()), this, SLOT(setServeur()));

    auto* ip = new QLineEdit("127.0.0.0");
    IP=ip->text();
    layout->addWidget(ip,1,0);
    QObject::connect(ip, SIGNAL(textChanged(QString)), this, SLOT(setIP(QString)));

    auto* boutonClient = new QPushButton("Client");
    layout->addWidget(boutonClient,2,0);
    QObject::connect(boutonClient, SIGNAL(clicked()), this, SLOT(setClient()));
}

void Reseau::setServeur() {
    windows->labelMessage->setText("Serveur initialisé (addr ip: "+QNetworkInterface::allAddresses()[1].toString()+" )");
    isServeur = true;
    isConnected=true;
    serveur = new ServeurTcp(this);
    QObject::connect(serveur, SIGNAL(vers_IHM_connexion()), windows, SLOT(nouvellePartieReseau()));
    QObject::connect(serveur, SIGNAL(coupJoueeReseau(int)), windows, SLOT(addPieceReseau(int)));
}

void Reseau::setClient() {
    windows->labelMessage->setText("Client connecté à l'adresse ip: "+IP);
    isServeur = false;
    isConnected=true;
    client = new ClientTcp(IP);
    QObject::connect(client, SIGNAL(vers_IHM_connexion()), windows, SLOT(nouvellePartieReseau()));
    QObject::connect(client, SIGNAL(coupJoueeReseau(int)), windows, SLOT(addPieceReseau(int)));
}

void Reseau::envoieCoup(int i) {
    newGame = true;
    if (isConnected) {
        if (isServeur) {
            serveur->envoyerCoup(i);
        } else {
            client->envoyerCoup(i);
        }
    }
}

void Reseau::setIP(QString IP2) {
    IP = IP2;
}

void Reseau::envoieNouvellePartie() {
    if (!newGame) return;
    newGame = false;
    if (isConnected) {
        if (isServeur) {
            serveur->envoyerCoup(-1);
        } else {
            client->envoyerCoup(-1);
        }
    }
}


