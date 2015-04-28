#ifndef ARCHERTOWER
#define ARCHERTOWER

#include "tower.h"

class ArcherTower: public Tower{
    Q_OBJECT
public:
    ArcherTower(QGraphicsItem * parent=0);
    void fire();
public slots:
    void aquire_target();
};

#endif // ARCHERTOWER

