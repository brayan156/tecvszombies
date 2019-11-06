#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include "game.h"
#include "menuview.h"

#include <QGraphicsView>
#include <QPushButton>



class CustomButton: public QPushButton
{
public:
    CustomButton(Game *game);
    void mousePressEvent(QMouseEvent *event);
    Game *game;
    MenuView *menu;

};

#endif // CUSTOMBUTTON_H
