#include "hero.h"
#include "ui_hero.h"

hero::hero(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hero)
{
    ui->setupUi(this);
}

hero::~hero()
{
    delete ui;
}

