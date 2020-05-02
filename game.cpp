#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>


Game::Game(QWidget *parent){
    // Create scene.
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/Images/Background.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

        // Create player.
        player = new Player();
        player->setPos(400,500);

        // Set focus on player.
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();

        // Add player.
        scene->addItem(player);

        // Add score/health.
        score = new Score();
        scene->addItem(score);
        health = new Health();
        health->setPos(health->x(),health->y()+25);
        scene->addItem(health);

        // Spawn enemies
        QTimer * timer = new QTimer();
        QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
        timer->start(2000);


        show();
}







