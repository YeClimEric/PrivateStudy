#pragma once

#include <QUrl>

class IWebViewHelper
{
public:
	virtual bool Navigate(const QUrl& url) = 0;
};

