#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>

class Server : public QObject
{
    Q_OBJECT
    public:
        void initSocketServer();
        void initSocketClient();
        void Send(QString Send);

        Server();
        ~Server();

        QString From;
        QString Port;
        QString Message;
        QUdpSocket *udpSocket;

    public slots:
        void Receive();
    private:

};

#endif // SERVER_H
