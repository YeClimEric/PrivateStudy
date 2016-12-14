#pragma once

#include <QWidget>
#include "IWebViewHelper.h"
#include "Components/Browser/CustomWebView.h"

class CExample_WebView : public QWidget, public IWebViewHelper
{
    Q_OBJECT
public:
    explicit CExample_WebView(QWidget *parent = 0);
    void LoadUrl(const QString& url);
    virtual bool Navigate(const QUrl &url);

signals:

public slots:

private:
    CCustomWebView* m_pWebview;

};
