#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <QGraphicsTextItem>

class GameOver: public QGraphicsTextItem{
public:
    GameOver(QGraphicsItem * parent=0);
    int Score();



};

#endif // GAMEOVER_H
