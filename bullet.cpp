#include "bullet.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h> //qSin, qCos, qTan
#include "game.h"

extern Game * game;

#define STEP_SIZE 30

Bullet::Bullet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{
    // set graphics
    setPixmap(QPixmap(":images/arrow.png"));

    // connect a timer to move()
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);

}

void Bullet::move()
{
    double theta = rotation(); //degrees
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));

    setPos(x()+dx,y()+dy);
}
