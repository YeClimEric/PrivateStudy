#-------------------------------------------------
#
# Project created by QtCreator 2015-12-28T19:55:02
#
#-------------------------------------------------

QT       += core gui

equals(QT_MAJOR_VERSION, 4){
QT       += multimedia
}
equals(QT_MAJOR_VERSION, 5){
QT       += widgets multimediawidgets
}

TARGET = QBarrage
TEMPLATE = app

win32{
    equals(QT_MAJOR_VERSION, 5):{
        msvc{
            !contains(QMAKE_TARGET.arch, x86_64){
                 #support on windows XP
                 QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01
            }
        }

        gcc{
            QMAKE_CXXFLAGS += -std=c++11
            QMAKE_CXXFLAGS += -Wunused-function
            QMAKE_CXXFLAGS += -Wswitch
        }
    }
    equals(QT_MAJOR_VERSION, 4):{
            QMAKE_CXXFLAGS += -std=c++11
            QMAKE_CXXFLAGS += -Wunused-function
            QMAKE_CXXFLAGS += -Wswitch
    }
}

INCLUDEPATH += $$PWD/BarrageCore \
               $$PWD/widget \
                $$PWD/Components   \
               $$PWD/

TRANSLATIONS += cn.ts

SOURCES += \
        main.cpp \
        videoview.cpp \
    BarrageCore/BarrageAnimation.cpp \
    BarrageCore/BarrageWidget.cpp \
    BarrageCore/Components/BarrageComponentBase.cpp \
    widget/videocontrol.cpp \
    widget/barrageedit.cpp \
    BarrageCore/DataClass/cbdatabase.cpp \
    BarrageCore/DataClass/cbverticalscreendata.cpp \
    BarrageCore/Components/cbverticalscreencomponent.cpp

HEADERS  += \
        videoview.h \
    BarrageCore/BarrageAnimation.h \
    BarrageCore/BarrageCore.h \
    BarrageCore/BarrageWidget.h \
    BarrageCore/Components/BarrageComponentBase.h \
    widget/videocontrol.h \
    widget/barrageedit.h \
    BarrageCore/Components/cbverticalscreencomponent.h \
    BarrageCore/DataClass/cbdatabase.h \
    BarrageCore/DataClass/cbverticalscreendata.h \
    BarrageCore/dynobjectfactory.h


RESOURCES+= QBarrage.qrc

#RC_FILE  += \
#        QWeather.rc

#FORMS    += \
#        ui/weatherapplication.ui \
#        ui/weathermessagebox.ui

DISTFILES += \
    cn.ts
