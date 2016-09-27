#include <QPropertyAnimation>
#include "WidgetBase.h"
#include "../barragecore.h"
#include "../Animations/ContainerAnimation/barrageanimation.h"
#include "../Components/ComponentBase.h"
#include "../Components/CBVerticalScreenComponent.h"
#include "../DynObjectFactory.h"

#include "../Components/ComponentBase.h"

CBarrageWdgBase::CBarrageWdgBase(QWidget *parent, QString asComponentName):
QWidget(parent),
m_sComponentName(asComponentName),
m_barrageState(true)
{
    m_lsComponentsName << m_sComponentName;
}

CBarrageWdgBase::CBarrageWdgBase(QWidget* parent, QStringList alsComponentsName):
QWidget(parent),
m_lsComponentsName(alsComponentsName),
m_barrageState(true)
{

}

CBarrageWdgBase::~CBarrageWdgBase()
{

}

void CBarrageWdgBase::onShow(bool abShow)
{
    if (abShow && m_barrageState)
    {
        onMove();
        show();
    }
    else
    {
        hide();
    }

}

void CBarrageWdgBase::start()
{
    if(m_barrageState)
    {
        for(int i = 0; i < m_lsComponent.count(); i++)
        {
            m_lsComponent[i]->show();
            m_lsAnimations[i]->start();
        }
    }
}

void CBarrageWdgBase::pause()
{
    if(m_barrageState)
    {
        for(int i = 0; i < m_lsComponent.count(); i++)
        {
            m_lsComponent[i]->hide();
            m_lsAnimations[i]->pause();
        }
    }
}

void CBarrageWdgBase::stop()
{
    for(int i = 0; i < m_lsComponent.count(); i++)
    {
        m_lsComponent[i]->hide();
        m_lsAnimations[i]->stop();
    }
}

void CBarrageWdgBase::addBarrage(CBDataBase *apData)
{
    BarrageCore::timeSRand();
    int index = qrand() % m_lsComponentsName.size();
    CComponentBase *pComp = static_cast<CComponentBase*>(CDynObjectFactory::CreateObject(m_lsComponentsName[index], this));
    if(pComp == nullptr)
        return;
    pComp->setData(apData);
    createAnimation(pComp);
    m_lsComponent << pComp;
    start();
}

void CBarrageWdgBase::StateChanged(bool on)
{

}

void CBarrageWdgBase::setSize(const QSize &size)
{
    m_parentSize = size;
    setFixedSize(size);
}

void CBarrageWdgBase::deleteItems()
{
    while(!m_lsComponent.isEmpty())
    {
        delete m_lsComponent.takeLast();
        delete m_lsAnimations.takeLast();
    }
}

void CBarrageWdgBase::createAnimation(CComponentBase *apComp)
{
    CBarrageAnimation *anim = new CBarrageAnimation(apComp, "pos");
    connect(anim, SIGNAL(finished()), this, SLOT(animationFinished()));
    connect(anim, SIGNAL(valueChanged(QVariant)), this, SLOT(onCurrentValueChanged(QVariant)));
    anim->setDirection(QAbstractAnimation::Backward);
    m_lsAnimations << anim;
}

void CBarrageWdgBase::animationFinished()
{
    CBarrageAnimation* pAnim = dynamic_cast<CBarrageAnimation*>(sender());
    if(pAnim == nullptr)
        return;
    int iAnimIndex = m_lsAnimations.indexOf(pAnim);
    if(iAnimIndex == -1)
        return;


    CComponentBase* pComp = dynamic_cast<CComponentBase*>(pAnim->targetObject());
    if(pComp == nullptr)
        return;
    int iCompIndex = m_lsComponent.indexOf(pComp);
    if(iCompIndex == -1)
        return;
    m_lsAnimations.removeAt(iAnimIndex);
    m_lsComponent.removeAt(iCompIndex);

    pAnim->stop();
    delete pAnim;
    pAnim = nullptr;
    delete pComp;
    pComp = nullptr;
}
