//
// Created by titou on 20/03/2023.
//

#ifndef PROJET_RESEAU_H
#define PROJET_RESEAU_H


#include "ClientTcp.h"
#include "ServeurTcp.h"
#include "../Board.h"
#include "../Windows.h"

class Reseau : public QWidget {
    Q_OBJECT
private:
    ClientTcp *client;
    ServeurTcp *serveur;
    Windows *windows;
    bool isServeur;
    bool isConnected;
    int port;
    QString IP;
public slots:
    void setIP(QString IP2);
    void setServeur();
    void setClient();
    void envoieCoup(int i);

public:
    Reseau(Windows *windows);


};


#endif //PROJET_RESEAU_H