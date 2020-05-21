#include "texts.h"
#include "health.h"
#include "score.h"
#include "game.h"

#include <QBrush>
#include <QInputDialog>
#include <QLabel>


extern Game * game;

//*****************************************************************************************************************
GameOver::GameOver(QGraphicsItem *parent): QGraphicsTextItem(parent){

    // Draw text.
    setPlainText(QString("  Thank you for defending the capital,\n\t\tYou killed: ") + QString::number(game->score->getScore()) + " enemies");
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",30));

}
//*****************************************************************************************************************
ClientText::ClientText(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw the rect
    setRect(0,0,100,20);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    setAcceptHoverEvents(true);
}

void ClientText::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void ClientText::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

void ClientText::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);
}

//*****************************************************************************************************************
CP::CP(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw the rect
    setRect(0,0,100,20);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    setAcceptHoverEvents(true);
}

void CP::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void CP::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

void CP::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);
}

//*****************************************************************************************************************
ServerText::ServerText(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw the rect
    setRect(0,0,100,20);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    setAcceptHoverEvents(true);
}

void ServerText::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void ServerText::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

void ServerText::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);
}
//*****************************************************************************************************************
SP::SP(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw the rect
    setRect(0,0,100,20);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    setAcceptHoverEvents(true);
}

void SP::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void SP::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

void SP::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);
}
//*****************************************************************************************************************
TitleText::TitleText(QGraphicsItem *parent)
{
    setPlainText(QString("SpaceInvaders"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",50));

}

ClientIP::ClientIP(QGraphicsItem *parent)
{
    setPlainText(game->ClientIPAddress);
    setDefaultTextColor(Qt::gray);
    setFont(QFont("times",10));
}

ServerIP::ServerIP(QGraphicsItem *parent)
{
    setPlainText(game->ServerIPAddress);
    setDefaultTextColor(Qt::gray);
    setFont(QFont("times",10));
}


ClientPort::ClientPort(QGraphicsItem *parent)
{
    setPlainText(game->Clientprt);
    setDefaultTextColor(Qt::gray);
    setFont(QFont("times",10));
}

ServerPort::ServerPort(QGraphicsItem *parent)
{
    setPlainText(game->Serverprt);
    setDefaultTextColor(Qt::gray);
    setFont(QFont("times",10));
}
