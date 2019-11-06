#include "custombutton.h"
#include "estadisticasview.h"

CustomButton::CustomButton(Game *game)
{
    this->game=game;
}

void CustomButton::mousePressEvent(QMouseEvent *event){
    if (this->text().compare("estadisticas")==0){
    Estadisticasview *view=new Estadisticasview(this->game);
    view->show();
    }
    else if(this->text().compare("Por Oleadas")==0){
        this->game->empezar_generacion(this->menu->Line_oleadas->text().toInt());
        this->game->show();
        this->menu->close();
    }
    else if(this->text().compare("Primer graduado")==0){
        this->game->empezar_primer_ganador();
        this->game->show();
        this->menu->close();

    }

}
