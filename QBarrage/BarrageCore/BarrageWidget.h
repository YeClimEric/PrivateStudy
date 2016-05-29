#ifndef BARRAGEWIDGET_H
#define BARRAGEWIDGET_H

#include <QWidget>

class CBarrageAnimation;
class CBarrageComponentBase;
class CBDataBase;

class CBarrageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CBarrageWidget(QWidget* parent, QString asComponentName = "CBarrageComponentBase");
    ~CBarrageWidget();

    void OnMove();

    void start();
    void pause();
    void stop();

    void barrageStateChanged(bool on);
    void setSize(const QSize &size);

    void setCompBackground(const QColor &color);
    void setCompTextSize(int size);
    void addBarrage(CBDataBase *apData);

protected:
    void deleteItems();
    void createDisplayComponent();
    void createDisplayComponent(CBarrageComponentBase *apComp);
    void createAnimation();
    void createAnimation(CBarrageComponentBase *apComp);
    void setCompBackground(CBarrageComponentBase *apComp);
    void setCompTextSize(CBarrageComponentBase *apComp);

private:
    QWidget *m_parentClass;
    QString m_sComponentName;
    bool m_barrageState;
    QSize m_parentSize;
    int m_fontSize;
    QColor m_backgroundColor;
    QList<CBarrageComponentBase*> m_lsComponent;
    QList<CBarrageAnimation*> m_lsAnimations;
    QList<CBDataBase*> m_lsBarrageData;
    CBarrageComponentBase* m_pDisplayComponent;

};

#endif // BARRAGEWIDGET_H
