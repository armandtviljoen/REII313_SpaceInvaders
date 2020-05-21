#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include "enemy.h"
#include "game.h"

extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // Draw bullet.
    setPixmap(QPixmap(":/Images/bullet.png"));


    // Move bullet.
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Bullet::move(){
    // Get a list of all the items currently colliding.
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // If one of the colliding items is an Enemy, destroy bullet and the enemy.
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // increase the score
            game->score->increase();

            this->setPixmap(QPixmap(":/Images/boom.png"));


            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them permanently
            delete colliding_items[i];
            delete this;

            return;
        }
    }

    // As long as no collision takes place, keep moving.
    setPos(x(),y()-10);

    // Destroy bullet on screen exit.
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}

void Bullet::delay()
{
    QTimer * delay = new QTimer;
    delay->setInterval(500);
    delay->start();
}


