//
// Created by titou on 20/03/2023.
//

#ifndef PROJET_RESEAU_H
#define PROJET_RESEAU_H

#include <QWidget>
#include <QPushButton>
#include "ClientTcp.h"
#include "ServeurTcp.h"

class Board;
class Windows;
class Reseau : public QWidget {
    Q_OBJECT
private:
    ClientTcp *client;
    ServeurTcp *serveur;
    Windows *windows;
    QString IP;
    QPushButton *boutonServeur;
    QPushButton *boutonClient;
    bool newGame;

public slots:
    void setIP(QString IP2);
    void setServeur();
    void setClient();
    void envoieCoup(int i);

public:
    Reseau(Windows *windows);
    bool isServeur;
    bool isConnected;

    void envoieNouvellePartie();
};


#endif //PROJET_RESEAU_H
