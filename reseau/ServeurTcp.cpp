#include <QObject>
#include <QTextStream>
#include <iostream>

#include "ServeurTcp.h"


ServeurTcp::ServeurTcp() {
    listen(QHostAddress::Any, 4000);
    QObject::connect(this, SIGNAL(newConnection()),
                     this, SLOT(demande_connexion()));
    std::cout<<"Serveur en ecoute"<<std::endl;
}

void ServeurTcp::demande_connexion() {
//    // on crée une nouvelle socket pour ce client
    clientConnection = nextPendingConnection();
    emit vers_IHM_connexion(); // on envoie un signal à l'IHM
    // si on reçoit des données, le slot recoitCoup() est appelé
    QObject::connect(clientConnection, SIGNAL(readyRead()),
                     this, SLOT(recoitCoup()));
}

void ServeurTcp::recoitCoup() {
    int col = atoi(clientConnection->readLine());
    emit coupJoueeReseau(col);
}

void ServeurTcp::envoyerCoup(int i) {
    clientConnection->write(std::to_string(i).c_str());
}
