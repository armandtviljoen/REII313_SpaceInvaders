#include "server.h"
#include "game.h"

extern Game * game;

Server::Server()
{

}

void Server::initSocketServer()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress(game->ServerIPAddress), game->Serverprt.toInt());
}

void Server::initSocketClient()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress(game->ClientIPAddress), game->Clientprt.toInt());

}


void Server::Send(QString Send)
{
    QByteArray Data;
    Data.append(Send);

    if (game->IAmTheServer == true)
    {
        udpSocket->writeDatagram(Data,QHostAddress(game->ClientIPAddress),game->Clientprt.toInt());
    }
    else
    {
        udpSocket->writeDatagram(Data,QHostAddress(game->ServerIPAddress),game->Serverprt.toInt());
    }
}

Server::~Server()
{
    delete this->udpSocket;
}

void Server::Receive()
{
    QByteArray Buffer;
    Buffer.resize(udpSocket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderport;

    udpSocket->readDatagram(Buffer.data(),Buffer.size(),&sender,&senderport);

    From = sender.toString();
    Port = senderport;
    Message = Buffer.data();

    qDebug() << "Message from:" << From;
    qDebug() << "Message port:" << senderport;
    qDebug() << "Message:" << Message;

    game->player2->MessageFromSocket(Message);

}
