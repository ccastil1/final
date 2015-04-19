#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include "Enemy.h"
#include "Player.h"

Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
//    view = new QGraphicsView();
    scene->setSceneRect(0,0,800,600);   //set the QGraphicsScene to a specified size
    setBackgroundBrush(QBrush(QImage(":/images/star-background.png"))); //change filename to change background

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
    timer->start(1750);

    //play bg music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bgmusic.mp3"));
    music->play();

    show();
}
