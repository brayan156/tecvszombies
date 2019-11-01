#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "enemy.h"

class Tower:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(QGraphicsItem * parent=0);
    double distanceTo(QGraphicsItem * item);
    virtual void fire();
    QGraphicsPolygonItem * attack_area;
    Enemy * enemy;
    void setSCALE_FACTOR(int value);
    float damage;
    int cost;

public slots:
    void aquire_target();

protected:
    QPointF attack_dest;
    bool has_target;
};

#endif // TOWER_H
