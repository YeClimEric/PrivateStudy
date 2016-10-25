#include "MyAxWidget.h"
#include <QPainter>
#include <QDebug>

MyAxWidget::MyAxWidget(QWidget* parent):
    QAxWidget(parent)
{
//    setAttribute(Qt::WA_TranslucentBackground);
//    setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint | Qt::Window);
    resize(300,100); //设置控件的大小
    setControl(QString::fromUtf8("{d27cdb6e-ae6d-11cf-96b8-444553540000}")); //注册控件
//    connect(this,SIGNAL(signal( const QString &, int, void *)),this, SLOT(flashAction(const QString &, int, void *)));
//    connect(this,SIGNAL(signal( const QString &, int, void *)),[&](const QString &name, int argc , void * argv){
//        qDebug()<<"name:"<<name;
//    });
    dynamicCall("LoadMovie(long,string)",0,"E:/RemoteDataBase/QiJu/code/trunk/beta/client/Flash/GiftEffect/BearCards.swf"); //调用方法

    //QString str2 = flash->dynamicCall("TotalFrames" ).toString();//获得属性
    //dynamicCall("FrameNum" , 200);//设置属性
//    dynamicCall("WMode", "Transparent");
}

void MyAxWidget::paintEvent(QPaintEvent *e)
{
    if(hasFocus())
    {
       qDebug()<<"has Focuse";
    }
    QPainter p(this );
//    p.setCompositionMode( QPainter::CompositionMode_Xor );
    p.setBrush(QBrush(QColor(255,0,255,0)));
    p.setPen(QPen(Qt::red));
    p.fillRect( 0, 0, 300, 500, Qt::SolidPattern);
    p.drawLine(0,0,100,100);
}

void MyAxWidget::focusOutEvent(QFocusEvent *e)
{
    qDebug()<<"out Focuse";
}

void MyAxWidget::flashAction(const QString &name, int argc, void *argv)
{
    qDebug()<<"name:"<<name;
}
