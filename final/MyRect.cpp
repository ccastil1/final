#include "MyRect.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"

void MyRect::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "MyRect knows that you pressed a key";
    if(event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }

    else if(event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }

    else if(event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }

    else if(event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
    }

    else if(event->key() == Qt::Key_Space){
        //create bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        //qDebug() <<"bullet created";
        scene()->addItem(bullet);
    }

}
