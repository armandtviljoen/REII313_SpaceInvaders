#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/Images/Background.jpg")));

    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Player();
    player->setPos(400,500);

    // make the player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add the player to the scene
    scene->addItem(player);


    // spawn enemies
    QTimer * timer = new QTimer();
    timer->start(2000);


    show();
}
