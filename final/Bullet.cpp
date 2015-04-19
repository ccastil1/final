#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <typeinfo>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>

extern Game * game; //allows use of the external global object
Bullet::Bullet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{
    //draw the graphic
    setPixmap(QPixmap(":/images/greenLaserRay.png"));   //change directory to choose different image

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    //check collision w/ enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            //increase score
            game->score->increase();

            //remove items
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete items
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // move the bullet up
    setPos(x(),y()-10);
    // delete the bullet when it moves off screen
    if(pos().y() < -50){
//        qDebug() << "bullet deleted";
        scene()->removeItem(this);
        delete this;
    }
}
