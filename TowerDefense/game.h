#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "enemy.h"
#include "tower.h"
#include<QtGui>


class Game: public QGraphicsView{
    Q_OBJECT
public:
    // member functions

    Game();
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void createEnemies(int numberOfEnemies);
    void creatRoad();
    void crear_poblacion();
    void agregar_torre_matriz(int px, int py);

    // member attributes
    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    Tower * building;
    QTimer * spawnTimer;
    int enemiesSpawned;
    int maxNumberOfEnemies;
    QList<QPointF> pointsToFollow;
    int matriz[800][600];
    QList <Enemy*> *enemigos=new QList<Enemy*>;
    QList <Zombie> *zombies=new QList<Zombie>;
    int contador_union_zombie_enemigo=0;
public slots:
    void spawnEnemy();
};

#endif // GAME_H
