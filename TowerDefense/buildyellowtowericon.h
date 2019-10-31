#ifndef BUILDYELLOWTOWERICON_H
#define BUILDYELLOWTOWERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildYellowTowerIcon: public QGraphicsPixmapItem{
public:
    BuildYellowTowerIcon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // BUILDYELLOWTOWERICON_H
