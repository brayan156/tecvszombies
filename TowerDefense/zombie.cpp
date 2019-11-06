#include "zombie.h"
#include <iostream>
#include <QDebug>
Zombie::Zombie()
{

}

void Zombie::crear_zombie_ramdon()
{
    int tipo=rand()%4;

    if (tipo==0){
        crear_Orco();
    }
    else if (tipo==1) {
       crear_Elfo();
    }
    else if (tipo==2) {
        crear_Harpia();
    }
    else {
       crear_Mercenario();
    }
}





void Zombie::crear_Orco()
{
    stats[this->tipo]=1;
    stats[this->velocidad]=3;
    for (int i=2; i<7;i++){
        if (i==this->Res_arquero){
            stats[i]=rand()%5+6;
        }
        else if (i==3) {
            stats[i]=rand()%10+1;
        }
        else  {
            stats[i]=rand()%5+1;
        }
    }
    this->vida_incial=this->stats[this->vida];
}

void Zombie::crear_Elfo()
{
    stats[this->tipo]=2;
    stats[this->velocidad]=5;
    for (int i=2; i<7;i++){
        if (i==this->Res_arquero || i== this->Res_mago){
            stats[i]=rand()%5+6;
        }
        else if (i==this->Res_artillero || i==this->Res_fuego) {
            stats[i]=rand()%5+1;
        }
        else  {
            stats[i]=rand()%10+1;
        }
    }
    this->vida_incial=this->stats[this->vida];
}

void Zombie::crear_Harpia()
{
    stats[this->tipo]=3;
    stats[this->velocidad]=5;
    for (int i=2; i<7;i++){
        stats[i]=rand()%10+1;

    }
    this->vida_incial=this->stats[this->vida];
}

void Zombie::crear_Mercenario()
{
    stats[this->tipo]=4;
    stats[this->velocidad]=7;
    for (int i=2; i<7;i++){
        if (i==this->Res_arquero || i==this->Res_mago || i==this->Res_artillero){
            stats[i]=rand()%5+6;
        }
        else if (i==this->Res_fuego) {
            stats[i]=rand()%5+1;
        }
        else  {
            stats[i]=rand()%10+1;
        }
    }
    this->vida_incial=this->stats[this->vida];
}
