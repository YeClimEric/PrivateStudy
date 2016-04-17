#include "widget.h"
#include "ui_widget.h"

#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QVariantMap>
#include <QVariant>

#include "weatherinfo.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    data(new Widget::Private())
{
    ui->setupUi(this);
    QComboBox *cityList = new QComboBox(this);
    cityList->addItem(tr("Beijing"), QLatin1String("Beijing, cn"));
    cityList->addItem(tr("Shanghai"), QLatin1String("Shanghai, cn"));
    cityList->addItem(tr("Nanjing"), QLatin1String("Nanjing, cn"));

    QLabel* cityLabel = new QLabel(tr("City:"), this);
    QPushButton *refreshButton = new QPushButton(tr("Refresh"), this);
    QHBoxLayout *cityListLayout = new QHBoxLayout;
    cityListLayout->setDirection(QBoxLayout::LeftToRight);
    cityListLayout->addWidget(cityLabel);
    cityListLayout->addWidget(cityList);
    cityListLayout->addWidget(refreshButton);

    QVBoxLayout *weatherLayout = new QVBoxLayout;
    weatherLayout->setDirection(QBoxLayout::TopToBottom);
    QLabel* cityNameLabel = new QLabel(this);
    weatherLayout->addWidget(cityNameLabel);
    QLabel *dateTimeLabel = new QLabel(this);
    weatherLayout->addWidget(dateTimeLabel);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(cityListLayout);
    mainLayout->addLayout(weatherLayout);
    resize(320, 120);
    setWindowTitle("Weather");

    connect(data->network, &NetWorker::finished, [=](QNetworkReply* reply){
        qDebug()<<"Widget finished";
        QJsonParseError error;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll(), &error);

        if(error.error == QJsonParseError::NoError){
            if(!(jsonDoc.isNull() || jsonDoc.isEmpty()) && (jsonDoc.isObject())){
                QVariantMap data = jsonDoc.toVariant().toMap();
                WeatherInfo weather;
                weather.setCityName(data[QLatin1String("name")].toString());
                QDateTime dateTime;
                dateTime.setTime_t(data[QLatin1String("dt")].toLongLong());
                weather.setDateTime(dateTime);
                QVariantMap main = data[QLatin1String("main")].toMap();
                weather.setTempertuare(main[QLatin1String("temp")].toFloat());
                weather.setPressure(main[QLatin1String("pressure")].toFloat());
                weather.setHumidity(main[QLatin1String("humidity")].toFloat());
                QVariantList detaiList = data[QLatin1String("weather")].toList();
                WeatherDetailList details;
                foreach (QVariant w, detaiList) {
                    QVariantMap wm = w.toMap();
                    WeatherDetail *detail = new WeatherDetail;
                    detail->setDesc(wm[QLatin1String("description")].toString());
                    detail->setIcon(wm[QLatin1Literal("icon")].toString());
                }
                weather.setDetails(details);
                cityNameLabel->setText(weather.cityName());
                dateTimeLabel->setText(weather.dateTime().toString(Qt::DefaultLocaleLongDate));
                qDebug()<<weather;
            }
        }
        reply->deleteLater();
    });

    connect(refreshButton, &QPushButton::clicked, [=]{
        data->fetchWeather(cityList->itemData(cityList->currentIndex()).toString());
        qDebug()<<"refresh Weather";
    });

}

Widget::~Widget()
{
    delete ui;
}
