#include "enemy.h"
#include "game.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>

#include <QDebug>
extern Game * game;
Enemy::Enemy(QList<QPointF> pointsToFollow, QGraphicsItem *parent){


    // set points
    points = pointsToFollow;
    point_index = 0;

    //dest = points[0];
    //rotateToPoint(dest);

    // connect timer to move_forward

}

void Enemy::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
}

void Enemy::poner_a_caminar()
{
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveForward()));
    int tope=50;
    int velocidad_inicial=300;
    int aumento_velocidad=this->zombie.stats[this->zombie.velocidad]*20;
    if (velocidad_inicial-aumento_velocidad<tope){
        aumento_velocidad=velocidad_inicial-tope;
    }
    int velocidad_final=velocidad_inicial-aumento_velocidad;
    timer->start(velocidad_final);
}





void Enemy::moveForward(){
    // if close to dest, rotate to next dest

    /*QLineF ln(pos(),dest);

    if (ln.length() < 5){
        point_index++;
        // last point reached
        if (point_index >= points.size()){
            return;
        }
        // last point not reached
        dest = points[point_index];
        rotateToPoint(dest);
    }

    // move enemy forward at current angle
    int STEP_SIZE = 5;
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));*/
    //y=90 y x=90
//    qDebug()<<"intento caminar";
    if (mov_actual==0){if (ruta->length()!=0){
            mov_actual=this->ruta->first();}
        if (mov_actual==1){this->coordenada[0]--;}
        else if(mov_actual==2){this->coordenada[1]--;}
        else if(mov_actual==3){this->coordenada[0]++;}
        else {this->coordenada[0]++;}

    }
    if (this->mov_actual==1 || this->mov_actual==3){
        if(this->pasos==80){
            if (cambio_ruta==0){
                this->ruta->removeFirst();
                this->mov_actual=0;
                if (ruta->length()!=0){
                mov_actual=this->ruta->first();}
                if (mov_actual==1){this->coordenada[0]--;}
                else if(mov_actual==2){this->coordenada[1]--;}
                else if(mov_actual==3){this->coordenada[0]++;}
                else {this->coordenada[0]++;}
            }else{
                if (ruta->length()!=0){
                mov_actual=this->ruta->first();}
                if (mov_actual==1){this->coordenada[0]--;}
                else if(mov_actual==2){this->coordenada[1]--;}
                else if(mov_actual==3){this->coordenada[0]++;}
                else {this->coordenada[0]++;}
                this->cambio_ruta=0;
            }

            this->pasos=0;
        }
        if (mov_actual==1){setPos(x()-2, y());}
        else {setPos(x()+2, y());}
        this->pasos+=2;

    }
    if (this->mov_actual==2 || this->mov_actual==4){
        if(this->pasos==60){
            if (cambio_ruta==0){
                this->ruta->removeFirst();
                this->mov_actual=0;
                if (ruta->length()!=0){
                mov_actual=this->ruta->first();}
                if (mov_actual==1){this->coordenada[0]--;}
                else if(mov_actual==2){this->coordenada[1]--;}
                else if(mov_actual==3){this->coordenada[0]++;}
                else {this->coordenada[0]++;}
            }else{
                if (ruta->length()!=0){
                mov_actual=this->ruta->first();}
                if (mov_actual==1){this->coordenada[0]--;}
                else if(mov_actual==2){this->coordenada[1]--;}
                else if(mov_actual==3){this->coordenada[0]++;}
                else {this->coordenada[0]++;}
                this->cambio_ruta=0;
            }

            this->pasos=0;
        }
        if (mov_actual==2){setPos(x(), y()-2);}
        else {setPos(x(), y()+2);}
        this->pasos+=2;
    }


    if (y()<=0+10 && x()>=80*9-10){
        this->hide();
        this->zombie.stats[2]=this->zombie.vida_incial;
        if (game->enemigos->contains(this)){
            game->enemigos_pasados->append(this->zombie);
            game->enemigos->removeOne(this);
        }
        if (game->enemigos->length()==0 && game->enemiesSpawned==game->maxNumberOfEnemies){
            game->contador_union_zombie_enemigo=0;
            game->pasar_generacion();
        }
    }

}
