#ifndef GREENTOWER_H
#define GREENTOWER_H

#include "tower.h"
#include "bullet.h"

class GreenTower: public Tower{
    Q_OBJECT
public:
    GreenTower(QGraphicsItem * parent=0);
    void fire();
    Bullet * bullet1;
    Bullet * bullet2;
    Bullet * bullet3;

public slots:
    void aquire_target();
    void check_colision();
};


#endif // GREENTOWER_H
