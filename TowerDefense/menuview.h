#ifndef MENUVIEW_H
#define MENUVIEW_H

#include "game.h"

#include <QGraphicsView>
#include <QLineEdit>



class MenuView:public QGraphicsView
{
public:
    MenuView(Game *game);
    QLineEdit *Line_oleadas=new QLineEdit;
    Game *game;
};

#endif // MENUVIEW_H
