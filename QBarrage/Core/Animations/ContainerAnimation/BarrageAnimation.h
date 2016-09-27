#ifndef BARRAGEANIMATION_H
#define BARRAGEANIMATION_H

#include <QSize>
#include <QPropertyAnimation>
#include <QWidget>
#include <QObject>

class CBarrageAnimation : public QPropertyAnimation
{
    Q_OBJECT
public:
    explicit CBarrageAnimation(QWidget *parent = 0);
    CBarrageAnimation(QWidget *target, const QByteArray &propertyName, QWidget *parent = 0);
    ~CBarrageAnimation();// = default;//Q_DECL_EQ_DEFAULT

    inline void setMinDuration(int aiDuration){ m_iMinDuration = aiDuration; }

protected:
    void init();
    QSize m_parentSize;
    QWidget* m_pTarget;
    int m_iMinDuration;

};

#endif // BARRAGEANIMATION_H
