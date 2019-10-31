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

};

#endif // GENETICO_H
