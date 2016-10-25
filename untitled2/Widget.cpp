#include "Widget.h"
#include "ui_Widget.h"

#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint | Qt::Window);

    setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter p(this );
    p.setCompositionMode( QPainter::CompositionMode_Clear );
    p.fillRect( 0, 0, 300, 300, Qt::NoBrush );
}
