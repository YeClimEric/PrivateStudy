#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "MyAxWidget.h"
#include <QPalette>
#include <QVBoxLayout>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *e);
    void timerEvent(QTimerEvent* e);

protected slots:
    void flashAction(QString aa);

private:
    Ui::Widget *ui;
    QAxWidget *flash;
    QPalette palette;
    QVBoxLayout *m_pVBoxLayout;

    int timerID;
};

#endif // WIDGET_H
