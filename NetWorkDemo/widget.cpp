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
#include <QMessageBox>

#include "weatherinfo.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_pData(new Widget::Private())
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

    m_pData->descLabel = new QLabel(this);
    weatherLayout->addWidget(m_pData->descLabel);
    m_pData->iconLabel = new QLabel(this);
    weatherLayout->addWidget(m_pData->iconLabel);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(cityListLayout);
    mainLayout->addLayout(weatherLayout);
    resize(320, 120);
    setWindowTitle("Weather");

    connect(m_pData->network, &NetWorker::finished, [=](QNetworkReply* reply){
        switch(m_pData->replyMap.value(reply))
        {
        case FetchWeatherInfo:
            {
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
                            details.append(detail);
                        }
                        weather.setDetails(details);
                        cityNameLabel->setText(weather.cityName());
                        dateTimeLabel->setText(weather.dateTime().toString(Qt::DefaultLocaleLongDate));
                        m_pData->descLabel->setText(weather.details().at(0)->desc());
                        qDebug()<<weather;
                    }
                    else{
                        QMessageBox::critical(this, "Error","Parse Reply Error!");
                    }
                }
            }
        case FetchWeatherIcon:
            {
            QPixmap pixmap;
            pixmap.loadFromData(reply->readAll());
            m_pData->iconLabel->setPixmap(pixmap);
            }
        }
        reply->deleteLater();
    });

    connect(refreshButton, &QPushButton::clicked, [=]{
        m_pData->fetchWeather(cityList->itemData(cityList->currentIndex()).toString());
    });

}

Widget::~Widget()
{
    delete ui;
}
