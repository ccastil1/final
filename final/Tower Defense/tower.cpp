#include "tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include "bullet.h"
#include <QLineF>
#include "game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <enemy.h>

extern Game * game;

#define SCALE_FACTOR 65

Tower::Tower(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    // set the graphics
    setPixmap(QPixmap(":/images/archer_tower.png"));

    // create points vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2)
           << QPoint(2,3) << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);
    //scale points
    for (size_t i =0, n=points.size();i<n; i++){
        points[i] *= SCALE_FACTOR;
    }

    // create polygon for attack radius
    QPolygonF polygon(points);

    // create QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(polygon,this);
    attack_area->setPen(QPen(Qt::DotLine));

    //move polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);
    QPointF tower_center(x()+35,y()+54);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    // connect timer to attack_target()
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);

    //set attack_dest
    attack_dest = QPointF(800,0);
}

double Tower::distanceTo(QGraphicsItem *item)
{
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void Tower::fire()
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

void Tower::aquire_target()
{
    //get list of all items colliding w/ attack area
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();

    has_target = false;

    double closest_dist = 300;
    QPointF closest_pt = QPointF(0,0);
    for (size_t i = 0, n = colliding_items.size(); i <n; ++i){
        Enemy * enemy = dynamic_cast<Enemy *>(colliding_items[i]);
        if(enemy){
            double this_dist = distanceTo(colliding_items[i]);
            if (this_dist < closest_dist){
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
    }
    if(has_target){
        attack_dest = closest_pt;
        fire();
    }
}
