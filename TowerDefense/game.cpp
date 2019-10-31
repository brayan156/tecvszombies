#include "game.h"
#include <QGraphicsScene>
#include "browntower.h"
#include "bullet.h"
#include "enemy.h"
#include "buildbrowntowericon.h"
#include "buildgreentowericon.h"
#include "buildredtowericon.h"
#include "buildyellowtowericon.h"
#include <QTimer>
#include <QGraphicsLineItem>
#include <QPen>
#include <QGraphicsLineItem>
#include <QDebug>

Game::Game(): QGraphicsView(){
    // create a scene
    srand(time(NULL));
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    QBrush brush(QColor("grey"));
    scene->setBackgroundBrush(brush);

    // set the scene
    setScene(scene);

    // set curosr

    cursor = nullptr;
    building = nullptr;
    setMouseTracking(true);

    // alter window

    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create enemy

    spawnTimer = new QTimer(this);
    enemiesSpawned = 0;
    maxNumberOfEnemies = 0;
    pointsToFollow << QPointF(800,0) << QPointF(450,450) << QPointF(0,600);
    this->crear_poblacion();
    createEnemies(40);

    // create road
    creatRoad();

    // test code
    BuildBrownTowerIcon * bt = new BuildBrownTowerIcon();
    BuildGreenTowerIcon * gt = new BuildGreenTowerIcon();
    BuildRedTowerIcon * rt = new BuildRedTowerIcon();
    BuildYellowTowerIcon * yt = new BuildYellowTowerIcon();

    gt->setPos(x(),y()+50);
    rt->setPos(x(),y()+100);
    yt->setPos(x(),y()+150);

    scene->addItem(bt);
    scene->addItem(gt);
    scene->addItem(rt);
    scene->addItem(yt);


}

void Game::setCursor(QString filename){
    // if there is already a cursor, remove it first
    if (cursor){
        scene->removeItem(cursor);
        delete cursor;
    }

    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event){
    if (cursor){
        cursor->setPos(event->pos());
    }
}

void Game::mousePressEvent(QMouseEvent *event){
    // if we are building
    if (building){
        // return if the cursor is colliding with a tower
        QList<QGraphicsItem *> items = cursor->collidingItems();
        for (size_t i = 0, n = items.size(); i < n; i++){
            if (dynamic_cast<Tower*>(items[i])){
                return;
            }
        }

        // otherwise, build at the clicked location
        scene->addItem(building);
        building->setPos(event->pos());
        this->agregar_torre_matriz(event->x(),event->y());
        cursor = nullptr;
        building = nullptr;
    }
    else {
        QGraphicsView::mousePressEvent(event);
    }

}

void Game::createEnemies(int numberOfEnemies){

    enemiesSpawned = 0;
    maxNumberOfEnemies = numberOfEnemies;
    connect(spawnTimer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    spawnTimer->start(1000);

}

void Game::creatRoad(){
    for (size_t i = 0, n = pointsToFollow.size()-1; i < n; i++){
        // create a line connecting the two points
        QLineF line(pointsToFollow[i],pointsToFollow[i+1]);
        QGraphicsLineItem * lineItem = new QGraphicsLineItem(line);

        QPen pen;
        pen.setWidth(15);
        pen.setColor(Qt::darkGray);

        lineItem->setPen(pen);
        scene->addItem(lineItem);

    }
}

void Game::crear_poblacion()
{
    int i=0;
    while (i<=10){
        Zombie zombie;
        zombie.crear_Orco();
        this->zombies->append(zombie);
        i++;
    }
    i=0;
    while (i<=10){
        Zombie zombie;
        zombie.crear_Elfo();
        this->zombies->append(zombie);
        i++;
    }
    i=0;
    while (i<=10){
        Zombie zombie;
        zombie.crear_Harpia();
        this->zombies->append(zombie);
        i++;
    }
    i=0;
    while (i<=10){
        Zombie zombie;
        zombie.crear_Mercenario();
        this->zombies->append(zombie);
        i++;
    }

}

void Game::agregar_torre_matriz(int px, int py)
{
    int i=0;
    while (i<=50){
        this->matriz[py][px+i]=1;
        i++;
    }
    while (i<=50){
        this->matriz[py+i][px]=1;
        i++;
    }
}

void Game::spawnEnemy(){
    // spawn an enemy
    Enemy * enemy = new Enemy(pointsToFollow);
    enemy->zombie=this->zombies->at(this->contador_union_zombie_enemigo);
    this->contador_union_zombie_enemigo++;
    enemy->setPos(pointsToFollow[0]);
    scene->addItem(enemy);
    this->enemigos->append(enemy);
    enemiesSpawned += 1;

    if (enemiesSpawned >= maxNumberOfEnemies){
        spawnTimer->disconnect();
    }
}
