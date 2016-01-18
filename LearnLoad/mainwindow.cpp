#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QFileInfo>
#include <QDataStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);





//    radioA = new QRadioButton("A");
//    radioB = new QRadioButton("V");
//    radioC = new QRadioButton("C");

//    radioA->setText("A");
//    radioB->setText("B");
//    radioC->setText("C");

//    radioA->setChecked(true);
//    layout = new QHBoxLayout();
//    layout->addWidget(radioA);
//    layout->addWidget(radioB);
//    layout->addWidget(radioC);
//    layout->setSpacing(60);
//    widget = new QWidget();

//    widget->setLayout(layout);
//    this->setCentralWidget(widget);


//    spinBox = new QSpinBox(this);
//    spinBox->setRange(0,100);
//    spinBox->setValue(20);
//    spinBox->setPrefix("$");
//    spinBox->setSuffix("dollor");

//    fontComBox = new QFontComboBox(this);
//    fontComBox->setGeometry(50,50,100,20);



//    comBox = new QComboBox(this);
//    comBox->setGeometry(QRect(50,50,100,25));
//    QStringList strList;
//    strList << "hello" <<"world"<<"ai";
//    comBox->addItems(strList);

//    lineEdit = new QLineEdit(this);
//    lineEdit->setGeometry(50,50,100,20);
//    lineEdit->setStyleSheet("border:1px;border-style:solid;color:red;border-color: bluered;");
//    lineEdit->setMaxLength(12);
//    lineEdit->setEchoMode(QLineEdit::Password);

//    textEdit = new QTextEdit(this);
//    textEdit->setGeometry(QRect(50,50,200,150));
//    textEdit->setText("<h1>001<h1/><h3>002<h3/>");

//    plainEdit = new QPlainTextEdit(this);
//    plainEdit->setGeometry(QRect(50,50,300,200));
//    plainEdit->setPlainText("<p>hah</p>aa");

//    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置背景透明
//    this->setAttribute(Qt::WA_TranslucentBackground, true);
//    this->setStyleSheet("");



//    QString fileName("E:/Github/Qt/LearnLoad/TASCEmail.ini");
//    if(!QFile::exists(fileName))
//        QMessageBox::information(this, "info","not exist!");
//    QFile file(fileName);

//    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
//        QMessageBox::information(this, "info", "open file failed");
//    else
//        while(!file.atEnd()){
//            qDebug(file.readLine());
//        }
//    QDataStream out(&file);
//    out<<"hello world";
//    file.close();
//    QFileInfo info(file);
//    qDebug()<<info.absolutePath();
}

MainWindow::~MainWindow()
{
    delete ui;
}
