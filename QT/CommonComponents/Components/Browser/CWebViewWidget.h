#ifndef CWEBVIEWWIDGET_H
#define CWEBVIEWWIDGET_H

#include <QWidget>

class QWebPage;
class QWebFrame;
class QWebView;
class QNetworkDiskCache;
class QNetworkAccessManager;


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
    QWebView *GetWebView();

signals:
    void LinkClicked(const QUrl& url);
    void LoadFinished(bool ok);
    void LoadProgress(int progress);
    void LoadStarted();
    void URLChanged(const QUrl& url);

private:
    void Init();
    void InitSignals();
    void InitWebSetting();

private:
    Ui::CWebViewWidget *ui;
    QNetworkDiskCache *m_pDiskCache;
    QNetworkAccessManager *m_pNetworkManager;
};

#endif // CWEBVIEWWIDGET_H
