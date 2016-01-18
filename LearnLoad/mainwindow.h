#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLineEdit>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QFontComboBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QRadioButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPlainTextEdit *plainEdit;
    QComboBox *comBox;
    QFontComboBox *fontComBox;
    QSpinBox *spinBox;
    QRadioButton* radioA, *radioB, *radioC;
    QHBoxLayout *layout;
    QWidget *widget;
};

#endif // MAINWINDOW_H
