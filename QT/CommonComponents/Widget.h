#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Examples/CExample_WebView.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QApplication& app, QWidget *parent = 0);
    ~Widget();

private:
    void LoadStyleSheet(QString sSuffix="");

private slots:
    void sl_WebViewExample();

private:
    Ui::Widget *ui;
    QApplication& m_App;

    QString m_sRccFile;

    CExample_WebView* m_pWebViewWidget;
};

#endif // WIDGET_H
