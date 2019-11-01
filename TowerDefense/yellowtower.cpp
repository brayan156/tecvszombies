#include "yellowtower.h"
#include <QTimer>
#include "bullet.h"
#include "game.h"

extern Game * game;

YellowTower::YellowTower(QGraphicsItem *parent){
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
               << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);


    // scale points
    int SCALE_FACTOR = 125;

    for (size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE_FACTOR;
    }


    // create the QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);
    attack_area->setPen(QPen(Qt::DotLine));

    // move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);;
    QPointF tower_center(x()+25,y()+25);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    // connect a timer to aquire_target

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(2000);
    
    damage = 7.0;

}

void YellowTower::fire(){


    bullet = new Bullet();
    bullet->setPixmap(QPixmap(":/images/yelowtowerbullet.png"));
    bullet->setPos(x()+25,y()+25);


    QLineF ln(QPointF(x()+25,y()+25),attack_dest);
    int angle = (-1 * ln.angle())+13;

    bullet->setRotation(angle);
    game->scene->addItem(bullet);



    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(check_colision()));
    timer->start(150);


}

void YellowTower::aquire_target(){

    Tower::aquire_target();
}

void YellowTower::check_colision()
{

    for (int i = 0;i<game->enemigos->size();++i) {
        int posx_enemy = game->enemigos->at(i)->x();
        int posx_bullet = bullet->x();
        int posy_enemy = game->enemigos->at(i)->y();
        int posy_bullet = bullet->y();

        if(posx_enemy+60 > posx_bullet  && posx_bullet > posx_enemy-60){

            if(posy_enemy+60 > posy_bullet && posy_bullet > posy_enemy-60){

                qDebug() << "Crash" << endl;
                game->enemigos->at(i)->hide();

            }

        }


    }

}




