#ifndef GENETICO_H
#define GENETICO_H

#include "zombie.h"

#include <QList>



class Genetico
{
public:
    Genetico();
    QList<Zombie> *Combinar(QList<Zombie> *zombies_a_cruzar);
    Zombie Inversion(Zombie zombie_a_invertir);
    int prob_mutacion=2;
    int prob_inversion=4;
    int cant_mutaciones=0;
    int cant_inversiones=0;
    int num_generacion=1;

};

#endif // GENETICO_H
