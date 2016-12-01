#include "Widget.h"
#include <QApplication>
#include "Components/Browser/CWebViewWidget.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CWebViewWidget w;
    w.SetUrl(QString("http://client.qxiu.com/hall/hall.html"));
    w.show();
//    Widget w(a);
//    w.show();

    return a.exec();
}
