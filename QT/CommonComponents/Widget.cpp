#include "Widget.h"
#include "ui_Widget.h"
#include <QApplication>
#include <QResource>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QComboBox>

#include <QStringList>
#include <QFileDialog>


Widget::Widget(QApplication& app, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_App(app),
    m_pWebViewWidget(new CExample_WebView())
{
    m_sRccFile = QApplication::applicationDirPath() + QString("/Resource/Skins.rcc");
    if(!QFile::exists(m_sRccFile))
    {
        //QMessageBox::information(this,"Information","no rcc file");
    }
    QResource::registerResource(m_sRccFile);
    LoadStyleSheet();

    ui->setupUi(this);
    ui->SkinComBox->setMaxCount(3);
    ui->SkinComBox->insertItem(0,"Blue");
    ui->SkinComBox->insertItem(1,"Dark");
    ui->SkinComBox->insertItem(2,"Green");
    qDebug()<<"Application:"<<m_App.styleSheet();

    connect(ui->SkinComBox, &QComboBox::currentTextChanged,[&](QString s){
        LoadStyleSheet(s);
    });

#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
    connect(ui->webviewExp, &QPushButton::clicked, this, &Widget::sl_WebViewExample);
#else
    connect(ui->webviewExp, SIGNAL(clicked(),this, SLOT(sl_WebViewExample());
#endif
}

Widget::~Widget()
{
    QResource::unregisterResource(m_sRccFile);
    m_App.setStyleSheet("");
    delete ui;
}

void Widget::LoadStyleSheet(QString sSuffix)
{
    QString sQssFile;
    if(sSuffix.isEmpty()){
        sQssFile = QString(":/qss/images/Skins.qss");
    }
    else{
        sQssFile = QString(":/qss/images_%1/Skins.qss").arg(sSuffix);
    }

    if (!QFile::exists(sQssFile)){
        QMessageBox::information(this, "Information","no qss file");
    }
    QFile loFile(sQssFile);
    if(loFile.open(QFile::ReadOnly))
    {
       QString strData = QString::fromUtf8(loFile.readAll());
       m_App.setStyleSheet(strData);
    }
    else{
        QMessageBox::information(this,"information","open file failed");
    }
    loFile.close();
}

void Widget::sl_WebViewExample()
{
    if(m_pWebViewWidget != nullptr){
        qDebug()<<"Load...";
        m_pWebViewWidget->LoadUrl("http://client.qxiu.com/hall/hall.html?");
        m_pWebViewWidget->show();
    }
}
