#-------------------------------------------------
#
# Project created by QtCreator 2016-02-02T15:32:50
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += network

TARGET = NetWorkTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    networker.cpp \
    weatherinfo.cpp

HEADERS  += mainwindow.h \
    networker.h \
    weatherinfo.h

FORMS    += mainwindow.ui
