#include "buildgreentowericon.h"
#include "browntower.h"
#include "game.h"
#include "greentower.h"

extern Game * game;

BuildGreenTowerIcon::BuildGreenTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/greentower.png"));
}

void BuildGreenTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->building){
        game->building = new GreenTower();
        game->setCursor(QString(":/images/greentower.png"));
    }
}
