#ifndef ZOMBIE_H
#define ZOMBIE_H


class Zombie
{
public:
    // lo valores de los atributos son para acceder al de la lista con mayor facilidad y orden
    //para el tipo 1=ogro,2=Elfo Osucro, 3=Harpia,4=Mercenario
    Zombie();
    int tipo=0;
    int velocidad=1;
    int vida=2;
    int vida_incial;
    int Res_arquero=3;
    int Res_mago=4;
    int Res_artillero=5;
    int Res_fuego=6;
    int stats[7];
    int modo_movimiento=8;
    int backtracking=8;
    int A=9;
    void crear_zombie_ramdon();
    void crear_Orco();
    void crear_Elfo();
    void crear_Harpia();
    void crear_Mercenario();

};

#endif // ZOMBIE_H
