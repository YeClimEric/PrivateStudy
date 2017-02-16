#include "CQWebPage.h"
#include <QNetworkRequest>
#include <QWebFrame>

CQWebPage::CQWebPage(QWidget *parent)
	: QWebPage(parent),
    m_INavigator(nullptr)
{

}

CQWebPage::~CQWebPage()
{

}

void CQWebPage::SetUrl(const QUrl &url)
{
    this->currentFrame()->setUrl(url);
}

bool CQWebPage::acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request,QWebPage::NavigationType type)
{
    if (m_INavigator != nullptr)
	{
        return m_INavigator->Navigate(request.url());
	}
	else
	{
		return true;
	}
	
}
