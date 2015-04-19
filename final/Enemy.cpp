#include "Enemy.h"
#include "Game.h"
#include "Health.h"
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
}

void Enemy::move()
{
    // move the Enemy down
    setPos(x(),y()+10);
    // delete the Enemy when it moves off screen
    if(pos().y() > 700){
        //decrease health
        game->health->decrease();
        //qDebug() << "Enemy deleted";
        scene()->removeItem(this);
        delete this;
    }
}

