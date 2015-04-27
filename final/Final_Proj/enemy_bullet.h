#ifndef ENEMY_BULLET_H
#define ENEMY_BULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy_Bullet : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy_Bullet(QGraphicsItem *);
    ~Enemy_Bullet();
public slots:
    void move();
};

#endif // ENEMY_BULLET_H
