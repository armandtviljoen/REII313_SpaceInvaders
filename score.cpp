#include "score.h"

#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Set score.
    score = 0;

    // Draw score.
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

int Score::getScore(){
    return score;
}
