#include "Widget.h"
#include <QApplication>
#include <QWebView>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QWebSettings *setting = QWebSettings::globalSettings();
//    setting->setAttribute(QWebSettings::PluginsEnabled, true);
//    setting->setAttribute(QWebSettings::JavascriptEnabled, true);
//    w.SetUrl(QString("http://client.qxiu.com/hall/hall.html?openid=DCF65DF181ECABE99999FFDDA1721355&openkey=A346D66B8C2869B3E004FFD10CC99AD6&userId=45777564&ver=1.22.22.22"));
    //w.SetUrl(QString("http://www.huomao.com/"));
//    w.show();

    Widget w(a);
    w.show();

    return a.exec();
}
