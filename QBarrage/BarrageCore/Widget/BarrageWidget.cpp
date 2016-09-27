#include <QPropertyAnimation>
#include "barragewidget.h"
#include "../barragecore.h"
#include "../Animations/ContainerAnimation/barrageanimation.h"
#include "../Components/ComponentBase.h"
#include "../Components/CBVerticalScreenComponent.h"
#include "../dynobjectfactory.h"
#include <QVariant>

CBarrageWidget::CBarrageWidget(QWidget* parent, QString asComponentName /*= "CComponentBase"*/)
: CBarrageWdgBase(parent, asComponentName),
  m_iLineCount(5),
  m_iBarrageIntervalLength(70)
{
    setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint | Qt::Window);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_ShowWithoutActivating, true);
    setFocusPolicy(Qt::NoFocus);
    setAttribute(Qt::WA_X11DoNotAcceptFocus, true);

    m_parentClass = static_cast<QWidget*>(parent);
    m_barrageState = true;

    m_pMainLayout = new QVBoxLayout(this);
    m_pMainLayout->setSpacing(0);
    m_pMainLayout->setContentsMargins(0, 0, 0, 0);

    //先初始化一把弹幕的布局
    for(int i = 0; i < m_iLineCount; i++)
    {
        QWidget* pWdg = new QWidget(this);
        pWdg->setObjectName(QString("Line%1").arg(i));
        m_pMainLayout->addWidget(pWdg);
        m_lsDisplayLine.push_back(pWdg);
    }
}

CBarrageWidget::~CBarrageWidget()
{
    deleteItems();
}


void CBarrageWidget::onMove()
{

}

void CBarrageWidget::start()
{
    if(m_barrageState)
    {
        if (!getComponentsList().isEmpty() && (getCurrentShowBarrageWdgCount() < m_iLineCount))
        {
            int iCurCount = getCurrentShowBarrageWdgCount();
            while((getAnimationList().size() == getComponentsList().size()) &&
                (getComponentsList().size() > iCurCount) &&
                iCurCount < m_iLineCount
                )
            {
                QWidget* pParentWdg = getNullChildLineWdg();
                //找不到的话说明正在满载弹幕，直接跳出即可
                if (pParentWdg == nullptr)
                {
                    break;
                }
                onAppendAnimation(pParentWdg);
                iCurCount = getCurrentShowBarrageWdgCount();
            }
        }
    }
}

void CBarrageWidget::pause()
{
    if(m_barrageState)
    {
        for(int i=0; i<getComponentsList().count(); i++)
        {
            getComponentsList()[i]->hide();
            getAnimationList()[i]->pause();
        }
    }
}

void CBarrageWidget::stop()
{
    for(int i=0; i<getComponentsList().count(); i++)
    {
        getComponentsList()[i]->hide();
        getAnimationList()[i]->stop();
    }
}
void CBarrageWidget::onShow(bool abShow)
{
    if(abShow && m_barrageState)
    {
        onMove();
        show();
    }
    else
    {
        hide();
    }
}

void CBarrageWidget::onCurrentValueChanged(const QVariant &val)
{
    CBarrageAnimation* pAnim = dynamic_cast<CBarrageAnimation*>(sender());
    if(pAnim == nullptr)
        return;

    CComponentBase* pTarget = dynamic_cast<CComponentBase*>(pAnim->targetObject());
    if((pTarget == nullptr) || pTarget->parent() == nullptr)
        return;

    QWidget* pParent = dynamic_cast<QWidget*>(pTarget->parent());
    if(pParent == nullptr)
        return;

    QObjectList oList = pParent->children();
    if (oList.size() == 0)
        return;

    CComponentBase* pLastTarget = dynamic_cast<CComponentBase*>(oList.last());
    if ((pLastTarget == nullptr) ||
        (pLastTarget != pTarget))
    {
        return;
    }

    QPoint oCurPos = val.toPoint();
    if(pParent->width() - (pTarget->width() + oCurPos.x()) >= m_iBarrageIntervalLength)
    {
        onAppendAnimation(pParent);
    }

}

void CBarrageWidget::onAppendAnimation(QWidget* parent)
{
    int iCurCount = getCurrentShowBarrageWdgCount();
    if(getComponentsList().size() <= iCurCount)
    {
        return;
    }
    QWidget* pCurWdg = getComponentsList()[iCurCount];
    pCurWdg->setParent(parent);
    pCurWdg->show();
    getAnimationList()[iCurCount]->setStartValue(QPoint(0 - pCurWdg->width(), 0));
    getAnimationList()[iCurCount]->setEndValue(QPoint(parent->width(), 0));
    getAnimationList()[iCurCount]->setDuration(parent->width() * 10 * 3);

    getAnimationList()[iCurCount]->start();
}

void CBarrageWidget::addAnimationToQueue(CBarrageAnimation* apAnimation)
{
    if(m_pMainLayout == nullptr)
        return;
    if(apAnimation == nullptr)
        return;

    QWidget* pTargetWidget = dynamic_cast<QWidget*>(apAnimation->targetObject());
    m_pMainLayout->addWidget(pTargetWidget);
    apAnimation->start();
}

int CBarrageWidget::getCurrentShowBarrageWdgCount()
{
    int iCount = 0;
    foreach(QWidget* it, m_lsDisplayLine)
    {
        iCount += it->children().size();
    }
    return iCount;
}

QWidget* CBarrageWidget::getNullChildLineWdg()
{
    foreach(QWidget* it, m_lsDisplayLine)
    {
        if (it->children().size() == 0)
        {
            return it;
        }
    }
    return nullptr;
}

