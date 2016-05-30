#include <QPropertyAnimation>
#include "barragewidget.h"
#include "barragecore.h"
#include "barrageanimation.h"
#include "Components/BarrageComponentBase.h"
#include "Components/cbverticalscreencomponent.h"
#include "dynobjectfactory.h"

#include <QDebug>

CBarrageWidget::CBarrageWidget(QWidget* parent, QString asComponentName /*= "CBarrageComponentBase"*/)
: QWidget(parent),
  m_sComponentName(asComponentName)
{
//    setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint | Qt::Window);
//    setAttribute(Qt::WA_TranslucentBackground);
//    setAttribute(Qt::WA_ShowWithoutActivating, true);
//    setFocusPolicy(Qt::NoFocus);
//    setAttribute(Qt::WA_X11DoNotAcceptFocus, true);

    setStyleSheet("background-color:red;");

    m_parentClass = static_cast<QWidget*>(parent);
    m_barrageState = false;
    m_fontSize = 15;
    m_backgroundColor = QColor(255, 0, 0);
    setFixedSize(650,380);
}

CBarrageWidget::~CBarrageWidget()
{
    deleteItems();
}


void CBarrageWidget::start()
{
    if(m_barrageState)
    {
        for(int i=0; i<m_lsComponent.count(); i++)
        {
            m_lsComponent[i]->show();
            m_lsAnimations[i]->start();
        }
    }
}

void CBarrageWidget::pause()
{
    if(m_barrageState)
    {
        for(int i=0; i<m_lsComponent.count(); i++)
        {
            m_lsComponent[i]->hide();
            m_lsAnimations[i]->pause();
        }
    }
}

void CBarrageWidget::stop()
{
    for(int i=0; i<m_lsComponent.count(); i++)
    {
        m_lsComponent[i]->hide();
        m_lsAnimations[i]->stop();
    }
}

void CBarrageWidget::barrageStateChanged(bool on)
{
    m_barrageState = on;
//    if(m_barrageState && !m_lsBarrageData.isEmpty())
//    {
//        deleteItems();
//        createDisplayComponent();
//        createAnimation();
//        setCompTextSize(m_fontSize);
//        start();
//    }
//    else
//    {
//        stop();
//    }
}

void CBarrageWidget::setSize(const QSize &size)
{
    m_parentSize = size;
    foreach(CBarrageAnimation *anima, m_lsAnimations)
    {
        anima->setSize(size);
    }
}

void CBarrageWidget::addBarrage(CBDataBase *apData)
{
    BarrageCore::timeSRand();
    CBarrageComponentBase *pComp = static_cast<CBarrageComponentBase*>(CDynObjectFactory::CreateObject("CBVerticalScreenComponent",this));
    if(pComp == nullptr)
        return;
    createAnimation(pComp);
    pComp->setData(apData);
    m_lsComponent << pComp;
    start();
}

void CBarrageWidget::animationFinished()
{
    qDebug()<<"animationFinished BEGIN!";
    CBarrageAnimation* pAnim = dynamic_cast<CBarrageAnimation*>(sender());
    if(pAnim == nullptr)
        return ;
    int iAnimIndex = m_lsAnimations.indexOf(pAnim);
    if(iAnimIndex == -1)
        return;


    CBarrageComponentBase* pComp = dynamic_cast<CBarrageComponentBase*>(pAnim->targetObject());
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

    qDebug()<<"animationFinished END!";
}

void CBarrageWidget::deleteItems()
{
    while(!m_lsComponent.isEmpty())
    {
        delete m_lsComponent.takeLast();
        delete m_lsAnimations.takeLast();
    }
}

void CBarrageWidget::createAnimation()
{
    foreach(CBarrageComponentBase *pComp, m_lsComponent)
    {
        createAnimation(pComp);
    }
}

void CBarrageWidget::createAnimation(CBarrageComponentBase *apComp)
{
    CBarrageAnimation *anim = new CBarrageAnimation(apComp, "pos");
    connect(anim, SIGNAL(finished()), this, SLOT(animationFinished()));
    anim->setSize(m_parentSize);
    anim->setDirection(QAbstractAnimation::Backward);
    m_lsAnimations << anim;
}

