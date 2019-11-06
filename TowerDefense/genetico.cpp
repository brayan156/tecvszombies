#include "genetico.h"

Genetico::Genetico()
{

}

QList<Zombie> *Genetico::Combinar(QList<Zombie> *zombies_a_cruzar)
{
    QList<Zombie>* nuevagen=new QList<Zombie>;
    for (int i=0; i < zombies_a_cruzar->length();i++){

        Zombie zombie1=zombies_a_cruzar->at(i);
        for (int j=i+1; j<zombies_a_cruzar->length();j++){
            Zombie nuevozombie;
            Zombie zombie2=zombies_a_cruzar->at(j);
            int tipo=rand()%2;
            if (tipo==0){
                nuevozombie.stats[zombie1.tipo]=zombie1.stats[zombie1.tipo];
                nuevozombie.stats[zombie1.velocidad]=zombie1.stats[zombie1.velocidad];
            }
            else{
                nuevozombie.stats[zombie2.tipo]=zombie2.stats[zombie2.tipo];
                nuevozombie.stats[zombie2.velocidad]=zombie2.stats[zombie2.velocidad];
            }
            int orden=rand()%2;
            if (orden==0){
                nuevozombie.stats[2]=zombie1.stats[2];
                nuevozombie.stats[3]=zombie1.stats[3];
                nuevozombie.stats[4]=zombie2.stats[4];
                nuevozombie.stats[5]=zombie2.stats[5];
                nuevozombie.stats[6]=zombie2.stats[6];

            }
            else{
                nuevozombie.stats[2]=zombie2.stats[2];
                nuevozombie.stats[3]=zombie2.stats[3];
                nuevozombie.stats[4]=zombie1.stats[4];
                nuevozombie.stats[5]=zombie1.stats[5];
                nuevozombie.stats[6]=zombie1.stats[6];
            }
            int n_inverision=rand()%10;
            if (n_inverision>this->prob_inversion){
                nuevozombie=this->Inversion(nuevozombie);
                this->cant_inversiones++;
            }
            for (int m=2;m<7;m++){
                int n_mutancion=rand()%10;
                if (n_mutancion>this->prob_mutacion){
                    nuevozombie.stats[m]+=2;
                    this->cant_mutaciones++;
                }
            }
            nuevozombie.vida_incial=nuevozombie.stats[nuevozombie.vida];
            nuevagen->append(nuevozombie);
        }
    }
    this->num_generacion++;
    return nuevagen;
}

Zombie Genetico::Inversion(Zombie zombie_a_invertir)
{
    Zombie zombie_invertido;
    int j=6;
    zombie_invertido.stats[zombie_invertido.velocidad]=zombie_a_invertir.stats[zombie_a_invertir.velocidad];
    for (int i=2;i<j;i++){
        zombie_invertido.stats[i]=zombie_a_invertir.stats[j];
        zombie_invertido.stats[j]=zombie_a_invertir.stats[i];
        j--;
    }
    zombie_invertido.stats[j]=zombie_a_invertir.stats[j];
    return zombie_invertido;
}
