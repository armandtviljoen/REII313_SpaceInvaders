#ifndef TEXTS_H
#define TEXTS_H

#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QFont>
#include <QObject>

//*********************************************************************
class TitleText: public QGraphicsTextItem{

public:
    TitleText(QGraphicsItem * parent=0);

};
//*********************************************************************
class GameOver: public QGraphicsTextItem{
public:
    GameOver(QGraphicsItem * parent=0);
    int Score();
};
//*********************************************************************
class ClientText:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // constructors
    ClientText(QString name, QGraphicsItem* parent=NULL);

    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};

class CP:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // constructors
    CP(QString name, QGraphicsItem* parent=NULL);

    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};

class ClientIP: public QGraphicsTextItem{
public:
    ClientIP(QGraphicsItem * parent=0);

};

class ClientPort: public QGraphicsTextItem{
public:
    ClientPort(QGraphicsItem * parent=0);

};
//*********************************************************************
class ServerText:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // constructors
    ServerText(QString name, QGraphicsItem* parent=NULL);

    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};

class SP:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // constructors
    SP(QString name, QGraphicsItem* parent=NULL);

    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};


class ServerIP: public QGraphicsTextItem{
public:
    ServerIP(QGraphicsItem * parent=0);

};

class ServerPort: public QGraphicsTextItem{
public:
    ServerPort(QGraphicsItem * parent=0);

};
//*********************************************************************
#endif // TEXTS_H
