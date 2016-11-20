#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pNetworkManager = new QNetworkAccessManager(this);

    connect(m_pNetworkManager, &QNetworkAccessManager::finished,[&](QNetworkReply * reply){
        QTextCodec *codec = QTextCodec::codecForName("utf8");
        QString all = codec->toUnicode(reply->readAll());
        ui->textBrowser->setText(all);
        reply->deleteLater();
    });

    m_pNetworkManager->get(QNetworkRequest(QUrl("http://www.qter.org")));
}

MainWindow::~MainWindow()
{
    delete ui;
}
