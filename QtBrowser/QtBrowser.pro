#-------------------------------------------------
#
# Project created by QtCreator 2016-08-19T15:19:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += webkit
QT += webkitwidgets

CONFIG += c++11

TARGET = QtBrowser
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    CCustomWebControl.cpp

HEADERS  += Widget.h \
    CCustomWebControl.h

FORMS    += Widget.ui
