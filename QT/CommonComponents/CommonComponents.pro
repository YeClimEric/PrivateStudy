#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T13:02:30
#
#-------------------------------------------------

QT       += core gui webkit network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets  webkitwidgets

CONFIG += c++11

TARGET = CommonComponents
TEMPLATE = app

INCLUDEPATH += QtNetwork QtWebKitWidgets

SOURCES += main.cpp\
        Widget.cpp \
    Components/Browser/CWebViewWidget.cpp

HEADERS  += Widget.h \
    Components/Browser/CWebViewWidget.h

FORMS    += Widget.ui \
    Components/Browser/CWebViewWidget.ui

RESOURCES += \
    Resource/Skins.qrc
