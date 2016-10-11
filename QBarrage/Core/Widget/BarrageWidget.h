#ifndef BARRAGEWIDGET_H
#define BARRAGEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

#include "WidgetBase.h"

class CBarrageAnimation;
class CComponentBase;
class CDataBase;

class CBarrageWidget : public CWidgetBase
{
    Q_OBJECT
public:
    explicit CBarrageWidget(QWidget* parent, QString asComponentName = "CBarrageComponentBase");
    ~CBarrageWidget();


    void start();
    void pause();
    void stop();

    void onShow(bool abShow);
    void onMove();

    inline void setBarrageLineCount(int aiLine){ m_iLineCount = aiLine; }
    inline void setBarrageIntervalLength(int aiInterval){ m_iBarrageIntervalLength = aiInterval; }

public slots:
    virtual void onCurrentValueChanged(const QVariant  &val);
    void onAppendAnimation(QWidget* parent);

private:
    void addAnimationToQueue(CBarrageAnimation* apAnimation);
    int getCurrentShowBarrageWdgCount();
    QWidget* getNullChildLineWdg();


private:
    QWidget *m_parentClass;
    bool m_barrageState;
    QSize m_parentSize;

    QVBoxLayout* m_pMainLayout;
    QList<QWidget*> m_lsDisplayLine;

    int m_iLineCount;
    int m_iBarrageIntervalLength;
};

#endif // BARRAGEWIDGET_H
