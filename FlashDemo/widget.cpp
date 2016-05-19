#include "widget.h"
#include "ui_widget.h"
#include <QNetworkProxyFactory>
#include <QWebSettings>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QNetworkProxyFactory::setUseSystemConfiguration(true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, true);

    ui->webView->load(QUrl(":/flash/Resource/7.swf"));
}

Widget::~Widget()
{
    delete ui;
}
