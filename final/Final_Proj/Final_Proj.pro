#-------------------------------------------------
#
# Project created by QtCreator 2015-04-20T22:15:27
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Final_Proj
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Game.cpp \
    Health.cpp \
    Player.cpp \
    Score.cpp \
    enemy_bullet.cpp

HEADERS  += mainwindow.h \
    Bullet.h \
    Enemy.h \
    Game.h \
    Health.h \
    Player.h \
    Score.h \
    enemy_bullet.h

FORMS    += mainwindow.ui

RESOURCES += \
    Laser.wav \
    Enemy_plane.png \
    Player_plane.png \
    star-background.png \
    bgmusic.mp3 \
    greenLaserRay.png \
