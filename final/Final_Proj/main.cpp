/*
#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
#include <QTimer>
*/
/*
Prereqs:
-basic understanding of c++
-VERY basic knowledge of Qt
Tutorial Topics (1):
-QGraphicsScene (container for game objects)
-QGrapicsItem   (derived abstract class, QGraphicsRectItem)
-QGraphicsView  (Used to visualize scene, used to print scene)

Tutorial Topics (2):
-events (keyPressEvent() and QKeyEvent)
-event propogation system
-QDebug

Tutorial Topics (3):
-QTimer
-signals and slots (connect function)
-QObject and Q_OBJECT macro
*/ /*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene
    MyRect * player = new MyRect();
    player->setRect(0,0,100,100);

    // add item to the scene
    scene->addItem(player);

    // make player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add a view
    QGraphicsView * view = new QGraphicsView(scene);
//    view -> setScene(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    view->setFixedSize(800,600);    //sets the QGraphicsView (game window) to a set size
    scene->setSceneRect(0,0,800,600);   //set the QGraphicsScene to a specified size

    player->setPos(view->width()/2,view->height()-player->rect().height()); //Set the x,y position of the player

    //spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1750);

    return a.exec();
}
*/


#include <QApplication>
#include "Game.h"

Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}

