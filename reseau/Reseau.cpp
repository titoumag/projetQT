//
// Created by titou on 20/03/2023.
//

#include <QLineEdit>
#include "Reseau.h"
#include "QPushButton"

Reseau::Reseau(Windows *windows) : windows(windows) {
    isServeur = false;
    isConnected = false;
    port = 0;
    IP = "";

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
    isServeur = true;
    isConnected=true;
    serveur = new ServeurTcp(this);
    QObject::connect(serveur, SIGNAL(vers_IHM_connexion()), windows, SLOT(nouvellePartieReseau()));
    QObject::connect(serveur, SIGNAL(coupJoueeReseau(int)), windows, SLOT(addPieceReseau(int)));
}

void Reseau::setClient() {
    isServeur = false;
    isConnected=true;
    client = new ClientTcp(IP);
    QObject::connect(client, SIGNAL(vers_IHM_connexion()), windows, SLOT(nouvellePartieReseau()));
    QObject::connect(client, SIGNAL(coupJoueeReseau(int)), windows, SLOT(addPieceReseau(int)));
}

void Reseau::envoieCoup(int i) {
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


