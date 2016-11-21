#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "weatherinfo.h"

#include <QJsonParseError>
#include <QVariantMap>
#include <QDateTime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
//    ui(new Ui::MainWindow)
    d(new Private()),
    cityList(new QComboBox(this)),
    cityLabel(new QLabel(tr("City"),this)),
    cityNameLabel(new QLabel(this)),
    dateTimeLabel(new QLabel(this)),
    refreshBtn(new QPushButton(tr("Refresh"), this)),
    cityListLayout(new QVBoxLayout),
    weatherLayout(new QVBoxLayout),
    mainWidget(new QWidget(this)),
    mainLayout(new QVBoxLayout(mainWidget))
{
//    ui->setupUi(this);
    cityList->addItem(tr("Beijing"), QLatin1String("Beijing,cn"));
    cityList->addItem(tr("Shanghai"), QLatin1String("Shanghai,cn"));
    cityList->addItem(tr("Nanjing"), QLatin1String("Nanjing,cn"));

    cityListLayout->addWidget(cityLabel);
    cityListLayout->addWidget(cityList);
    cityListLayout->addWidget(refreshBtn);

    weatherLayout->setDirection(QBoxLayout::TopToBottom);
    weatherLayout->addWidget(cityNameLabel);
    weatherLayout->addWidget(dateTimeLabel);

    mainLayout->addLayout(cityListLayout);
    mainLayout->addLayout(weatherLayout);
    setCentralWidget(mainWidget);
    resize(320, 120);
    setWindowTitle(tr("Weather"));

//    connect(d->netWorker, &NetWorker::finished, [=] (QNetworkReply *reply) {
//            qDebug() << reply;
//            QJsonParseError error;
//            QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll(), &error);
//            if (error.error == QJsonParseError::NoError) {
//                if (!(jsonDocument.isNull() || jsonDocument.isEmpty()) && jsonDocument.isObject()) {
//                    QVariantMap data = jsonDocument.toVariant().toMap();
//                    WeatherInfo weather;
//                    weather.setCityName(data[QLatin1String("name")].toString());
//                    QDateTime dateTime;
//                    dateTime.setTime_t(data[QLatin1String("dt")].toLongLong());
//                    weather.setDateTime(dateTime);
//                    QVariantMap main = data[QLatin1String("main")].toMap();
//                    weather.setTemperature(main[QLatin1String("temp")].toFloat());
//                    weather.setPressure(main[QLatin1String("pressure")].toFloat());
//                    weather.setHumidity(main[QLatin1String("humidity")].toFloat());
//                    QVariantList detailList = data[QLatin1String("weather")].toList();
//                    QList<WeatherDetail *> details;
//                    foreach (QVariant w, detailList) {
//                        QVariantMap wm = w.toMap();
//                        WeatherDetail *detail = new WeatherDetail;
//                        detail->setDesc(wm[QLatin1String("description")].toString());
//                        detail->setIcon(wm[QLatin1String("icon")].toString());
//                        details.append(detail);
//                    }
//                    weather.setDetails(details);

//                    cityNameLabel->setText(weather.cityName());
//                    dateTimeLabel->setText(weather.dateTime().toString(Qt::DefaultLocaleLongDate));
//                }
//            } else {
//                QMessageBox::critical(this, tr("Error"), error.errorString());
//            }
//            reply->deleteLater();
//        });
    connect(d->netWorker, &NetWorker::finished, [=](QNetworkReply* reply){
//        qDebug() << reply;
        QJsonParseError error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll(), &error);
        if(jsonDocument.isEmpty())
        {
            qDebug()<<"json is empty";
        }
        else
            qDebug()<<"json is not empty";
        qDebug() << jsonDocument.toJson();
//        qDebug() << jsonDocument.toVariant().toString();
    });

    connect(refreshBtn, &QPushButton::clicked, [=] () {
        d->fetchWeather(cityList->itemData(cityList->currentIndex()).toString());
    });
}

MainWindow::~MainWindow()
{
//    delete ui;
}



