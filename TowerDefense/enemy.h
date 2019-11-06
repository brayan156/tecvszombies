#ifndef ENEMY_H
#define ENEMY_H

#include "par.h"
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
    QList <int> *ruta=new QList <int>;
    int  coordenada[2]={0,9};
    int pasos=0;
    int mov_actual=0;
    int cambio_ruta=0;
    QList<Par> *lista_Astar=new QList<Par>;
    Par siguiente_punto;
    void poner_a_caminar();



public slots:
    void moveForward();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
};

#endif // ENEMY_H
