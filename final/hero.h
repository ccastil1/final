
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

private:
    Ui::hero *ui;
};

#endif // HERO_H

