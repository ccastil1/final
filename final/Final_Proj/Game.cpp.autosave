#include "Game.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include "Score.h"
#include "Enemy.h"
#include "Player.h"

Game::Game(QWidget *parent){
    int spawn_rate = 2000;
    scene = new QGraphicsScene();
//    view = new QGraphicsView();
    scene->setSceneRect(0,0,800,600);   //set the QGraphicsScene to a specified size
    setBackgroundBrush(QBrush(QImage(":/images/star-background.png")));

    //make newly created scene
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //create the player
    player = new Player();
    //player->setRect(0,0,100,100);
    player->setPos(400,500);
    //make player the focus of the scene
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    //add player to the scene
    scene->addItem(player);

    //create score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    //spawn the enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(spawn_rate);

    //change spawn rate
    if(score->getScore() >= 5){
        spawn_rate = 500;
        qDebug() << "spawn rate is: " + spawn_rate;
        timer->start(spawn_rate);
    }

    //play bg music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bgmusic.mp3"));
    music->play();

    show();
}
//    // create an item to put into the scene
//    Player * player = new Player();
//    player->setRect(0,0,100,100);

//    // add item to the scene
//    scene->addItem(player);

//    // make player focusable
//    player->setFlag(QGraphicsItem::ItemIsFocusable);
//    player->setFocus();

//    // add a view
//    QGraphicsView * view = new QGraphicsView(scene);
//    view -> setScene(scene);

//    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//    view->show();

//    view->setFixedSize(800,600);    //sets the QGraphicsView (game window) to a set size

//    player->setPos(view->width()/2,view->height()-player->rect().height()); //Set the x,y position of the player

//    //spawn enemies
//    QTimer * timer = new QTimer();
//    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
//    timer->start(1750);
//}
