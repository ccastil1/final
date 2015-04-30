#include "enemy.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>

#define STEP_SIZE 5

Enemy::Enemy(QList<QPointF> ptsToFollow,QGraphicsItem *parent)
{
    //set graphics
    setPixmap(QPixmap(":/images/semrich.png"));
    setOffset(-20,-18);

    //set points
    points = ptsToFollow;
    point_index = 0;
    dest = points[0];
    rotateToPoint(dest);

    //connect timer to move_forward()
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(50);

}

void Enemy::rotateToPoint(QPointF p)
{
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
}

void Enemy::move_forward()
{
    //if close to dest, rotate to next dest
    QLineF ln(pos(),dest);
    if (ln.length() < 5){
        point_index++;
        if (point_index >= points.size()){
            return;
        }
        dest = points[point_index];
        rotateToPoint(dest);
    }

    //move enemy forward at angle theta
    double theta = rotation(); //degrees
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));

    setPos(x()+dx,y()+dy);
}
