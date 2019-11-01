#ifndef ENEMY_H
#define ENEMY_H

#include "zombie.h"

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QList<QPointF> pointsToFollow, QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);
    Zombie zombie;


public slots:
    void moveForward();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
};

#endif // ENEMY_H
