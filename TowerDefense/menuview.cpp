#include "custombutton.h"
#include "menuview.h"

#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>

MenuView::MenuView(Game *game)
{
    this->game=game;
    QGraphicsScene *scene=new QGraphicsScene;
    this->setScene(scene);
    QGroupBox *box=new QGroupBox;
    box->move(0,0);
    QLayout *layoutv=new QVBoxLayout();
    QLayout *layouth2=new QHBoxLayout();
    QLayout *layouth3=new QHBoxLayout();
    CustomButton *button_oleadas=new CustomButton(this->game);
    CustomButton *button_graduado=new CustomButton(this->game);
    button_oleadas->menu=this;
    button_graduado->menu=this;
    button_oleadas->setText("Por Oleadas");
    button_graduado->setText("Primer graduado");
    layoutv->addItem(layouth2);
    layoutv->addItem(layouth3);
    QLabel *l_prob_mutacion=new QLabel("Seleccione Modo de Juego:");
    layouth2->addWidget(l_prob_mutacion);
    layouth3->addWidget(this->Line_oleadas);
    layouth3->addWidget(button_oleadas);
    layouth3->addWidget(button_graduado);
    box->setLayout(layoutv);
    scene->addWidget(box);
}
