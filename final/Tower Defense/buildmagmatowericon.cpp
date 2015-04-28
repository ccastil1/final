#include "buildmagmatowericon.h"
#include "magmatower.h"
#include "game.h"

extern Game * game;

BuildMagmaTowerIcon::BuildMagmaTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/magma_build.png"));
}

void BuildMagmaTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->build){
        game->build = new MagmaTower();
        game->setCursor(":/images/magma_tower.png");
    }
}

