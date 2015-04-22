#-------------------------------------------------
#
# Project created by QtCreator 2015-04-06T16:45:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pacifism
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    animationmanager.cpp \
    ex_graphicsscene.cpp \
    Bullet.cpp \
    hero.cpp

HEADERS  += mainwindow.h \
    animationmanager.h \
    ex_graphicsscene.h \
    Bullet.h \
    hero.h

FORMS    += mainwindow.ui
