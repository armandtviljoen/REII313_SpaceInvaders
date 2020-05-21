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
    if (event->key() == Qt::Key_Escape){
        game->esc();
    }

// Movements when in single player.
    if(game->MuliplayerMode == false){
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
// Movements when in Multiplayer.
    if((game->MuliplayerMode == true)&&(game->MultiGameHasStarted == true)){
// Movements you are the server.
    if(game->IAmTheServer==true){
        if ((event->key() == Qt::Key_Left)&&(game->health->getHealth() > 0)){
            if (pos().x() > 0)
            setPos(x()-10,y());
            game->socket->Send("L");
        }
        else if ((event->key() == Qt::Key_Right)&&(game->health->getHealth() > 0)){
            if (pos().x() + 100 < 800)
            setPos(x()+10,y());
            game->socket->Send("R");
        }
        // Shoot.
        else if ((event->key() == Qt::Key_Space)&&(game->health->getHealth() > 0)){
            // Spawn bullet.
            Bullet * bullet = new Bullet();
            bullet->setPos(x()+25,y());
            scene()->addItem(bullet);
            game->socket->Send("S");
        }
    }
    if(game->IAmTheServer==false){
        if ((event->key() == Qt::Key_A)&&(game->health->getHealth() > 0)){
            if (pos().x() > 0)
            setPos(x()-10,y());
            game->socket->Send("L");
        }
        else if ((event->key() == Qt::Key_D)&&(game->health->getHealth() > 0)){
            if (pos().x() + 100 < 800)
            setPos(x()+10,y());
            game->socket->Send("R");
        }
        // Shoot.
        else if ((event->key() == Qt::Key_P)&&(game->health->getHealth() > 0)){
            // Spawn bullet.
            Bullet * bullet = new Bullet();
            bullet->setPos(x()+25,y());
            scene()->addItem(bullet);
            game->socket->Send("S");
        }
    }

  }
}

void Player::spawn(){// Spawning enemies.
// When playing single player:
    if(game->MuliplayerMode == false){
        if(game->health->getHealth() > 0){
           Enemy * enemy = new Enemy();
           scene()->addItem(enemy);
           int random_number = rand() % 700;
           enemy->setPos(random_number,0);
        }
    }
// When playing multiplayer player and hosting the game:
    if((game->MuliplayerMode == true)&&(game->IAmTheServer == true)&&(game->MultiGameHasStarted == true)){
        if(game->health->getHealth() > 0){
           Enemy * enemy = new Enemy();
           scene()->addItem(enemy);
           int random_number = rand() % 700;
           enemy->setPos(random_number,0);
           game->socket->Send("E_" + QString::number(random_number));
        }
    }
}

Player2::Player2(QGraphicsItem *parent)
{
    // Draw player.
    setPixmap(QPixmap(":/Images/player.png"));
}

void Player2::MessageFromSocket(QString action)
{
    if ((action == "Start")&&(game->IAmTheServer == true)){
        game->MultiGameHasStarted = true;
        delete game->Connection;
        }
    if (action == "L"){
        if (pos().x() > 0)
        setPos(x()-10,y());
        }
    if (action == "R"){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
        }
    if (action == "S"){
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+25,y());
        scene()->addItem(bullet);
        }
     if (action[0] == "E"){
         QString pos ;
          for(int i = 2 ; i < action.length();i ++)
          {
              pos.append(action[i]);
          }
          Enemy * enemy = new Enemy();
          scene()->addItem(enemy);
          enemy->setPos(pos.toInt(),0);
        }
}


