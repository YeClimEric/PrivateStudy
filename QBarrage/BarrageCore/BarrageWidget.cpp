#include "barragewidget.h"
#include "barragecore.h"
#include "barrageanimation.h"
#include "Components/BarrageComponentBase.h"
#include "Components/cbverticalscreencomponent.h"
#include "dynobjectfactory.h"

CBarrageWidget::CBarrageWidget(QWidget* parent, QString asComponentName /*= "CBarrageComponentBase"*/)
: QWidget(parent),
  m_sComponentName(asComponentName)
{
//    setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint | Qt::Window);
//    setAttribute(Qt::WA_TranslucentBackground);
//    setAttribute(Qt::WA_ShowWithoutActivating, true);
//    setFocusPolicy(Qt::NoFocus);
//    setAttribute(Qt::WA_X11DoNotAcceptFocus, true);

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
    if(m_barrageState && !m_lsBarrageData.isEmpty())
    {
        deleteItems();
        createDisplayComponent();
        createAnimation();
        setCompTextSize(m_fontSize);
        start();
    }
    else
    {
        stop();
    }
}

void CBarrageWidget::setSize(const QSize &size)
{
    m_parentSize = size;
    foreach(CBarrageAnimation *anima, m_lsAnimations)
    {
        anima->setSize(size);
    }
}

void CBarrageWidget::setCompBackground(const QColor &color)
{
    m_backgroundColor = color;
    foreach(CBarrageComponentBase *pComp, m_lsComponent)
    {
        setCompBackground(pComp);
    }
}

void CBarrageWidget::setCompTextSize(int size)
{
    m_fontSize = size;
    foreach(CBarrageComponentBase *pComp, m_lsComponent)
    {
        setCompTextSize(pComp);
    }
}

void CBarrageWidget::addBarrage(CBDataBase *apData)
{
    BarrageCore::timeSRand();
    CBarrageComponentBase *pComp = static_cast<CBarrageComponentBase*>(CDynObjectFactory::CreateObject("CBVerticalScreenComponent",this));
//    CBarrageComponentBase *pComp = new CBarrageComponentBase(this);
//    pComp->show();
    if(pComp == nullptr)
        return;
    createDisplayComponent(pComp);
    createAnimation(pComp);
    setCompBackground(pComp);
    setCompTextSize(pComp);
    pComp->setData(apData);
    m_lsBarrageData << apData;

    if(m_barrageState)
    {
        if(m_lsComponent.count() == 1)
        {
            deleteItems();
            createDisplayComponent();
            createAnimation();
        }
        setCompTextSize(m_fontSize);
        start();
    }
}

void CBarrageWidget::deleteItems()
{
    while(!m_lsComponent.isEmpty())
    {
        delete m_lsComponent.takeLast();
        delete m_lsAnimations.takeLast();
    }
}

void CBarrageWidget::createDisplayComponent()
{
    BarrageCore::timeSRand();
    foreach(CBDataBase* pData, m_lsBarrageData)
    {
        Q_UNUSED(pData);
        CBarrageComponentBase *pComp = static_cast<CBarrageComponentBase*>(CDynObjectFactory::CreateObject("CBVerticalScreenComponent",this));
//        CBarrageComponentBase *pComp = new CBarrageComponentBase(this);
        createDisplayComponent(pComp);
    }
}

void CBarrageWidget::createDisplayComponent(CBarrageComponentBase *apComp)
{
    if(!m_lsBarrageData.isEmpty())
    {
        apComp->setData(m_lsBarrageData[qrand()%m_lsBarrageData.count()]);
    }
    apComp->hide();
    m_lsComponent << apComp;
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
    anim->setSize(m_parentSize);
    anim->setDirection(QAbstractAnimation::Backward);
    m_lsAnimations << anim;
}

void CBarrageWidget::setCompBackground(CBarrageComponentBase *apComp)
{
//    QString colorString = QString("CBarrageComponentBase{background-color:rgb(%1,%2,%3);}")
//            .arg(m_backgroundColor.red()).arg(m_backgroundColor.green())
//            .arg(m_backgroundColor.blue());
//            apComp->setStyleSheet(label->styleSheet() + colorString);
}

void CBarrageWidget::setCompTextSize(CBarrageComponentBase *apComp)
{
//    QFont ft = label->font();
//    ft.setPointSize(m_fontSize);
//    apComp->setFont(ft);
//    QFontMetrics ftMcs(ft);
//    apComp->resize(ftMcs.width(label->text()), ftMcs.height());
}

