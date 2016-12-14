#include "commoncomponents.h"

#include "IEWidget/CustomWebView.h"
#include <QDebug>

CommonComponents::CommonComponents(QWidget *parent, Qt::WindowFlags flags)
	: QWidget(parent, flags),
	m_pWebView(new CCustomWebView(this))
{
	ui.setupUi(this);
	m_pWebView->resize(this->width(), this->height());
	m_pWebView->load(QUrl(QString("http://client.qxiu.com/hall/hall.html?openid=DCF65DF181ECABE99999FFDDA1721355&openkey=A346D66B8C2869B3E004FFD10CC99AD6&userId=45777564&ver=1.22.22.22")));
	m_pWebView->show();
	m_pWebView->InstallNavigateCallBack(this);
}

CommonComponents::~CommonComponents()
{
	delete m_pWebView;
	m_pWebView = nullptr;
}

bool CommonComponents::Navigate(const QUrl& url)
{
	return true;
}