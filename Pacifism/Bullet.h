#ifndef BULLET
#define BULLET
#include <QGraphicsRectItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Bullet();
    ~Bullet();
public slots:
    void move();
private:

};

#endif // BULLET

