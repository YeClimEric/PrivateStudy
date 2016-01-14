#-------------------------------------------------
#
# Project created by QtCreator 2016-01-14T14:55:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GluttonousSnake
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    food.cpp \
    gamecontroller.cpp

HEADERS  += mainwindow.h \
    food.h \
    common.h \
    gamecontroller.h

FORMS    += mainwindow.ui
