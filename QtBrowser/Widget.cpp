#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_pControl = new CCustomWebControl(this);
    ui->verticalLayout->addWidget(m_pControl);
    m_pControl->SetShowUrl("http://client.qxiu.com/hall/hall.html?openid=DCF65DF181ECABE99999FFDDA1721355&openkey=A346D66B8C2869B3E004FFD10CC99AD6&userId=45777564");
}

Widget::~Widget()
{
    delete ui;
}
