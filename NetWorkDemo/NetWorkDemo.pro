#-------------------------------------------------
#
# Project created by QtCreator 2016-04-14T14:00:45
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NetWorkDemo
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    networker.cpp \
    weatherinfo.cpp

HEADERS  += widget.h \
    networker.h \
    weatherinfo.h

FORMS    += widget.ui
