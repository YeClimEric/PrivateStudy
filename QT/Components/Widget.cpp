#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
     m_pWebview(new CQWebView(this))
{
    ui->setupUi(this);
    //ui->label->SetElideMode(Qt::TextElideMode::ElideMiddle);
    //ui->label->SetTextLength(70);


//    ui->label->SetTextDirection(CQLabel::TextDirection::Vertical);
//    ui->label->SetText("Hello World");
//    ui->label->SetScrollType(CQLabel::SCrollType::Vertical_BT);
//    ui->label->SetScrollState(true);

    m_pWebview->InstallNavigateCallBack(this);
    ui->mainLayout->addWidget(m_pWebview);
    m_pWebview->SetUrl(QUrl(QString("http://www.sina.com")));
    m_pWebview->show();
//    ui->webView->setUrl(QUrl(QString("http://www.sina.com")));

//    ui->label->setFrameStyle(QFrame::HLine);
//    ui->label->setWordWrap(true);
//    ui->label->setAlignment(Qt::AlignTop);
//    QString s = "测试abcdefg word";
//    ui->label->setText(s.split("", QString::SkipEmptyParts).join("\n"));
}

Widget::~Widget()
{
    delete ui;
    m_pWebview->deleteLater();
}

bool Widget::Navigate(const QUrl &url)
{
    return true;
}
