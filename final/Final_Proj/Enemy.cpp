#include "Enemy.h"
#include "Game.h"
#include "Health.h"
@#include "Enemy_Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

extern Game * game;
Enemy::Enemy(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    //set rand pos
    int random_number = rand() %700;
    setPos(random_number,0);

    //draw the enemy
    setPixmap(QPixmap(":/images/Enemy_plane.png"));

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

    // connect shooting
    QTimer * shotClock = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(shoot()))
}

void Enemy::shoot()
{
    Enemy_Bullet * enemybullet = new Bullet();
    enemybullet->setPos(x()+45 ,y());
    //qDebug() <<"bullet created";
    scene()->addItem(enemybullet);
    //play bulletsound
    if (bulletsound->state()==QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
}

void Enemy::move()
{
    // move the Enemy down
    setPos(x(),y()+10);
    // delete the Enemy when it moves off screen
    if(pos().y() > 600){
        //decrease health
        game->health->decrease();
        //qDebug() << "Enemy deleted";
        scene()->removeItem(this);
        delete this;
    }
}
