#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    // set graphic
    setPixmap(QPixmap(":/Images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_A){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_D){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+25,y());
        scene()->addItem(bullet);

    }
}

