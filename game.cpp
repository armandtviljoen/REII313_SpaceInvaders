#include "game.h"
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <QInputDialog>
#include <QTextEdit>
#include <QKeyEvent>


Game::Game(QWidget *parent){
    // Create scene.

    IAmTheServer = false;
    ClientIPAddress = "192.168.101.131";
    ServerIPAddress = "192.168.101.131";
    Clientprt ="1235";
    Serverprt = "1234";
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/Images/Background.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

}

void Game::start()
{

    scene->clear();
    MuliplayerMode = false;
    MultiGameHasStarted = false;

    // Create player.
    player = new Player();
    player->setPos(400,500);

    // Set focus on player.
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // Add player.
    scene->addItem(player);

    // Add score/health.
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // Spawn enemies
    enemytimer = new QTimer;
    connect(enemytimer,SIGNAL(timeout()),player,SLOT(spawn()));
    enemytimer->start(1500);

    show();
}

void Game::startMultiMode()
{
    scene->clear();
    MultiGameHasStarted = false;
    MuliplayerMode = true;
    socket = new Server;

    if (IAmTheServer == true)
    {
        socket->initSocketServer();
        Connection = new TitleText;
        Connection->setPlainText("Waiting for your partner");
        int cxPos = this->width()/2 - Connection->boundingRect().width()/2;
        int cyPos = 150;
        Connection->setPos(cxPos,cyPos);
        scene->addItem(Connection);
    }
    else
    {
        socket->initSocketClient();
        socket->Send("Start");
        MultiGameHasStarted = true;
    }

    // Player creation if you are the host.
    if(IAmTheServer == true){
        player = new Player();
        player->setPos(300,500);

        player2 = new Player2();
        player2->setPos(450,500);
    }
    // Player creation if you are not the host.
    if(IAmTheServer == false){
        player = new Player();
        player->setPos(450,500);

        player2 = new Player2();
        player2->setPos(300,500);
    }

    // Set focus on player.
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();      

    // Add players.
    scene->addItem(player);
    scene->addItem(player2);

    // Add score/health.
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // Spawn enemies + socket timer

    if(IAmTheServer == true){
        enemytimer = new QTimer;
        connect(enemytimer,SIGNAL(timeout()),player,SLOT(spawn()));
        enemytimer->start(1500);
    }
    sockettimer = new QTimer;
    connect(sockettimer,SIGNAL(timeout()),socket,SLOT(Receive()));
    sockettimer->start(5);
}

void Game::updateScene()
{
    scene->clear();
    displayMainMenu();
}


void Game::clientSetup()
{
    IAmTheServer = false;
    this->startMultiMode();

}

void Game::serverSetup()
{
    IAmTheServer = true;
    this->startMultiMode();
}

void Game::getIP()
{
    system("ipconfig" "&pause");
}

void Game::changeCIP()
{
    this->ClientIPAddress  = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                                                   tr("New Client IP"), QLineEdit::Normal);
    updateScene();
}

void Game::changesprt()
{
    this->Serverprt  = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                                                   tr("New Client Port"), QLineEdit::Normal);
    updateScene();
}

void Game::esc()
{
    if(MuliplayerMode == false){
        delete player;
        delete score;
        delete health;
        delete enemytimer;
        scene->clear();
        displayMainMenu();
    }
    if(MuliplayerMode == true){
        delete player;
        delete player2;
        delete score;
        delete health;
        delete enemytimer;
        delete socket;
        delete sockettimer;
        scene->clear();
        displayMainMenu();
    }
}

void Game::changecprt()
{
    this->Clientprt  = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                                                   tr("New Client Port"), QLineEdit::Normal);
    updateScene();
}


void Game::changeSIP()
{
    this->ServerIPAddress  = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                                                   tr("New Server IP"), QLineEdit::Normal);
    updateScene();
}


void Game::displayMainMenu()
{

    titleText = new TitleText;
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    ServerText* servertext = new ServerText(QString("Change Server IP"));
    servertext->setPos(10,30);
    scene->addItem(servertext);
    connect(servertext,SIGNAL(clicked()),this,SLOT(changeSIP()));
    SP* sp = new SP(QString("Change Server Port"));
    sp->setPos(10,60);
    scene->addItem(sp);
    connect(sp,SIGNAL(clicked()),this,SLOT(changesprt()));
    serverip = new ServerIP;
    serverip->setPos(120,27);
    scene->addItem(serverip);
    sport = new ServerPort;
    sport->setPos(120,57);
    scene->addItem(sport);

    ClientText* clienttext = new ClientText(QString("Change Client IP"));
    clienttext->setPos(10,90);
    scene->addItem(clienttext);
    connect(clienttext,SIGNAL(clicked()),this,SLOT(changeCIP()));
    CP* cp = new CP(QString("Change Client Port"));
    cp->setPos(10,120);
    scene->addItem(cp);
    connect(cp,SIGNAL(clicked()),this,SLOT(changecprt()));
    clientip = new ClientIP;
    clientip->setPos(120,93);
    scene->addItem(clientip);
    cport = new ClientPort;
    cport->setPos(120,117);
    scene->addItem(cport);


    // create the Host button
    Button* singleP = new Button(QString("Single Player"));
    int spxPos = this->width()/2 - singleP->boundingRect().width()/2;
    int spyPos = 275;
    singleP->setPos(spxPos,spyPos);
    connect(singleP,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(singleP);

    // create the Host button
    Button* hostButton = new Button(QString("Host"));
    int hxPos = this->width()/2 - 210;
    int hyPos = 350;
    hostButton->setPos(hxPos,hyPos);
    connect(hostButton,SIGNAL(clicked()),this,SLOT(serverSetup()));
    scene->addItem(hostButton);

    // create the client button
    Button* joinbutton = new Button(QString("Join"));
    int jxPos = this->width()/2 + 10;
    int jyPos = 350;
    joinbutton->setPos(jxPos,jyPos);
    connect(joinbutton,SIGNAL(clicked()),this,SLOT(clientSetup()));
    scene->addItem(joinbutton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 425;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

    // create the IPconfig button
    Button* ipConfig = new Button(QString("Get IP"));
    int ixPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int iyPos = 500;
    ipConfig->setPos(ixPos,iyPos);
    connect(ipConfig,SIGNAL(clicked()),this,SLOT(getIP()));
    scene->addItem(ipConfig);


}

