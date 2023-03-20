//
// Created by titou on 20/03/2023.
//

#ifndef PROJET_CLIENTTCP_H
#define PROJET_CLIENTTCP_H


#include <QObject>
#include <QTcpSocket>

class ClientTcp : public QObject
{
    Q_OBJECT
public :
    ClientTcp(QString IP2);
    void envoyerCoup(int i);
private slots :
//    void demande_connexion() ;
    void recoitCoup();
    void connexion_OK();  // en provenance de la socket et émet un signal vers l'IHM
    void erreurSocket(QAbstractSocket::SocketError);
signals :
    void vers_IHM_connexion();
    void coupJoueeReseau(int);

//public slots :
//            void recoit_IP(QString IP2);  // en provenance de l'IHM et se connecte au serveur
//    void recoit_texte(QString t); // en provenance de l'IHM et écrit sur la socket
//private slots :
//    void lecture();       // en provenance de la socket, lit la socket, émet un signal vers l'IHM
//    signals :
//            void vers_IHM_connexion_OK();
//    void vers_IHM_texte(QString);

private :
    QString IP;
    int port;
    QTcpSocket* soc;
};

#endif //PROJET_CLIENTTCP_H
