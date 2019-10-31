#ifndef YELLOWTOWER_H
#define YELLOWTOWER_H

#include "tower.h"

class YellowTower: public Tower{
    Q_OBJECT
public:
    YellowTower(QGraphicsItem * parent=0);
    void fire();
public slots:
    void aquire_target();
};


#endif // YELLOWTOWER_H
