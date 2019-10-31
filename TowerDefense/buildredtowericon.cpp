#include "buildredtowericon.h"
#include "browntower.h"
#include "game.h"
#include "redtower.h"

extern Game * game;

BuildRedTowerIcon::BuildRedTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/redtower.png"));
}

void BuildRedTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->building){
        game->building = new RedTower();
        game->setCursor(QString(":/images/redtower.png"));
    }
}

