#include "widget.h"
#include "ui_widget.h"



#include <QClipboard>
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),/*,
    ui(new Ui::Widget)*/
  mainLayout(new QVBoxLayout(this)),
  northLayout(new QHBoxLayout(this)),
  sourthLayout(new QHBoxLayout(this)),
  editor(new QTextEdit),
  label(new QLabel),
  copyBtn(new QPushButton),
  pasteBtn(new QPushButton)
{
//    ui->setupUi(this);

    label->setText("Text Input: ");
    label->setBuddy(editor);


    copyBtn->setText("set Clipboard");

    pasteBtn->setText("get Clipboard");

    northLayout->addWidget(label);
    northLayout->addWidget(editor);
    sourthLayout->addWidget(copyBtn);
    sourthLayout->addWidget(pasteBtn);
    mainLayout->addLayout(northLayout);
    mainLayout->addLayout(sourthLayout);

    connect(copyBtn, &QPushButton::clicked, this, &Widget::setClipboardContent);
    connect(pasteBtn, &QPushButton::clicked, this, &Widget::getClopboardContent);
}

Widget::~Widget()
{
    //    delete ui;
}

void Widget::setClipboardContent()
{
    QClipboard* board = QApplication::clipboard();
    board->setText(editor->toPlainText());

}

void Widget::getClopboardContent()
{
    QClipboard* board = QApplication::clipboard();
    QString str = board->text();
    QMessageBox::information(NULL, "From Clipboard", str);

}
