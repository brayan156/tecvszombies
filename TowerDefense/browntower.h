#ifndef BROWNTOWER_H
#define BROWNTOWER_H

#include "tower.h"
#include "bullet.h"

class BrownTower: public Tower{
    Q_OBJECT
public:
    BrownTower(QGraphicsItem * parent=0);
    void fire();
    Bullet * bullet;

public slots:
    void aquire_target();
    void check_colision();

};

#endif // BROWNTOWER_H
