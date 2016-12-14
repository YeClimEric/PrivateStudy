#pragma  once

#include <QWebView>
#include <QWidget>
#include <QWebFrame>
#include "CustomWebPage.h"

class QNetworkAccessManager;
class QNetworkDiskCache;

class CCustomWebView : public QWebView
{
	Q_OBJECT

public:
	CCustomWebView(QWidget *parent);
	~CCustomWebView();
    void RunJavaScript(const QString &js);
	inline void InstallNavigateCallBack(IWebViewHelper* helper){ m_pWebPage->InstallNavigateCallBack(helper);}
	QWebView* createWindow(QWebPage::WebWindowType type);

private:
	void Init();
	void InitWebSetting();
	void InitPage();

private:
	QNetworkAccessManager* m_pNetManager;
	QNetworkDiskCache* m_pDiskCache;
	CCustomWebPage* m_pWebPage;
	
};
