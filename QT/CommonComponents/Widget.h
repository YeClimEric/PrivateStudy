#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QApplication& app, QWidget *parent = 0);
    ~Widget();

private:
    void LoadStyleSheet(QString sSuffix="");

private:
    Ui::Widget *ui;
    QApplication& m_App;

    QString m_sRccFile;
};

#endif // WIDGET_H
