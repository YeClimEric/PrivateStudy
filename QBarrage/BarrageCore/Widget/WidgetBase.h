#ifndef BARRAGEWDGBASE_H
#define BARRAGEWDGBASE_H

#include <QWidget>

#include <QList>

class CComponentBase;
class CBDataBase;
class CBarrageAnimation;

class CBarrageWdgBase : public QWidget
{
	Q_OBJECT

public:
	CBarrageWdgBase(QWidget *parent, QString asComponentName);
    CBarrageWdgBase(QWidget* parent, QStringList alsComponentsName);
	~CBarrageWdgBase();

public:
    virtual void onShow(bool abShow);
    virtual void onMove(){}

    virtual void start();
    virtual void pause();
    virtual void stop();

    virtual void addBarrage(CBDataBase *apData);
    virtual void setSize(const QSize &size);

    inline void setBarrageState(bool asState){ m_barrageState = asState; }
    inline bool getBarrageState(){ return m_barrageState;}

protected:
    virtual void deleteItems();
    virtual void createAnimation(CComponentBase *apComp);

    inline QList<CComponentBase*>& getComponentsList(){ return m_lsComponent; }
    inline QList<CBarrageAnimation*> &getAnimationList(){ return m_lsAnimations; }
    inline QList<CBDataBase*> &getDataBaseList(){ return m_lsBarrageData; }

public slots:
    virtual void StateChanged(bool on);
    virtual void animationFinished();
    virtual void onCurrentValueChanged(const QVariant  &val){}



private:
    QWidget *m_parentClass;
    QString m_sComponentName;
    QStringList m_lsComponentsName;
    bool m_barrageState;
    QSize m_parentSize;
    QList<CComponentBase*> m_lsComponent;
    QList<CBarrageAnimation*> m_lsAnimations;
    QList<CBDataBase*> m_lsBarrageData;
};

#endif // BARRAGEWDGBASE_H
