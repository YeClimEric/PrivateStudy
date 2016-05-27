#-------------------------------------------------
#
# Project created by QtCreator 2016-05-27T17:26:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BarrageTemplate
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        cbarragefoundation.cpp \
    BarrageCore/BarrageAnimation.cpp \
    BarrageCore/BarrageWidget.cpp \
    BarrageCore/Components/BarrageComponentBase.cpp

HEADERS  += cbarragefoundation.h \
    BarrageCore/BarrageAnimation.h \
    BarrageCore/BarrageCore.h \
    BarrageCore/BarrageWidget.h \
    BarrageCore/Components/BarrageComponentBase.h

FORMS    += cbarragefoundation.ui
