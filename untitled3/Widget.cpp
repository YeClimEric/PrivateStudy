#include "Widget.h"
#include "ui_Widget.h"

#include <QPainter>
#include <QBrush>
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    flash = new QAxWidget(0,0);
    flash->resize(500,300);
    flash->setControl(QString::fromUtf8("{d27cdb6e-ae6d-11cf-96b8-444553540000}"));
    bool ret = connect(flash,SIGNAL(FlashCall(QString)),this,SLOT(flashAction(QString))); //用于处理FLASH传来的字符串
    qDebug()<<"connect return:"<<ret;
    flash->dynamicCall("LoadMovie(long,string)",0,"E:/RemoteDataBase/QiJu/code/trunk/beta/client/Flash/GiftEffect/BearCards.swf"); //调用方法
    timerID = 0;
//    timerID = startTimer(2*1000);



    flash->show();
}

Widget::~Widget()
{
    delete ui;
    delete flash;
}

void Widget::paintEvent(QPaintEvent *e)
{
//    QPainter p(this);
//    p.setCompositionMode( QPainter::CompositionMode_Source );
//    p.setBrush(QBrush(QColor(0,0,0,255)));
    //    p.fillRect( 0, 0, 50, 50, Qt::SolidPattern);
}

void Widget::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == timerID){
//        ui->textBrowser->setText(flash->generateDocumentation());
//        qDebug()<<"Hello";
//        QVariant ret2 =  flash->dynamicCall( "showBuyNobleMessage",str);//设置属性
        killTimer(timerID);
//        qDebug()<< ss;
//        QString str;
//        QTextStream(&str)<<"<invoke name=\"showBuyNobleMessage\" returntype=\"xml\">"
//                        <<"<arguments>"
//                       <<"<string> "
//                      <<"Hello"
//                     <<"</string>"
//                    <<"<string> "
//                   <<"22"
//                  <<"</string>"
//                 <<"</arguments> "
//                <<"</invoke>"
//                        ;
//        QVariant ret2 =  flash->dynamicCall( "showBuyNobleMessage",str);//设置属性
//        qDebug()<<"dynamicCall return:"<<ret2.toString();
    }
}

void Widget::flashAction(QString aa)
{
    qDebug()<<"aa:"<<aa;
}
