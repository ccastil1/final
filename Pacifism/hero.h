
#ifndef HERO_H
#define HERO_H

#include <QMainWindow>

namespace Ui {
class hero;
}

class hero : public QMainWindow
{
    Q_OBJECT

public:
    explicit hero(QWidget *parent = 0);
    ~hero();
    int getHealth();

private:
    void update(); //IMPORTANT: collide is determined here
    Ui::hero *ui;
    int health;
    int vX; //X velocity
    int vY; //Y velocity
};

#endif // HERO_H

