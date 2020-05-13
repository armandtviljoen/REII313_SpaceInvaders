#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

#include "player.h"
#include "score.h"
#include "health.h"
#include "enemy.h"
#include "button.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);
    void displayMainMenu();

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

public slots:
    void start();



};

#endif // GAME_H
