#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPropertyAnimation>

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
    QPropertyAnimation* m_pAnimation;
};

#endif // WIDGET_H
