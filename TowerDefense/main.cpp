#include <QApplication>
#include "game.h"

/*
Tutorial topics:
Review/apply a bunch of previously learned concepts
New Topics:
QGraphicsLineItem, setWidth(), setColor()
QTimer::disconnect()
*/

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();


    return a.exec();
}
