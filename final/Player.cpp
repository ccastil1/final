#include "Player.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/Laser.wav"));   //can replace with a different sound file.

    // Set graphic
    setPixmap(QPixmap(":/images/Player_plane.png"));    //change to valid filepath
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "Player knows that you pressed a key";
    if(event->key() == Qt::Key_Left){
        if (pos().x() > 0){
            setPos(x()-20,y());
        }
    }

    else if(event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800){
            setPos(x()+20,y());
        }
    }
/* Following two flow control statements commented out to
   only allow the player to move left and right
*/
//    else if(event->key() == Qt::Key_Up){
//        setPos(x(),y()-10);
//    }

//    else if(event->key() == Qt::Key_Down){
//        setPos(x(),y()+10);
//    }

    else if(event->key() == Qt::Key_Space){
        //create bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+45 ,y());
        //qDebug() <<"bullet created";
        scene()->addItem(bullet);
        //play bulletsound
        if (bulletsound->state()==QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
    }

}

void Player::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
