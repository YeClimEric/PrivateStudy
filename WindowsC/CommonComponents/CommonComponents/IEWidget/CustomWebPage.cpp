#include "CustomWebPage.h"
#include <QNetworkRequest>

CCustomWebPage::CCustomWebPage(QWidget *parent)
	: QWebPage(parent),
	m_IHelper(nullptr)
{

}

CCustomWebPage::~CCustomWebPage()
{

}

bool CCustomWebPage::acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request,QWebPage::NavigationType type)
{
	if (m_IHelper != nullptr)
	{
		return m_IHelper->Navigate(request.url());
	}
	else
	{
		return true;
	}
	
}
