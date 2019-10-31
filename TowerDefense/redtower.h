#ifndef REDTOWER_H
#define REDTOWER_H

#include "tower.h"

class RedTower: public Tower{
    Q_OBJECT
public:
    RedTower(QGraphicsItem * parent=0);
    void fire();
public slots:
    void aquire_target();
    //QGraphicsPolygonItem * attack_area;
};

#endif // REDTOWER_H
