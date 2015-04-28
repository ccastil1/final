#ifndef BUILDARCANETOWERICON
#define BUILDARCANETOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildArcaneTowerIcon: public QGraphicsPixmapItem{
public:
    BuildArcaneTowerIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};
#endif // BUILDARCANETOWERICON

