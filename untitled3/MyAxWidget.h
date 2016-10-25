#ifndef MYAXWIDGET_H
#define MYAXWIDGET_H

#include <QWidget>
#include <QAxWidget>

class MyAxWidget: public QAxWidget
{
public:
    MyAxWidget(QWidget* parent = Q_NULLPTR);

protected:
    void paintEvent(QPaintEvent *e);
    void focusOutEvent(QFocusEvent* e);
public slots:
    void flashAction( const QString & name, int argc, void * argv );
};

#endif // MYAXWIDGET_H
