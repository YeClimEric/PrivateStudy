#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QList>
#include <QUrl>
#include <QFile>

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    //参见MIME手册
    if(event->mimeData()->hasFormat("text/uri-list"))
    {
        event->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if(urls.isEmpty())
    {
        return;
    }

    QString fileName = urls.first().toLocalFile();
    if(fileName.isEmpty())
        return;

    if(readFile(fileName)){
        setWindowTitle(tr("%1--%2").arg(fileName, tr("Drag File")));
    }

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)/*,
    ui(new Ui::MainWindow)*/
{
//    ui->setupUi(this);
    textEdit = new QTextEdit;
    setCentralWidget(textEdit);
    textEdit->setAcceptDrops(false);
    setAcceptDrops(true);
    setWindowTitle("Text　Editor");
}

MainWindow::~MainWindow()
{
//    delete ui;
}

bool MainWindow::readFile(const QString &fileName)
{
    bool r = false;
    QFile file(fileName);
    QString content;
    if(file.open(QIODevice::ReadOnly)){
         content = file.readAll();
         r = true;
    }
    textEdit->setText(content);
    return r;

}
