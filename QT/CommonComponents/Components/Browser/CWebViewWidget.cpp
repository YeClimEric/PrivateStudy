#include "CWebViewWidget.h"
#include "ui_CWebViewWidget.h"

#include <QWebPage>
#include <QWebFrame>
#include <QNetworkAccessManager>
#include <QNetworkDiskCache>
#include <QStandardPaths>
#include <QUrl>
#include <QDebug>


CWebViewWidget::CWebViewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWebViewWidget),
    m_pDiskCache(new QNetworkDiskCache(this)),
    m_pNetworkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    Init();

    qDebug()<<QApplication::applicationVersion();
}

CWebViewWidget::~CWebViewWidget()
{
    delete ui;
}

void CWebViewWidget::SetUrl(const QString &url)
{
    ui->webView->setUrl(QUrl(url));
}

void CWebViewWidget::RunJavaScript(const QString &js)
{
    GetFrame()->evaluateJavaScript(js);
}

QWebPage *CWebViewWidget::GetPage()
{
    return ui->webView->page();
}

QWebFrame *CWebViewWidget::GetFrame()
{
    return GetPage()->mainFrame();
}

QWebView *CWebViewWidget::GetWebView()
{
    return ui->webView;
}

void CWebViewWidget::Init()
{
    InitSignals();
    InitWebSetting();
}

void CWebViewWidget::InitSignals()
{
    GetPage()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    connect(ui->webView, &QWebView::loadStarted,[&](){
        GetPage()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
        emit LoadStarted();
    });
    connect(ui->webView, &QWebView::loadFinished,[&](bool ok){
        emit LoadFinished(ok);
    });
    connect(ui->webView, &QWebView::loadProgress,[&](int progress){
        emit LoadProgress(progress);
    });
    connect(ui->webView, &QWebView::urlChanged,[&](const QUrl& url){
        emit URLChanged(url);
    });
    connect(ui->webView, &QWebView::linkClicked, [&](const QUrl& url){
        qDebug()<<url;
        emit LinkClicked(url);
    });
}

void CWebViewWidget::InitWebSetting()
{
    //开启缓存
    m_pNetworkManager = GetPage()->networkAccessManager();
    QString location = QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
    m_pDiskCache->setCacheDirectory(location);
    m_pNetworkManager->setCache(m_pDiskCache);
    GetPage()->setNetworkAccessManager(m_pNetworkManager);
    GetPage()->settings()->setMaximumPagesInCache(10);
    GetPage()->settings()->setAttribute(QWebSettings::AutoLoadImages,true);
    GetPage()->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    //开启网页插件、开启js
    QWebSettings *settings = QWebSettings::globalSettings();
    settings->setAttribute(QWebSettings::PluginsEnabled, true);
    settings->setAttribute(QWebSettings::JavaEnabled, true);
    settings->setAttribute(QWebSettings::JavascriptEnabled, true);
    settings->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    settings->setAttribute(QWebSettings::JavascriptCanCloseWindows, true);
    settings->setFontFamily(QWebSettings::SansSerifFont,"SansSerifFont");

}
