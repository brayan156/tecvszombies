#ifndef REDTOWER_H
#define REDTOWER_H

#include "tower.h"
#include "bullet.h"

class RedTower: public Tower{
    Q_OBJECT
public:
    RedTower(QGraphicsItem * parent=0);
    void fire();
    Bullet * bullet;
public slots:
    void aquire_target();
    void check_colision();
    //QGraphicsPolygonItem * attack_area;
};

#endif // REDTOWER_H
