#include "CWebViewWidget.h"
#include "ui_CWebViewWidget.h"

#include <QtWebKitWidgets/QWebPage>
#include <QtWebKitWidgets/QWebFrame>
#include <QUrl>
#include <QDebug>

CWebViewWidget::CWebViewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWebViewWidget)
{
    ui->setupUi(this);
    Init();
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

void CWebViewWidget::Init()
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
