#include "mainwindow.h"
#include <QApplication>
#include "hero.h"
#include "Bullet.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QGraphicsScene * scene = new QGraphicsScene();

    hero player = new hero;

    scene->additem(player);


    return a.exec();
}
