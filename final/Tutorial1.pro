#-------------------------------------------------
#
# Project created by QtCreator 2015-04-09T20:53:05
#
#-------------------------------------------------

QT       += core gui \
            multimedia //this line added from default to allow use of the multimedia library

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tutorial1
TEMPLATE = app


SOURCES += main.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Game.cpp \
    Score.cpp \
    Player.cpp \
    Health.cpp

HEADERS  += \
    Bullet.h \
    Enemy.h \
    Game.h \
    Score.h \
    Player.h \
    Health.h

RESOURCES += \
    res.qrc
