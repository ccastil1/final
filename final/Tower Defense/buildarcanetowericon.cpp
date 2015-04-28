#include "buildarcanetowericon.h"
#include "arcanetower.h"
#include "game.h"

extern Game * game;

BuildArcaneTowerIcon::BuildArcaneTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/arcane_build.png"));
}

void BuildArcaneTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->build){
        game->build = new ArcaneTower();
        game->setCursor(":/images/arcane_tower.png");
    }
}

