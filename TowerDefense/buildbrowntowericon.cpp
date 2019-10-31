#include "buildbrowntowericon.h"
#include "game.h"
#include "browntower.h"

extern Game * game;

BuildBrownTowerIcon::BuildBrownTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/browntower.png"));
}

void BuildBrownTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->building){
        game->building = new BrownTower();
        game->setCursor(QString(":/images/browntower.png"));
    }
}
