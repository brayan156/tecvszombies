#include "browntower.h"
#include <QTimer>
#include "game.h"

extern Game * game;

BrownTower::BrownTower(QGraphicsItem *parent){

    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
               << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);


    // scale points
    int SCALE_FACTOR = 100;

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
    timer->start(1500);


    this->damage = 10;


}

void BrownTower::fire(){

    bullet = new Bullet();
    bullet->setPixmap(QPixmap(":/images/browntowerbullet.png"));
    bullet->setPos(x()+25,y()+25);

    QLineF ln(QPointF(x(),y()),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(check_colision()));
    timer->start(100);


}

void BrownTower::aquire_target(){
    Tower::aquire_target();
}

void BrownTower::check_colision()
{

    for (int i = 0;i<game->enemigos->size();++i) {
        int posx_enemy = game->enemigos->at(i)->x();
        int posx_bullet = bullet->x();
        int posy_enemy = game->enemigos->at(i)->y();
        int posy_bullet = bullet->y();

        if(posx_enemy+25 > posx_bullet  && posx_bullet > posx_enemy-25){

            if(posy_enemy+20 > posy_bullet && posy_bullet > posy_enemy-20){
                int ataque=(this->damage)-game->enemigos->at(i)->zombie.stats[5];
                if (ataque<1){ataque=1;}
                if (bullet->golpea_a_enemigo==0){
                    game->enemigos->at(i)->zombie.stats[2] -= ataque;
                    bullet->golpea_a_enemigo=1;
                }
                qDebug() << game->enemigos->at(i)->zombie.stats[2] << endl;

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
}
