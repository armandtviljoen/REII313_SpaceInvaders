#include "enemy.h"

#include <QTimer>
#include <QGraphicsScene>

#include <stdlib.h>
#include "game.h"

extern Game * game;


Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // Set randpm starting position.
    int random_number = rand() % 700;
    setPos(random_number,0);

    // Draw enemy.
    setPixmap(QPixmap(":/Images/invader.png"));
    setTransformOriginPoint(50,50);

    // Connect timer.
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // Start timer.
    timer->start(50);
}

void Enemy::move(){
    // Move enemy.

    if(game->health->getHealth()==0){
        delete this;
    }   else{
            setPos(x(),y()+5);
            if (pos().y() > 530){
                setPixmap(QPixmap(":/Images/boom.png"));
            }
            // Destroy on screen exit.
            if (pos().y() > 600){
                // Decrease health.
                game->health->decrease();

                scene()->removeItem(this);
                delete this;}
        }
}
