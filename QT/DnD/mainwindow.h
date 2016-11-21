#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

#include <QDragEnterEvent>
#include <QMimeData>
#include <QDropEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
//    Ui::MainWindow *ui;
    bool readFile(const QString &fileName);
    QTextEdit* textEdit;
};

#endif // MAINWINDOW_H
