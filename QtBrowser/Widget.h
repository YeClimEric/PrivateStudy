#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <CCustomWebControl.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    CCustomWebControl *m_pControl;
};

#endif // WIDGET_H
