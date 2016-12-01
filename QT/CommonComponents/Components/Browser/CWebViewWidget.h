#ifndef CWEBVIEWWIDGET_H
#define CWEBVIEWWIDGET_H

#include <QWidget>

class QWebPage;
class QWebFrame;

namespace Ui {
class CWebViewWidget;
}

class CWebViewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CWebViewWidget(QWidget *parent = 0);
    ~CWebViewWidget();

    void SetUrl(const QString& url);
    void RunJavaScript(const QString &js);

protected:
    QWebPage *GetPage();
    QWebFrame *GetFrame();

signals:
    void LinkClicked(const QUrl& url);
    void LoadFinished(bool ok);
    void LoadProgress(int progress);
    void LoadStarted();
    void URLChanged(const QUrl& url);

private:
    void Init();

private:
    Ui::CWebViewWidget *ui;
};

#endif // CWEBVIEWWIDGET_H
