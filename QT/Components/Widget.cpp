#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //ui->label->SetElideMode(Qt::TextElideMode::ElideMiddle);
    //ui->label->SetTextLength(70);


    ui->label->SetTextDirection(CQLabel::TextDirection::Vertical);
    ui->label->SetText("Hello World");
    ui->label->SetScrollType(CQLabel::SCrollType::Vertical_BT);
    ui->label->SetScrollState(true);


//    ui->label->setFrameStyle(QFrame::HLine);
//    ui->label->setWordWrap(true);
//    ui->label->setAlignment(Qt::AlignTop);
//    QString s = "测试abcdefg word";
//    ui->label->setText(s.split("", QString::SkipEmptyParts).join("\n"));
}

Widget::~Widget()
{
    delete ui;
}
