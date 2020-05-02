#include "health.h"
#include "gameover.h"
#include "score.h"
#include "game.h"
#include <QFont>

extern Game * game;

GameOver::GameOver(QGraphicsItem *parent): QGraphicsTextItem(parent){

    // Draw text.
    setPlainText(QString(" Game_Over\n\tScore:") + QString::number(game->score->getScore()));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",38));

}
