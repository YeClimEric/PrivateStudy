#include "Widget.h"
#include <QApplication>

#include "MyAxWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w1;
    w1.show();

    MyAxWidget w;
    w.show();

    return a.exec();
}
