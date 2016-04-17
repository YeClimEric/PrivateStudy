#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include "networker.h"

namespace Ui {
class Widget;
}

enum RemoteRequest {
    FetchWeatherInfo,
    FetchWeatherIcon
};

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
    Private *m_pData;
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
        QNetworkReply* reply = network->get(QString("http://api.openweathermap.org/data/2.5/weather?q=%1&mode=json&units=metric&lang=zh_cn").arg(cityName));
        replyMap.insert(reply, FetchWeatherInfo);
    }
    void fetchIcon(const QString &iconName)
    {
        QNetworkReply* reply = network->get(QString("http://openweathermap.org/img/w/%1.png").arg(iconName));
        replyMap.insert(reply, FetchWeatherIcon);
    }

    NetWorker* network;
    QMap<QNetworkReply *, RemoteRequest> replyMap;
    QLabel* iconLabel;
    QLabel*descLabel;
};

#endif // WIDGET_H
