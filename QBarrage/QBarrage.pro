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
    BarrageCore/Components/ComponentBase.cpp \
    widget/videocontrol.cpp \
    widget/barrageedit.cpp \
    BarrageCore/DataClass/CBDataBase.cpp \
    BarrageCore/DataClass/CBVerticalScreenData.cpp \
    BarrageCore/Components/CBVerticalScreenComponent.cpp \
    BarrageCore/Widget/WidgetBase.cpp \
    BarrageCore/Widget/BarrageWidget.cpp \
    BarrageCore/Animations/ContainerAnimation/BarrageAnimation.cpp

HEADERS  += \
        videoview.h \
    BarrageCore/BarrageCore.h \
    widget/videocontrol.h \
    widget/barrageedit.h \
    BarrageCore/DataClass/CBVerticalScreenData.h \
    BarrageCore/DataClass/CBDataBase.h \
    BarrageCore/DynObjectFactory.h \
    BarrageCore/Components/CBVerticalScreenComponent.h \
    BarrageCore/Widget/BarrageWidget.h \
    BarrageCore/Animations/ContainerAnimation/BarrageAnimation.h \
    BarrageCore/Components/ComponentBase.h \
    BarrageCore/Widget/WidgetBase.h


RESOURCES+= QBarrage.qrc

#RC_FILE  += \
#        QWeather.rc

#FORMS    += \
#        ui/weatherapplication.ui \
#        ui/weathermessagebox.ui

DISTFILES += \
    cn.ts
