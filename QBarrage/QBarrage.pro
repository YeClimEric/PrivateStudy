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
SOURCES += \
        main.cpp \
        videoview.cpp \
    Core/Components/ComponentBase.cpp \
    widget/videocontrol.cpp \
    widget/barrageedit.cpp \
    Core/DataClass/CBDataBase.cpp \
    Core/DataClass/CBVerticalScreenData.cpp \
    Core/Components/CBVerticalScreenComponent.cpp \
    Core/Widget/WidgetBase.cpp \
    Core/Widget/BarrageWidget.cpp \
    Core/Animations/ContainerAnimation/BarrageAnimation.cpp

HEADERS  += \
        videoview.h \
    Core/BarrageCore.h \
    widget/videocontrol.h \
    widget/barrageedit.h \
    Core/DataClass/CBVerticalScreenData.h \
    Core/DataClass/CBDataBase.h \
    Core/DynObjectFactory.h \
    Core/Components/CBVerticalScreenComponent.h \
    Core/Widget/BarrageWidget.h \
    Core/Animations/ContainerAnimation/BarrageAnimation.h \
    Core/Components/ComponentBase.h \
    Core/Widget/WidgetBase.h


RESOURCES+= QBarrage.qrc

#RC_FILE  += \
#        QWeather.rc

#FORMS    += \
#        ui/weatherapplication.ui \
#        ui/weathermessagebox.ui

DISTFILES += \
    cn.ts
