#-------------------------------------------------
#
# Project created by QtCreator 2016-10-20T15:48:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = puzla
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    customrectitem.cpp \
    custompolygonitem.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    scene.h \
    customrectitem.h \
    custompolygonitem.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

CONFIG +=static
