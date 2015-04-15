#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
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
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene
    MyRect * rect = new MyRect();
    rect->setRect(0,0,100,100);

    // add item to the scene
    scene->addItem(rect);

    // make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // add a view
    QGraphicsView * view = new QGraphicsView(scene);
//    view -> setScene(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    return a.exec();
}
