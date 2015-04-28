#include "arcanetower.h"
#include <QTimer>
#include "bullet.h"
#include "game.h"

extern Game * game;

ArcaneTower::ArcaneTower(QGraphicsItem *parent)
{
    // connect timer to attack_target()
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);
}

void ArcaneTower::fire()
{
    //create bullets
    Bullet * bullet1 = new Bullet();
    Bullet * bullet2 = new Bullet();
    Bullet * bullet3 = new Bullet();

    //set bullet graphics
    bullet1->setPixmap(QPixmap(":/images/arcane.png"));
    bullet2->setPixmap(QPixmap(":/images/arcane.png"));
    bullet3->setPixmap(QPixmap(":/images/arcane.png"));

    bullet1->setPos(x()+35,y()+54);
    bullet2->setPos(x()+35,y()+54);
    bullet3->setPos(x()+35,y()+54);

    //rotate bullet depending on angle
    QLineF ln(QPointF(x()+35,y()+54),attack_dest);
    double angle = -1*ln.angle();

    bullet1->setRotation(angle);
    bullet2->setRotation(angle+10);
    bullet3->setRotation(angle-10);

    game->scene->addItem(bullet1);
    game->scene->addItem(bullet2);
    game->scene->addItem(bullet3);
}

void ArcaneTower::aquire_target()
{
    Tower::aquire_target();
}
