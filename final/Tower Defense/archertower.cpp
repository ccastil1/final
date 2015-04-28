#include "archertower.h"
#include <QTimer>
#include "bullet.h"
#include "game.h"

extern Game * game;

ArcherTower::ArcherTower(QGraphicsItem *parent)
{
    // connect timer to attack_target()
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);
}

void ArcherTower::fire()
{
    //create bullet
    Bullet * bullet = new Bullet();
    bullet->setPos(x()+35,y()+54);
    //rotate bullet depending on angle
    QLineF ln(QPointF(x()+35,y()+54),attack_dest);
    double angle = -1*ln.angle();
    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void ArcherTower::aquire_target()
{
    Tower::aquire_target();
}
