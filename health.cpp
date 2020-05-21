#include "health.h"
#include "score.h"
#include "game.h"
#include <QFont>

extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Set health.
    health = 3;

    // Draw health.
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    if (health <= 0)
    {
     setPlainText(QString("No lives left"));
     GameOver * gameover = new GameOver;
     gameover->setPos(60,100);
     scene()->addItem(gameover);

    }

    if (health > 0) {
        setPlainText(QString("Health: ") + QString::number(health));}
}

int Health::getHealth(){
    return health;
}
