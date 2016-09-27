#include "barrageanimation.h"
#include "../../barragecore.h"

CBarrageAnimation::CBarrageAnimation(QWidget *parent)
    : QPropertyAnimation(parent),
    m_iMinDuration(3000)
{
    init();
}

CBarrageAnimation::CBarrageAnimation(QWidget *target,
                                             const QByteArray &propertyName,
                                             QWidget *parent)
    : QPropertyAnimation(target, propertyName, parent)
    , m_pTarget(target)
    , m_iMinDuration(3)
{
    init();
}

CBarrageAnimation::~CBarrageAnimation()
{

}

void CBarrageAnimation::init()
{
    /*BarrageCore::timeSRand();
    setDuration(qrand() % 10000 + m_iMinDuration);*/
    setEasingCurve(QEasingCurve::Linear);
}
