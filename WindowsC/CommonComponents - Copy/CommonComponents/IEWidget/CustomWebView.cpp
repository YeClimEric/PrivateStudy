#include "CustomWebView.h"
#include <QNetworkAccessManager>
#include <QNetworkDiskCache>
#include <QDesktopServices>

CCustomWebView::CCustomWebView(QWidget *parent)
	: QWebView(parent),
	m_pNetManager(new QNetworkAccessManager(this)),
	m_pDiskCache(new QNetworkDiskCache(this)),
	m_pWebPage(new CCustomWebPage(this))
{
	Init();
}

CCustomWebView::~CCustomWebView()
{

}

QWebView* CCustomWebView::createWindow(QWebPage::WebWindowType type)
{
	return this;
}

void CCustomWebView::Init()
{
	InitPage();
	InitWebSetting();
}

void CCustomWebView::InitWebSetting()
{
	//���ü���Flash���
	settings()->setAttribute(QWebSettings::PluginsEnabled,true);
	settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
	//����֧��js
	settings()->setAttribute(QWebSettings::JavaEnabled, true);
	settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
	settings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard, true);
	//���û���
	m_pNetManager = page()->networkAccessManager();
#if QT_VERSION >= 0x500000
	QString location = QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
#else
	QString location = QDesktopServices::storageLocation(QDesktopServices::CacheLocation);
#endif
	m_pDiskCache->setCacheDirectory(location);
	m_pNetManager->setCache(m_pDiskCache);
	page()->setNetworkAccessManager(m_pNetManager);
	page()->settings()->setMaximumPagesInCache(10);
	page()->settings()->setAttribute(QWebSettings::AutoLoadImages, true);
	page()->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
	page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
}

void CCustomWebView::InitPage()
{
	this->setPage(m_pWebPage);
}

