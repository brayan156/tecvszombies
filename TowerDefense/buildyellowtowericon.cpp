#include "buildyellowtowericon.h"
#include "browntower.h"
#include "game.h"
#include "yellowtower.h"

extern Game * game;

BuildYellowTowerIcon::BuildYellowTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/yellowtower.png"));
}

void BuildYellowTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->building){
        game->building = new YellowTower();
        game->setCursor(QString(":/images/yellowtower.png"));
    }
}

