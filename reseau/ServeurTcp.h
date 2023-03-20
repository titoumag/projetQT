//
// Created by titou on 20/03/2023.
//

#ifndef PROJET_SERVEURTCP_H
#define PROJET_SERVEURTCP_H
#include <QTcpServer>
#include <QTcpSocket>

class Reseau;
class ServeurTcp : public QTcpServer {
    Q_OBJECT


public :
    ServeurTcp(Reseau* reseau);
    void envoyerCoup(int i);

private slots :
    void demande_connexion() ;
    void recoitCoup();

signals :
    void vers_IHM_connexion();
    void coupJoueeReseau(int);
private :
    QTcpSocket *clientConnection;
    Reseau* reseau;

};

#endif //PROJET_SERVEURTCP_H
