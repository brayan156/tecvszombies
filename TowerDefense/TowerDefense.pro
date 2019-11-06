#-------------------------------------------------
#
# Project created by QtCreator 2019-10-28T20:22:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerDefense
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        astar.cpp \
        backtracking.cpp \
        browntower.cpp \
        buildbrowntowericon.cpp \
        buildgreentowericon.cpp \
        buildredtowericon.cpp \
        buildyellowtowericon.cpp \
        bullet.cpp \
        custombutton.cpp \
        enemy.cpp \
        estadisticasview.cpp \
        game.cpp \
        genetico.cpp \
        greentower.cpp \
        main.cpp \
        mainwindow.cpp \
        menuview.cpp \
        par.cpp \
        redtower.cpp \
        tower.cpp \
        yellowtower.cpp \
        zombie.cpp

HEADERS += \
        backtracking.h \
        browntower.h \
        buildbrowntowericon.h \
        buildgreentowericon.h \
        buildredtowericon.h \
        buildyellowtowericon.h \
        bullet.h \
        custombutton.h \
        enemy.h \
        estadisticasview.h \
        game.h \
        genetico.h \
        greentower.h \
        mainwindow.h \
        menuview.h \
        par.h \
        redtower.h \
        tower.h \
        yellowtower.h \
        zombie.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
