#ifndef ARCANETOWER
#define ARCANETOWER

#include "tower.h"

class ArcaneTower: public Tower{
    Q_OBJECT
public:
    ArcaneTower(QGraphicsItem * parent=0);
    void fire();
public slots:
    void aquire_target();
};
#endif // ARCANETOWER

