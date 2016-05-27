#include "StdAfx.h"
#include "barrageanimation.h"
#include "barragecore.h"

CBarrageAnimation::CBarrageAnimation(QWidget *parent)
    : QPropertyAnimation(parent)
{
    init();
}

CBarrageAnimation::CBarrageAnimation(QWidget *target,
                                             const QByteArray &propertyName,
                                             QWidget *parent)
    : QPropertyAnimation(target, propertyName, parent)
    , m_pTarget(target)
{
    init();
}

CBarrageAnimation::~CBarrageAnimation()
{

}

void CBarrageAnimation::animationFinished()
{
    /*delete m_pTarget;
    m_pTarget = nullptr;*/
    setDuration(qrand() % 10000 + 1000);
    setSize(m_parentSize);
    start();
}

void CBarrageAnimation::setSize(const QSize &size)
{
    m_parentSize = size;
    int randHeight = qrand()%size.height();
    setStartValue(QPoint(0, randHeight));
    setEndValue(QPoint(size.width(), randHeight));
}

void CBarrageAnimation::init()
{
    BarrageCore::timeSRand();
    setDuration(qrand()%10000 + 1000);
    setEasingCurve(QEasingCurve::Linear);

    connect(this, SIGNAL(finished()), SLOT(animationFinished()));
}
