#include "CCustomWebControl.h"

#include <QMessageBox>
#include <QUrl>
#include <QDebug>
#include <QLayout>
#include <QWebPage>

CCustomWebControl::CCustomWebControl(QWidget *parent) : QWidget(parent)
{
    m_pMainLayout = new QVBoxLayout();
    this->setLayout(m_pMainLayout);

    m_pWebView = new QWebView(this);
    m_pMainLayout->addWidget(m_pWebView);
    connect(m_pWebView, &QWebView::loadStarted,[](){
        qDebug()<<"load Started";
    });

}

void CCustomWebControl::SetShowUrl(const QString &url)
{
    if(m_pWebView != nullptr)
    {
        m_pWebView->load(QUrl(url));
    }
    connect(m_pWebView->page(),&QWebPage::linkClicked, [](const QUrl & url ){
        qDebug()<<"LinkClicked:"<<url.toString();
    });
}
