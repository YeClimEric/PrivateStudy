#pragma  once
#include "IWebViewHelper.h"
#include <QWebPage>

class CCustomWebPage : public QWebPage
{
	Q_OBJECT

public:
	CCustomWebPage(QWidget *parent);
	~CCustomWebPage();
	inline void InstallNavigateCallBack(IWebViewHelper* helper){ m_IHelper = helper;}

protected:
	virtual bool acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request, QWebPage::NavigationType type);

private:
	IWebViewHelper* m_IHelper;	
};
