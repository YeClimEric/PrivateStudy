#pragma  once

#include <QWebView>
#include <QWidget>
#include <QWebFrame>
#include "CQWebPage.h"

class QNetworkDiskCache;
class QNetworkReply;

class CQWebView : public QWebView
{
	Q_OBJECT

public:
    CQWebView(QWidget *parent);
    ~CQWebView();
    void SetUrl(const QUrl& url);
    void RunJavaScript(const QString &js);
    inline void InstallNavigateCallBack(IWebViewNavigator* navigator){ m_pWebPage->InstallNavigateCallBack(navigator);}
	QWebView* createWindow(QWebPage::WebWindowType type);

private:
	void Init();
	void InitWebSetting();
	void InitPage();

private:
	QNetworkDiskCache* m_pDiskCache;
    CQWebPage* m_pWebPage;
};
