CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(cqlabelplugin)
TEMPLATE    = lib

HEADERS     = CQLabelPlugin.h
SOURCES     = CQLabelPlugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. -lcqlabel

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target


