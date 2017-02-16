#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Label/CQLabel.h"

#include "Web/IWebViewInterface.h"
#include "Web/CQWebView.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget, public IWebViewNavigator
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    virtual bool Navigate(const QUrl& url);

private:
    Ui::Widget *ui;
    CQWebView* m_pWebview;
};

#endif // WIDGET_H
