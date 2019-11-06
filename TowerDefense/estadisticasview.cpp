#include "estadisticasview.h"

#include <QGroupBox>
#include <QVBoxLayout>
#include <iostream>
#include <thread>




Estadisticasview::Estadisticasview(Game *game)
{
    this->game=game;
    QGraphicsScene *scene=new QGraphicsScene;
    this->setScene(scene);
    this->B_Poblacion=new QTextBrowser;
    this->B_Torres=new QTextBrowser;
    this->B_Zombies_muertos=new QTextBrowser;
    this->B_Poblacion->setMinimumSize(750,200);
    this->B_Torres->setMinimumSize(750,200);
    this->B_Zombies_muertos->setMinimumSize(800,200);
    scene->addWidget(B_Poblacion);
    QGroupBox *box=new QGroupBox;
    box->move(0,0);
    QLayout *layoutv=new QVBoxLayout();
    QLayout *layouth2=new QHBoxLayout();
    QLayout *layouth3=new QHBoxLayout();
    QLayout *layouth4=new QHBoxLayout();
    QLayout *layouth5=new QHBoxLayout();
    QLayout *layouth6=new QHBoxLayout();
    QLayout *layouth41=new QHBoxLayout();
    QLayout *layouth51=new QHBoxLayout();
    QLayout *layouth61=new QHBoxLayout();
    layoutv->addItem(layouth2);
    layoutv->addItem(layouth3);
    layoutv->addItem(layouth41);
    layoutv->addItem(layouth4);
    layoutv->addItem(layouth51);
    layoutv->addItem(layouth5);
    layoutv->addItem(layouth61);
    layoutv->addItem(layouth6);
    QLabel *l_prob_mutacion=new QLabel("Probabilidad de mutacion: "+ QString::number(this->game->cruzador.prob_mutacion)+"0%  ");
    QLabel *l_prob_inversion=new QLabel("Probabilidad de inversion: "+ QString::number(this->game->cruzador.prob_inversion)+"0%  ");
    layouth2->addWidget(l_prob_mutacion);
    layouth2->addWidget(l_prob_inversion);
    layouth2->addWidget(this->label_generaciones);
    layouth3->addWidget(this->label_mutaciones);
    layouth3->addWidget(this->label_inversiones);
    layouth4->addWidget(this->B_Poblacion);
    layouth5->addWidget(this->B_Zombies_muertos);
    layouth6->addWidget(this->B_Torres);
    layouth41->addWidget(new QLabel("Poblacion en mapa:"));
    layouth51->addWidget(new QLabel("Zombies caidos:"));
    layouth61->addWidget(new QLabel("Torres en mapa:"));
    qDebug()<<"aqui";


    box->setLayout(layoutv);
    scene->addWidget(box);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(cargar_dataset()));
    timer->start(100);



}

void Estadisticasview::cargar_dataset()
{

    this->B_Poblacion->clear();
    this->label_generaciones->setText("Generaciones: "+QString::number(this->game->cruzador.num_generacion));
    this->label_mutaciones->setText("Mutaciones: "+QString::number(this->game->cruzador.cant_mutaciones));
    this->label_inversiones->setText("Inversiones: "+QString::number(this->game->cruzador.cant_inversiones));
    QList<Enemy*> *lista_enemigos=this->game->enemigos;
    for (int i=0;i<lista_enemigos->length();i++){
        Zombie zombie=lista_enemigos->at(i)->zombie;
        int tipo_int=zombie.stats[zombie.tipo];
        QString tipo="";
        //para el tipo 1=ogro,2=Elfo Osucro, 3=Harpia,4=Mercenario
        if (tipo_int==1){tipo="Ogro";}
        else if (tipo_int==2){tipo="Elfo Oscuro";}
        else if (tipo_int==3){tipo="Harpia";}
        else if (tipo_int==4){tipo="Mercenario";}
        this->B_Poblacion->append("tipo = " +tipo+", "+
                            "vida = " + QString::number(zombie.stats[zombie.vida])+", "+
                            "velocidad = "+QString::number(zombie.stats[zombie.velocidad])+", "+
                            "Res_mago = "+QString::number(zombie.stats[zombie.Res_mago])+", "+
                            "Res_fuego = "+QString::number(zombie.stats[zombie.Res_fuego])+", "+
                            "Res_arquero = "+QString::number(zombie.stats[zombie.Res_arquero])+", "+
                            "Res_artillero = "+QString::number(zombie.stats[zombie.Res_artillero]));

    }
    this->B_Zombies_muertos->clear();

    for (int i=0;i<this->game->enemigos_eliminados->length();i++){
        Zombie zombie=this->game->enemigos_eliminados->at(i);
        int tipo_int=zombie.stats[zombie.tipo];
        QString tipo="";
        //para el tipo 1=ogro,2=Elfo Osucro, 3=Harpia,4=Mercenario
        if (tipo_int==1){tipo="Ogro";}
        else if (tipo_int==2){tipo="Elfo Oscuro";}
        else if (tipo_int==3){tipo="Harpia";}
        else if (tipo_int==4){tipo="Mercenario";}
        this->B_Zombies_muertos->append("tipo = " +tipo+", "+
                            "vida = " + QString::number(zombie.stats[zombie.vida])+", "+
                            "velocidad = "+QString::number(zombie.stats[zombie.velocidad])+", "+
                            "Res_mago = "+QString::number(zombie.stats[zombie.Res_mago])+", "+
                            "Res_fuego = "+QString::number(zombie.stats[zombie.Res_fuego])+", "+
                            "Res_arquero = "+QString::number(zombie.stats[zombie.Res_arquero])+", "+
                            "Res_artillero = "+QString::number(zombie.stats[zombie.Res_artillero]));

    }
}
