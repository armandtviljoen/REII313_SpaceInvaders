#include "player.h"
#include "game.h"
#include <QGraphicsScene>
#include <QKeyEvent>

extern Game * game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    // Draw player.
    setPixmap(QPixmap(":/Images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    // Move left/right.
    if ((event->key() == Qt::Key_Left)&&(game->health->getHealth() > 0)){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if ((event->key() == Qt::Key_Right)&&(game->health->getHealth() > 0)){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // Shoot.
    else if ((event->key() == Qt::Key_Space)&&(game->health->getHealth() > 0)){
        // Spawn bullet.
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+25,y());
        scene()->addItem(bullet);

    }
}

void Player::spawn(){
    // Spawn enemy.
    if(game->health->getHealth() > 0){
        Enemy * enemy = new Enemy();
        scene()->addItem(enemy);
    }


}
