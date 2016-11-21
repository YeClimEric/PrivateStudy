#include "widget.h"
#include "ui_widget.h"
#include <QPoint>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint |Qt::Window);
    setAttribute(Qt::WA_TranslucentBackground);
    m_pAnimation = new QPropertyAnimation(this);
    m_pAnimation->setStartValue(QPoint(0,300));
    m_pAnimation->setEndValue(QPoint(1000, 300));
    m_pAnimation->setDuration(5*1000);
    m_pAnimation->setDirection(QAbstractAnimation::Forward);

    bool ret = connect(m_pAnimation, &QPropertyAnimation::valueChanged,[&](const QVariant &value){
        QPoint pos = value.toPoint();
        this->move(pos);
    });
    m_pAnimation->start();
}

Widget::~Widget()
{
    delete ui;
}
