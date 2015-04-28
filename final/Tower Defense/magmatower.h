#ifndef MAGMATOWER
#define MAGMATOWER

#include "tower.h"

class MagmaTower: public Tower{
    Q_OBJECT
public:
    MagmaTower(QGraphicsItem * parent=0);
    void fire();
public slots:
    void aquire_target();
};
#endif // MAGMATOWER

