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
    
    damage = 10;

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

    bullet1->setPos(x()+25,y()+25);
    bullet2->setPos(x()+25,y()+25);
    bullet3->setPos(x()+25,y()+25);

    QLineF ln(QPointF(x(),y()),attack_dest);
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

            if((posy_enemy+20 > posy_bullet1 && posy_bullet1 > posy_enemy-20)){


                int ataque=(this->damage)-game->enemigos->at(i)->zombie.stats[4];
                if (ataque<1){ataque=1;}
                if (bullet2->golpea_a_enemigo==0){
                    game->enemigos->at(i)->zombie.stats[2] -= ataque;
                    bullet2->golpea_a_enemigo=1;
                }



            } else if ((posy_enemy+20 > posy_bullet2  && posy_bullet2 > posy_enemy-20)){


                int ataque=(this->damage)-game->enemigos->at(i)->zombie.stats[4];
                if (ataque<1){ataque=1;}
                if (bullet2->golpea_a_enemigo==0){
                    game->enemigos->at(i)->zombie.stats[2] -= ataque;
                    bullet2->golpea_a_enemigo=1;
                }


            } else if ((posy_enemy+20 > posy_bullet3  && posy_bullet3 > posy_enemy-20)){


                int ataque=(this->damage)-game->enemigos->at(i)->zombie.stats[4];
                if (ataque<1){ataque=1;}
                if (bullet3->golpea_a_enemigo==0){
                    game->enemigos->at(i)->zombie.stats[2] -= ataque;
                    bullet3->golpea_a_enemigo=1;
                }



            }
            if(game->enemigos->at(i)->zombie.stats[2] <= 0){
                game->enemigos->at(i)->hide();
                game->enemigos->at(i)->zombie.stats[2]=game->enemigos->at(i)->zombie.vida_incial;
                game->enemigos_eliminados->append(game->enemigos->at(i)->zombie);
                game->enemigos->removeAt(i);
                if (game->enemigos->length()==0 && game->enemiesSpawned==game->maxNumberOfEnemies){
                    game->contador_union_zombie_enemigo=0;
                    game->pasar_generacion();
                }

            }

        }


    }

}

