#include "game.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QBrush>
#include <QImage>
#include "archertower.h"
#include "bullet.h"
#include "enemy.h"
#include "button.h"
#include "buildarchertowericon.h"
#include "buildarcanetowericon.h"
#include "buildmagmatowericon.h"
#include <QGraphicsLineItem>


Game::Game(): QGraphicsView()
{
    //create scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/grass.gif")));

    //set scene
    setScene(scene);

    //set cursor
    cursor = NULL;
    build = NULL;
    setMouseTracking(true);

    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    spawnTimer = new QTimer(this);
    enemiesSpawned = 0;
    maxNumOfEnemies = 0;
    ptsToFollow << QPointF(800,50) << QPointF(325,50) << QPointF(325,175) << QPointF(700,175) << QPointF(700,425)
                << QPointF(135,425) << QPointF(135,640);

    //test code
    BuildArcherTowerIcon * at = new BuildArcherTowerIcon();
    BuildArcaneTowerIcon * ar = new BuildArcaneTowerIcon();
    BuildMagmaTowerIcon * mt = new BuildMagmaTowerIcon();
    ar->setPos(x(),y()+50);
    mt->setPos(x(),y()+100);
//    scene->addItem(at);
//    scene->addItem(ar);
//    scene->addItem(mt);
}

void Game::setCursor(QString filename)
{
    if (cursor){
        scene->removeItem(cursor);
        delete cursor;
    }

    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if(cursor){
        cursor->setPos(event->pos());
    }
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if(build){
        //check if there is any overlap w/ existing tower
        QList<QGraphicsItem *> items = cursor->collidingItems();
        for (size_t i = 0, n = items.size(); i < n; i++){
           if (dynamic_cast<Tower*>(items[i])){
                return;
            }
        }
        //if no overlap, build tower
        scene->addItem(build);
        build->setPos(event->pos());
        cursor = NULL;
        build = NULL;
    }
    else{
        QGraphicsView::mousePressEvent(event);
    }
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Q){
        exit(1);
    }

    else if(event->key() == Qt::Key_R){
        spawnTimer->disconnect();
        scene->clear();
        displayMainMenu();
    }
}

void Game::createEnemies(int numberOfEnemies)
{
    enemiesSpawned = 0;
    maxNumOfEnemies = numberOfEnemies;
    connect(spawnTimer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    spawnTimer->start(1000);
}

void Game::createRoad()
{
    for(size_t i = 0, n = ptsToFollow.size()-1; i < n; i++){
        //create non-physical line
        QLineF line(ptsToFollow[i],ptsToFollow[i+1]);
        QGraphicsLineItem * lineItem = new QGraphicsLineItem(line);

        QPen pen;
        pen.setWidth(25);
        pen.setColor(Qt::darkGray);
        lineItem->setPen(pen);
        scene->addItem(lineItem);
    }
}

void Game::displayMainMenu()
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Tower Defense"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    QGraphicsTextItem* instrText = new QGraphicsTextItem(QString("To play, click the build icon of the tower you would like to build\n"
                                                                 "then click where you would like to place it.\nQ = quit, R = reset"));
    QFont instrFont("comic sans",12);
    instrText->setFont(instrFont);
    int ixPos = this->width()/2 - instrText->boundingRect().width()/2;
    int iyPos = 250;
    instrText->setPos(ixPos,iyPos);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);
    scene->addItem(instrText);

    //play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 325;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    //quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 400;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

}

void Game::spawnEnemy()
{
    //spawn single enemy
    Enemy * enemy = new Enemy(ptsToFollow);
    enemy->setPos(ptsToFollow[0]);
    scene->addItem(enemy);
    enemiesSpawned +=1;

    if(enemiesSpawned >= maxNumOfEnemies){
        spawnTimer->disconnect();
    }
}

void Game::start()
{
    scene->clear(); //clear screen

    createEnemies(10);   //create n number of enemies
    createRoad();   //draw road

    //instantiate building icons
    BuildArcherTowerIcon * at = new BuildArcherTowerIcon();
    BuildArcaneTowerIcon * ar = new BuildArcaneTowerIcon();
    BuildMagmaTowerIcon * mt = new BuildMagmaTowerIcon();
    ar->setPos(0,y());
    mt->setPos(0,y()+50);
    scene->addItem(at);
    scene->addItem(ar);
    scene->addItem(mt);
}

