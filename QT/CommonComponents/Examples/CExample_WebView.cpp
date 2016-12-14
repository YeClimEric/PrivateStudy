#include "CExample_WebView.h"
#include <QDebug>

CExample_WebView::CExample_WebView(QWidget *parent) :
    QWidget(parent)
{
    m_pWebview = new CCustomWebView(this);
    m_pWebview->setFixedSize(1024,768);
}

void CExample_WebView::LoadUrl(const QString &url)
{
    m_pWebview->load(url);
}

bool CExample_WebView::Navigate(const QUrl &url)
{
    qDebug()<<url;
    return true;
}
