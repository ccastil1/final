#include "buildarchertowericon.h"
#include "archertower.h"
#include "game.h"

extern Game * game;

BuildArcherTowerIcon::BuildArcherTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/archer_build.png"));
}

void BuildArcherTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->build){
        game->build = new ArcherTower();
        game->setCursor(":/images/archer_tower.png");
    }
}
