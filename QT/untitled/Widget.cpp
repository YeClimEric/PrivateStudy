#include "Widget.h"
#include "ui_Widget.h"

#include <QDebug>
#include <QShowEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showEvent(QShowEvent *e)
{
    qDebug()<<"SHowEvent:"<< isVisible();
}

bool Widget::event(QEvent *event)
{
    qDebug()<<windowState();
    return true;
}
