#ifndef COMMONCOMPONENTS_H
#define COMMONCOMPONENTS_H

#include <QWidget>
#include "ui_commoncomponents.h"
#include "IWebViewHelper.h"

class CCustomWebView;

class CommonComponents : public QWidget, public IWebViewHelper
{
	Q_OBJECT

public:
	CommonComponents(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~CommonComponents();

	virtual bool Navigate(const QUrl& url);
private:
	Ui::CommonComponentsClass ui;
	CCustomWebView* m_pWebView;
};

#endif // COMMONCOMPONENTS_H
