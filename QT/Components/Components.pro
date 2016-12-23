#-------------------------------------------------
#
# Project created by QtCreator 2016-12-21T22:37:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += webenginewidgets


TARGET = Components
TEMPLATE = app

CONFIG += c++11

INCLUDEPATH += . \
    ./Label


SOURCES += main.cpp\
        Widget.cpp \
    Label/CQLabel.cpp

HEADERS  += Widget.h \
    Label/CQLabel.h

FORMS    += Widget.ui
