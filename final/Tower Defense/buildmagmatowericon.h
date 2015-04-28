#ifndef BUILDMAGMATOWERICON
#define BUILDMAGMATOWERICON

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildMagmaTowerIcon: public QGraphicsPixmapItem{
public:
    BuildMagmaTowerIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};
#endif // BUILDMAGMATOWERICON

