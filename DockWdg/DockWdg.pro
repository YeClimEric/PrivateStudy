#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T18:15:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DockWdg
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        lcomponent.cpp \
    component.cpp

HEADERS  += lcomponent.h \
    component.h

FORMS    += lcomponent.ui \
    component.ui
