#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*
Qt 进行网络访问的类是QNetworkAccessManager。为了使用网络相关的类，你需要在 pro 文件中添加QT += network
这个 API 本身就是异步设计，这意味着我们不需要自己为其开启线程，以防止界面被锁死,但是却要求我们使用更多的代码来监听返回

一个应用程序仅需要一个QNetworkAccessManager类的实例, QNetworkAccessManager本身没有被设计为单例
一旦一个QNetworkAccessManager实例创建完毕，我们就可以使用它发送网络请求。这些请求都返回QNetworkReply对象作为响应。这个对象一般会包含有服务器响应的数据

http://openweathermap.org/api 天气API
*/

#include <QMainWindow>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "networker.h"
#include <QDebug>

namespace Ui {
class MainWindow;
}

class Private
{
public:
    Private()
    {
        netWorker = NetWorker::instance();
    }

    void fetchWeather(const QString &cityName) const
    {
        netWorker->get(QString("http://api.openweathermap.org/data/2.5/weather?q=%1&appid=44db6a862fba0b067b1930da0d769e98&lang=zh_cn&units=metric").arg(cityName));
//        qDebug() << cityName;
    }
    NetWorker* netWorker;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
//    Ui::MainWindow *ui;
    friend class Private;
    Private *d;

    QWidget* mainWidget;
    QComboBox *cityList;
    QLabel* cityLabel,*cityNameLabel, *dateTimeLabel;
    QPushButton *refreshBtn;
    QVBoxLayout* cityListLayout;
    QVBoxLayout* weatherLayout;
    QVBoxLayout* mainLayout;
};



#endif // MAINWINDOW_H
