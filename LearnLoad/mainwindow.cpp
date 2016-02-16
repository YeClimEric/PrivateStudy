#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    label = new QLabel(this);
//    listWidget = new QListWidget(this);
//    listWidget->setGeometry(100,100,500,500);
//    QListWidgetItem* newItem = new QListWidgetItem;

//    QListWidgetItem* newItem2 = new QListWidgetItem;
//    newItem2->setText(tr("BB"));
//    listWidget->addItem(newItem2);

//    newItem->setText(tr("AA"));
//    listWidget->insertItem(1, newItem);

}

MainWindow::~MainWindow()
{
    delete ui;
}
