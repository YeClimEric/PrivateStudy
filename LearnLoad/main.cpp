#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QTimeEdit>
#include <QScrollBar>

#include <QRadioButton>
#include <QLabel>

#include <QListView>
#include <QStringListModel>
#include <QHBoxLayout>
#include <QCheckBox>


//#define QT_NO_STYLE_STYLESHEET


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    QTextEdit aa(&w);
//    aa.setStyleSheet(QString("d:\style.css"));
//    aa.setStyleSheet("width:100px");


//    QListView listView(&w);
//    listView.setGeometry(50,50,100,100);
//    QStringList strList;
//    strList<< "A" <<"B" <<"C";
//    QStringListModel model(strList);e
//    listView.setModel(&model);




//    QScrollBar scrollBar(&w);
//    scrollBar.setGeometry(50,50,500,30);
//    scrollBar.setOrientation(Qt::Horizontal);
//    QLabel label(&w);
//    label.setGeometry(100,100,200,300);

//    QRadioButton radioA(&w), radioB, radioC;
//    radioA.setGeometry(50,50,50,50);
//    radioB.setGeometry(100,50,50,50);
//    radioC.setGeometry(150,50,50,50);
//    QRadioButton* radioA = new QRadioButton();
//    QRadioButton* radioB = new QRadioButton();
//    QRadioButton* radioC = new QRadioButton();

//    radioA->setText("A");
//    radioB->setText("B");
//    radioC->setText("C");

//    radioA->setChecked(true);
//    QHBoxLayout *layout = new QHBoxLayout();
//    layout->addWidget(radioA);
//    layout->addWidget(radioB);
//    layout->addWidget(radioC);
//    layout->setSpacing(60);
//    w.setLayout(layout);

//    QTimeEdit timeEdit(&w);
//    timeEdit.setGeometry(50,50,100,30);
//    QDateTime sysTime = QDateTime::currentDateTime();

//    QStringList list = sysTime.toString("hh:mm:ss").split(":");
//    timeEdit.setTime(QTime(list[0].toInt(),list[1].toInt(), list[2].toInt()));
//    QPushButton btn(&w);
//    btn.setGeometry(500,500,50,50);
//    btn.setText("hello");
    w.show();

    return a.exec();
}
