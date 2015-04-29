#ifndef GAME
#define GAME
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "tower.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    //member functions
    Game();
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent * event);
    void createEnemies(int numberOfEnemies);
    void createRoad();
    void displayMainMenu();

    //member attributes
    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    Tower * build;
    QTimer * spawnTimer;
    int enemiesSpawned;
    int maxNumOfEnemies;
    QList<QPointF> ptsToFollow;
public slots:
    void spawnEnemy();
    void start();
};

#endif // GAME

