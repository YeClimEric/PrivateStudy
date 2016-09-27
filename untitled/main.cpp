#include "widget.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    qDebug()<<"w's Objectname:"<<w.objectName();
    if(w.parent() != nullptr)
        qDebug()<<"w's parent's Objectname:"<<w.parent()->objectName();


    w.show();

    return a.exec();
}
