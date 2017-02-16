#-------------------------------------------------
#
# Project created by QtCreator 2016-12-21T22:37:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets

TARGET = Components
TEMPLATE = app

CONFIG += c++11

INCLUDEPATH += . \
    ./Label \


SOURCES += main.cpp\
        Widget.cpp \
    Label/CQLabel.cpp \
    Web/CQWebPage.cpp \
    Web/CQWebView.cpp \
    Web/CNetWorker.cpp

HEADERS  += Widget.h \
    Label/CQLabel.h \
    Web/CQWebPage.h \
    Web/CQWebView.h \
    Web/IWebViewInterface.h \
    Web/CNetWorker.h

FORMS    += Widget.ui
