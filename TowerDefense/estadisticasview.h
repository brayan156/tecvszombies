#ifndef ESTADISTICASVIEW_H
#define ESTADISTICASVIEW_H

#include "game.h"

#include <QGraphicsView>
#include <QLabel>
#include <QLineEdit>
#include <QTextBrowser>

class Estadisticasview: public QGraphicsView{
    Q_OBJECT
public:
    Estadisticasview(Game *game);
    Game *game;
    QTimer * spawnTimer;


    QTextBrowser *B_Zombies_muertos;
    QTextBrowser *B_Poblacion;
    QTextBrowser *B_Torres;
    QLabel *label_generaciones=new QLabel;
    QLabel *label_mutaciones=new QLabel;
    QLabel *label_inversiones=new QLabel;

public slots:
    void cargar_dataset();
};

#endif // ESTADISTICASVIEW_H
