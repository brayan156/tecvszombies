#ifndef GREENTOWER_H
#define GREENTOWER_H

#include "tower.h"

class GreenTower: public Tower{
    Q_OBJECT
public:
    GreenTower(QGraphicsItem * parent=0);
    void fire();
public slots:
    void aquire_target();
};


#endif // GREENTOWER_H
