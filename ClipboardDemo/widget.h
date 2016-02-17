#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void setClipboardContent();
    void getClopboardContent();

private:
//    Ui::Widget *ui;
    QTextEdit* editor;
    QVBoxLayout* mainLayout;
    QHBoxLayout* northLayout;
    QHBoxLayout* sourthLayout;
    QLabel* label;// = new QLabel;
    QPushButton *copyBtn;// = new QPushButton;
    QPushButton *pasteBtn;// = new QPushButton;
};

#endif // WIDGET_H
