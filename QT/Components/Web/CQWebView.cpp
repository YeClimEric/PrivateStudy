#include "CQWebView.h"
#include <QNetworkAccessManager>
#include <QNetworkDiskCache>
#include <QDesktopServices>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "CNetWorker.h"

CQWebView::CQWebView(QWidget *parent)
    : QWebView(parent),
	m_pDiskCache(new QNetworkDiskCache(this)),
    m_pWebPage(new CQWebPage(this))
{
	Init();
}

CQWebView::~CQWebView()
{

}

void CQWebView::SetUrl(const QUrl &url)
{
    setUrl(url);
}

void CQWebView::RunJavaScript(const QString &js)
{
    m_pWebPage->mainFrame()->evaluateJavaScript(js);
}

QWebView* CQWebView::createWindow(QWebPage::WebWindowType type)
{
	return this;
}

void CQWebView::Init()
{
	InitPage();
	InitWebSetting();
}

void CQWebView::InitWebSetting()
{
    //¼ÓÔØFlash
	settings()->setAttribute(QWebSettings::PluginsEnabled,true);
	settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    //js
	settings()->setAttribute(QWebSettings::JavaEnabled, true);
	settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
	settings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard, true);

#if ( QT_VERSION >= QT_VERSION_CHECK(5,0,0) )
	QString location = QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
#else
	QString location = QDesktopServices::storageLocation(QDesktopServices::CacheLocation);
#endif
	m_pDiskCache->setCacheDirectory(location);
    CNetWorker::Instance()->GetNetWorkManager()->setCache(m_pDiskCache);
    page()->setNetworkAccessManager(CNetWorker::Instance()->GetNetWorkManager());
	page()->settings()->setMaximumPagesInCache(10);
	page()->settings()->setAttribute(QWebSettings::AutoLoadImages, true);
	page()->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
	page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
}

void CQWebView::InitPage()
{
	this->setPage(m_pWebPage);
}

