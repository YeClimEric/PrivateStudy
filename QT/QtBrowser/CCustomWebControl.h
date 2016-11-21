#ifndef CCUSTOMWEBCONTROL_H
#define CCUSTOMWEBCONTROL_H

#include <QWidget>
#include <QWebView>
#include <QVBoxLayout>

class CCustomWebControl : public QWidget
{
    Q_OBJECT
public:
    explicit CCustomWebControl(QWidget *parent = 0);

    void SetShowUrl(const QString &url);

signals:


private:
    QVBoxLayout *m_pMainLayout;
    QWebView* m_pWebView;
};

#endif // CCUSTOMWEBCONTROL_H
