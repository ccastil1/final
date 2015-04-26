#ifndef GAME
#define GAME
#include <QGraphicsView>
#include <QMouseEvent>
#include "tower.h"

class Game: public QGraphicsView{
public:
    //member functions
    Game();
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    //member attributes
    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    Tower * build;
};

#endif // GAME

