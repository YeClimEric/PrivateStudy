#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "networker.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    class Private;
    friend class Private;
    Private *data;
};

class Widget::Private
{
public:
    Private()
    {
        network = NetWorker::getInstance();
    }
    void fetchWeather(const QString &cityName)
    {
        network->get(QString("http://api.openweathermap.org/data/2.5/weather?q=%1&mode=json&units=metric&lang=zh_cn").arg(cityName));
    }

    NetWorker* network;
};

#endif // WIDGET_H
