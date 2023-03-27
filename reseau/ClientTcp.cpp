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
    std::cout<<"Client en ecoute"<<std::endl;
    std::cout<<"-"<<IP2.toStdString()<<"-"<<std::endl;
    IP=IP2;
    soc->connectToHost(IP,port); // pour se connecter au serveur
}

void ClientTcp::erreurSocket(QAbstractSocket::SocketError erreur)
{
    switch(erreur) // On affiche un message différent selon l'erreur qu'on nous indique
    {
        case QAbstractSocket::HostNotFoundError:
            std::cerr<<"ERREUR : le serveur n'a pas pu être trouvé. Verifiez l'IP et le port."<<std::endl;
            break;
        case QAbstractSocket::ConnectionRefusedError:
            std::cerr<<"ERREUR : le serveur a refuse la connexion. Verifiez si le serveur a bien ete lance. Verifiez aussi l'IP et le port."<<std::endl;
            break;
        case QAbstractSocket::RemoteHostClosedError:
            std::cerr<<"ERREUR : le serveur a coupe la connexion."<<std::endl;
            break;
        default:
            std::cerr<<"ERREUR : "<< soc->errorString().data() <<std::endl;
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
}

void ClientTcp::envoyerCoup(int i) {
    soc->write(std::to_string(i).c_str());
}
