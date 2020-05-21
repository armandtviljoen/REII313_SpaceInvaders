#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>

#include "player.h"
#include "score.h"
#include "health.h"
#include "enemy.h"
#include "button.h"
#include "server.h"
#include "texts.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);
    void displayMainMenu();

    QGraphicsScene * scene;
    Player * player;
    Player2 * player2;
    Score * score;
    Health * health;
    Server * socket;

    TitleText * titleText;
    TitleText * Connection;
    ClientIP * clientip;
    ServerIP * serverip;
    ClientPort * cport;
    ServerPort * sport;
    QTimer * enemytimer;
    QTimer * sockettimer;

    bool IAmTheServer;
    bool MuliplayerMode;
    bool MultiGameHasStarted;

    QString ServerIPAddress;
    QString ClientIPAddress;
    QString Serverprt;
    QString Clientprt;


public slots:
    void start();
    void startMultiMode();
    void updateScene();
    void clientSetup();
    void serverSetup();
    void getIP();
    void changeCIP();
    void changeSIP();
    void changecprt();
    void changesprt();
    void esc();
};



#endif // GAME_H
