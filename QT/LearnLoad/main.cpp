#include "mainwindow.h"
#include <QApplication>
#include <QStringListModel>
#include <QListView>
#include <QStringList>

#include <QFileSystemModel>
#include <QTreeView>
#include <QHeaderView>
#include <QDir>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//    QFileSystemModel* model = new QFileSystemModel(&w);
//    model->setRootPath(QDir::currentPath());
//    QTreeView *treeView = new QTreeView(&w);
//    treeView->setModel(model);
//    treeView->setRootIndex(model->index(QDir::currentPath()));
//    treeView->setGeometry(20,20,300,300);

//    treeView->header()->setStretchLastSection(true);
//    treeView->header()->setSortIndicator(0, Qt::AscendingOrder);
//    treeView->header()->setSortIndicatorShown(true);

//    QStringListModel test
    QStringList data;
    data << "aa"<<"bb" <<"cc"<<"dd";
    QStringListModel *model = new QStringListModel(&w);
    model->setStringList(data);

    QListView *listView = new QListView(&w);
    listView->setModel(model);
    listView->setItemDelegate(new SpinBoxDelegate());
    listView->setGeometry(100,100,200,200);




    w.show();

    return a.exec();
}
