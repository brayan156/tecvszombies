#include "greentower.h"
#include <QTimer>
#include "game.h"

extern Game * game;

GreenTower::GreenTower(QGraphicsItem *parent){

    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
               << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);


    // scale points
    int SCALE_FACTOR = 75;

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
    timer->start(1000);
    
    damage = 8/3;

}

void GreenTower::fire(){
    // create the bullets
    bullet1 = new Bullet();
    bullet2 = new Bullet();
    bullet3 = new Bullet();

    // set the graphics
    bullet1->setPixmap(QPixmap(":/images/greentowerbullet.png"));
    bullet2->setPixmap(QPixmap(":/images/greentowerbullet.png"));
    bullet3->setPixmap(QPixmap(":/images/greentowerbullet.png"));

    bullet1->setPos(x()+44,y()+44);
    bullet2->setPos(x()+44,y()+44);
    bullet3->setPos(x()+44,y()+44);

    QLineF ln(QPointF(x()+44,y()+44),attack_dest);
    int angle = -1 * ln.angle();

    bullet1->setRotation(angle);
    bullet2->setRotation(angle+5);
    bullet3->setRotation(angle-5);

    game->scene->addItem(bullet1);
    game->scene->addItem(bullet2);
    game->scene->addItem(bullet3);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(check_colision()));
    timer->start(200);

}

void GreenTower::aquire_target(){
    Tower::aquire_target();
}

void GreenTower::check_colision()
{

    for (int i = 0;i<game->enemigos->size();++i) {
        int posx_enemy = game->enemigos->at(i)->x();
        int posy_enemy = game->enemigos->at(i)->y();

        int posx_bullet1 = bullet1->x();
        int posy_bullet1 = bullet1->y();

        int posx_bullet2 = bullet2->x();
        int posy_bullet2 = bullet2->y();

        int posx_bullet3 = bullet3->x();
        int posy_bullet3 = bullet3->y();

        if((posx_enemy+20 > posx_bullet1  && posx_bullet1 > posx_enemy-20) || (posx_enemy+20 > posx_bullet2  && posx_bullet2 > posx_enemy-20) ||
                (posx_enemy+20 > posx_bullet3  && posx_bullet3 > posx_enemy-20)){

            if((posy_enemy+20 > posy_bullet1 && posy_bullet1 > posy_enemy-20) || (posy_enemy+20 > posy_bullet2  && posy_bullet2 > posy_enemy-20) ||
                    (posy_enemy+20 > posy_bullet3  && posy_bullet3 > posy_enemy-20)){

                qDebug() << "Crash" << endl;
                game->enemigos->at(i)->hide();

            }

        }


    }

}

