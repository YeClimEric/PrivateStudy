#pragma once

#include <QMouseEvent>
#include <QUrl>

class IWebViewNavigator
{
public:
	virtual bool Navigate(const QUrl& url) = 0;
};

class IWebViewMouseEvent
{
public:
    virtual void  mouseDoubleClickEvent(QMouseEvent * ev) = 0;
    virtual void  mouseMoveEvent(QMouseEvent * ev) = 0;
    virtual void  mousePressEvent(QMouseEvent * ev) = 0;
    virtual void  mouseReleaseEvent(QMouseEvent * ev) = 0;
    virtual void  wheelEvent(QWheelEvent * ev) = 0;
};

class IWebViewDragEvent
{
public :
    virtual void  dragEnterEvent(QDragEnterEvent * ev) = 0;
    virtual void  dragLeaveEvent(QDragLeaveEvent * ev) = 0;
    virtual void  dragMoveEvent(QDragMoveEvent * ev) = 0;
    virtual void  dropEvent(QDropEvent * ev) = 0;
};

class IWebViewKeyEvent
{
    virtual void	focusInEvent(QFocusEvent * ev) = 0;
    virtual bool	focusNextPrevChild(bool next) = 0;
    virtual void	focusOutEvent(QFocusEvent * ev) = 0;
    virtual void	inputMethodEvent(QInputMethodEvent * e) = 0;
    virtual void	keyPressEvent(QKeyEvent * ev) = 0;
    virtual void	keyReleaseEvent(QKeyEvent * ev) = 0;
};

class IWebViewControl: public IWebViewNavigator,
        public IWebViewMouseEvent,
        public IWebViewKeyEvent,
        public IWebViewDragEvent
{
public:

};

