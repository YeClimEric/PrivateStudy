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
INCLUDEPATH += .\Components\Browser \
               .\Examples

SOURCES += main.cpp\
        Widget.cpp \
    Components/Browser/CustomWebPage.cpp \
    Components/Browser/CustomWebView.cpp \
    Examples/CExample_WebView.cpp

HEADERS  += Widget.h \
    Components/Browser/CustomWebPage.h \
    Components/Browser/CustomWebView.h \
    Components/Browser/IWebViewHelper.h \
    Examples/CExample_WebView.h

FORMS    += Widget.ui \

RESOURCES += \
    Resource/Skins.qrc
