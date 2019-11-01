#ifndef YELLOWTOWER_H
#define YELLOWTOWER_H

#include "tower.h"
#include "bullet.h"

class YellowTower: public Tower{
    Q_OBJECT
public:
    YellowTower(QGraphicsItem * parent=0);
    void fire();
    Bullet * bullet;


public slots:
    void aquire_target();
    void check_colision();

};


#endif // YELLOWTOWER_H
