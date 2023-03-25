//
// Created by titou on 20/03/2023.
//

#include "Reseau.h"
#include <QLineEdit>
#include <QNetworkInterface>
#include <iostream>
#include <QLabel>
#include <QTimer>
#include <QGridLayout>
#include "../Windows.h"


Reseau::Reseau(Windows *windows) : windows(windows) {
    isServeur = false;
    isConnected = false;
    IP = "";
    newGame = true;

    auto *layout = new QGridLayout(this);
    setLayout(layout);

    boutonServeur = new QPushButton("Serveur");
    layout->addWidget(boutonServeur,0,0);
    QObject::connect(boutonServeur, SIGNAL(clicked()), this, SLOT(setServeur()));

    auto* ip = new QLineEdit("127.0.0.1");
    IP=ip->text();
    layout->addWidget(ip,1,0);
    QObject::connect(ip, SIGNAL(textChanged(QString)), this, SLOT(setIP(QString)));

    boutonClient = new QPushButton("Client");
    layout->addWidget(boutonClient,2,0);
    QObject::connect(boutonClient, SIGNAL(clicked()), this, SLOT(setClient()));
}

void Reseau::setServeur() {
    windows->labelMessage->setText("Serveur initialisé (addr ip: "+QNetworkInterface::allAddresses()[1].toString()+" )");
    windows->timer->stop();
    isServeur = true;
    isConnected=true;
    boutonServeur->setEnabled(false);
    boutonClient->setEnabled(false);
    boutonServeur->setText("Serveur initialisé");
    boutonClient->setText("--");
    serveur = new ServeurTcp();
    QObject::connect(serveur, SIGNAL(vers_IHM_connexion()), windows, SLOT(nouvellePartieReseau()));
    QObject::connect(serveur, SIGNAL(coupJoueeReseau(int)), windows, SLOT(addPieceReseau(int)));
}

void Reseau::setClient() {
    windows->labelMessage->setText("Client connecté à l'adresse ip: "+IP);
    isServeur = false;
    isConnected=true;
    boutonServeur->setEnabled(false);
    boutonServeur->setText("--");
    client = new ClientTcp(IP);
    QObject::connect(client, SIGNAL(vers_IHM_connexion()), windows, SLOT(nouvellePartieReseau()));
    QObject::connect(client, SIGNAL(coupJoueeReseau(int)), windows, SLOT(addPieceReseau(int)));
}

void Reseau::envoieCoup(int i) {
    newGame = true;
    if (isConnected && i!=-2) {
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
            if (serveur->isConnected)
                serveur->envoyerCoup(-1);
            else {
                windows->labelMessage->setText("Serveur deconnecté, nouvelle partie locale");
                isConnected = false;
                delete serveur;
            }
        } else {
            client->envoyerCoup(-1);
        }
    }
}


