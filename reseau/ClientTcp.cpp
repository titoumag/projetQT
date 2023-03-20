#include <iostream>
#include "ClientTcp.h"

ClientTcp::ClientTcp(QString IP2)
{
    port=4000; // choix arbitraire (>1024)
    soc = new QTcpSocket(this);

    QObject::connect(soc,SIGNAL(connected()),this,SLOT(connexion_OK()));
    connect(soc, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this,
            SLOT(erreurSocket(QAbstractSocket::SocketError)));

    // signal émis lors de la connexion au serveur
    // signal émis lorsque des données sont prêtes à être lues
    std::cout<<"Client en écoute"<<std::endl;
    std::cout<<"-"<<IP2.toStdString()<<"-"<<std::endl;
    IP=IP2;
    soc->connectToHost(IP,port); // pour se connecter au serveur
}

void ClientTcp::erreurSocket(QAbstractSocket::SocketError erreur)
{
    switch(erreur) // On affiche un message différent selon l'erreur qu'on nous indique
    {
        case QAbstractSocket::HostNotFoundError:
            std::cout<<"<em>ERREUR : le serveur n'a pas pu être trouvé.Vérifiez l'IP et le port.</em>"<<std::endl;
            break;
        case QAbstractSocket::ConnectionRefusedError:
            std::cout<<"<em>ERREUR : le serveur a refusé la connexion. Vérifiez si le programme \"serveur\" a bien été lancé. Vérifiez aussi l'IP et leport.</em>"<<std::endl;
            break;
        case QAbstractSocket::RemoteHostClosedError:
            std::cout<<"<em>ERREUR : le serveur a coupé la connexion.</em>"<<std::endl;
            break;
        default:
            std::cout<<"<em>ERREUR : "<< soc->errorString().data() <<std::endl;
    }
}


void ClientTcp::connexion_OK()
{
    std::cout<<"Connexion OK"<<std::endl;
    QObject::connect(soc, SIGNAL(readyRead()),this, SLOT(recoitCoup()));
    emit vers_IHM_connexion(); // on envoie un signal à l'IHM
}

void ClientTcp::recoitCoup() {
    int col = atoi(soc->readLine());
    emit coupJoueeReseau(col);
    std::cout<<col<<std::endl;
}

void ClientTcp::envoyerCoup(int i) {
    soc->write(std::to_string(i).c_str());
}
