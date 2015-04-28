#ifndef BUILDARCHERTOWERICON
#define BUILDARCHERTOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildArcherTowerIcon: public QGraphicsPixmapItem{
public:
    BuildArcherTowerIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDARCHERTOWERICON

