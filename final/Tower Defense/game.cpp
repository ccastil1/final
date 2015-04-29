#include "game.h"
#include <QGraphicsScene>
#include <QTimer>
#include "archertower.h"
#include "bullet.h"
#include "enemy.h"
#include "button.h"
#include "bigenemy.h"
#include "buildarchertowericon.h"
#include "buildarcanetowericon.h"
#include "buildmagmatowericon.h"
#include <QGraphicsLineItem>


Game::Game(): QGraphicsView()
{
    //create scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);


    //set scene
    setScene(scene);

    //set cursor
    cursor = NULL;
    build = NULL;
    setMouseTracking(true);

    //create a tower
    //Tower * t = new Tower();
    //t->setPos(250,250);

    //add tower to scene
    //scene->addItem(t);



    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    spawnTimer = new QTimer(this);
    enemiesSpawned = 0;
    maxNumOfEnemies = 0;
    ptsToFollow << QPointF(800,0) << QPointF(325,15) << QPointF(325,175) << QPointF(700,175) << QPointF(700,425)
                << QPointF(135,425) << QPointF(135,600);

//    createEnemies(5);

    //create road
//    createRoad();

//    //create enemy
//    Enemy * enemy = new Enemy();
//    //enemy->setPos(x(),y()+300);
//    scene->addItem(enemy);



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
        start();
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
        pen.setWidth(15);
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
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    //play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    //quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
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
    scene->clear();

    createEnemies(5);
    createRoad();

    BuildArcherTowerIcon * at = new BuildArcherTowerIcon();
    BuildArcaneTowerIcon * ar = new BuildArcaneTowerIcon();
    BuildMagmaTowerIcon * mt = new BuildMagmaTowerIcon();
    ar->setPos(x(),y()+50);
    mt->setPos(x(),y()+100);
    scene->addItem(at);
    scene->addItem(ar);
    scene->addItem(mt);
}

