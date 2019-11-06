#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "backtracking.h"
#include "enemy.h"
#include "genetico.h"
#include "par.h"
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
    void crearCuadricula();
    void empezar_primer_ganador();
    void empezar_generacion(int n);
    void crearMatrizBack();
    void updateMatrizBack(int puntox, int puntoy);
    void pasar_generacion();
    QList<int> *crearuta(int px,int py);


    // member attributes
    QString link="http://192.168.100.24:9080/web_war_exploded/zombies/zomb";
    QList<Par> *lista_temporal_Astar=new QList<Par>;
    int tiempo_spawn=3000;
    int MatrizBack[10][10];
    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    QVector < QVector <int>> cuadricula;
    Tower * building;
    QTimer * spawnTimer;
    int enemiesSpawned;
    int maxNumberOfEnemies;
    int numero_enemigos;
    int distanciax;
    int distanciay;
    int llamado=0;
    QList<QPointF> pointsToFollow;
    QList <Enemy*> *enemigos=new QList<Enemy*>;
    QList <Zombie> *zombies=new QList<Zombie>;
    QList <Zombie> *enemigos_eliminados=new QList<Zombie>;
    QList <Zombie> *enemigos_pasados=new QList<Zombie>;
    int contador_union_zombie_enemigo=0;
    QPointF checkpos(QPoint posicion);
    Genetico cruzador;
    int cantidad_oleadas;
    QString modo="";
    BackTracking track;
    int A_temporizador=0;

    QList<Enemy *> *getEnemigos() const;

public slots:
    void spawnEnemy();
};

#endif // GAME_H
