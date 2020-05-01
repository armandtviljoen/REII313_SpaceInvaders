#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"

extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw graphics
    setPixmap(QPixmap(":/Images/bullet.png"));


    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Bullet::move(){

    // Move the bullet forward
    setPos(x(),y()-10);
    // if the bullet is off the screen, destroy it
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
