#pragma  once
#include "IWebViewInterface.h"
#include <QWebPage>

class CQWebPage : public QWebPage
{
	Q_OBJECT

public:
    CQWebPage(QWidget *parent);
    ~CQWebPage();
    void SetUrl(const QUrl& url);
    inline void InstallNavigateCallBack(IWebViewNavigator* navigator){ m_INavigator = navigator;}

protected:
	virtual bool acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request, QWebPage::NavigationType type);

private:
    IWebViewNavigator* m_INavigator;
};
