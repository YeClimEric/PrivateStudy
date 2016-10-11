#ifndef CGIFTWIDGET_H
#define CGIFTWIDGET_H

#include <QWidget>
#include "WidgetBase.h"

class CGiftWidget : public CWidgetBase
{
public:
    explicit CGiftWidget(QWidget* parent, QString asComponentName = "CGiftComponent");
    ~CGiftWidget();
};

#endif // CGIFTWIDGET_H
