#include "Enemy_Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <typeinfo>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>

extern Game * game; //allows use of the external global object
Enemy_Bullet::Enemy_Bullet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{
    //draw the graphic
    setPixmap(QPixmap(":/images/greenLaserRay.png"));

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy_Bullet::move()
{
    //check collision w/ enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            //decrease health
            game->health->decrease();

            //remove items
            scene()->removeItem(this);

            //delete items
            delete this;
            return;
        }
    }

    // move the Enemy_Bullet up
    setPos(x(),y()+25);
    // delete the Enemy_Bullet when it moves off screen
    if(pos().y() > 850){
//      qDebug() << "Enemy_Bullet deleted";
        scene()->removeItem(this);
        delete this;
    }
}
