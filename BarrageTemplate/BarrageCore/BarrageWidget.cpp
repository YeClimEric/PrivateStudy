#include "StdAfx.h"
#include "barragewidget.h"
#include "barragecore.h"
#include "barrageanimation.h"
#include "croomui.h"

#include <QFile>
#include <QLabel>
#include <QPushButton>

CBarrageWidget::CBarrageWidget(CRoomUI* parent)
: QWidget(parent->m_pRoomUIWgd),
m_pRoomUI(parent)
{
    setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint | Qt::Window);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_ShowWithoutActivating, true);
    setFocusPolicy(Qt::NoFocus);
    setAttribute(Qt::WA_X11DoNotAcceptFocus, true);

    /*this->setStyleSheet("background-color:red");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    show();*/
    m_parentClass = static_cast<QWidget*>(parent->m_pRoomUIWgd);
    m_barrageState = true;//测试需要，先置位
    m_fontSize = 15;
    m_backgroundColor = QColor(255, 0, 0);
}

CBarrageWidget::~CBarrageWidget()
{
    deleteItems();
}

void CBarrageWidget::OnMove()
{
    if(m_pRoomUI != NULL && m_pRoomUI->m_pVideoLayout != NULL)
    {
        QRect qrcChatArea = m_pRoomUI->m_pVideoLayout->geometry();
        QPoint ptTopLeft = m_pRoomUI->m_pRoomUIWgd->mapToGlobal(qrcChatArea.topLeft());
        int cx = ptTopLeft.x();
        int cy = ptTopLeft.y();

        setGeometry(cx, cy, qrcChatArea.width(), qrcChatArea.height());

        move(cx, cy);
    }
}

void CBarrageWidget::start()
{
    if(m_barrageState)
    {
        for(int i=0; i<m_labels.count(); i++)
        {
            m_labels[i]->show();
            m_animations[i]->start();
        }
    }
}

void CBarrageWidget::pause()
{
    if(m_barrageState)
    {
        for(int i=0; i<m_labels.count(); i++)
        {
            m_labels[i]->hide();
            m_animations[i]->pause();
        }
    }
}

void CBarrageWidget::stop()
{
    for(int i=0; i<m_labels.count(); i++)
    {
        m_labels[i]->hide();
        m_animations[i]->stop();
    }
}

void CBarrageWidget::barrageStateChanged(bool on)
{
    m_barrageState = on;
    if(m_barrageState && !m_barrageLists.isEmpty())
    {
        deleteItems();
        createLabel();
        createAnimation();
        setLabelTextSize(m_fontSize);
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
    foreach(CBarrageAnimation *anima, m_animations)
    {
        anima->setSize(size);
    }
}

void CBarrageWidget::setLabelBackground(const QColor &color)
{
    m_backgroundColor = color;
    foreach(QLabel *label, m_labels)
    {
        setLabelBackground(label);
    }
}

void CBarrageWidget::setLabelTextSize(int size)
{
    m_fontSize = size;
    foreach(QLabel *label, m_labels)
    {
        setLabelTextSize(label);
    }
}

void CBarrageWidget::addBarrage(const QString &string)
{
    BarrageCore::timeSRand();
    QLabel *label = new QLabel(this);
    createLabel(label);
    createAnimation(label);
    setLabelBackground(label);
    setLabelTextSize(label);

    label->setText(string);
    m_barrageLists << string;

    if(m_barrageState)
    {
        if(m_labels.count() == 1)
        {
            deleteItems();
            createLabel();
            createAnimation();
        }
        setLabelTextSize(m_fontSize);
        start();
    }
}

void CBarrageWidget::deleteItems()
{
    while(!m_labels.isEmpty())
    {
        delete m_labels.takeLast();
        delete m_animations.takeLast();
    }
}

void CBarrageWidget::createLabel()
{
    BarrageCore::timeSRand();
    foreach(QString str, m_barrageLists)
    {
        Q_UNUSED(str);
        QLabel *label = new QLabel(this);
        createLabel(label);
    }
}

void CBarrageWidget::createLabel(QLabel *label)
{
    QString color = QString("QLabel{color:rgb(%1,%2,%3);}")
            .arg(qrand()%255).arg(qrand()%255).arg(qrand()%255);
    label->setStyleSheet(color);
    if(!m_barrageLists.isEmpty())
    {
        label->setText(m_barrageLists[qrand()%m_barrageLists.count()]);
    }
    label->hide();
    m_labels << label;
}

void CBarrageWidget::createAnimation()
{
    foreach(QLabel *label, m_labels)
    {
        createAnimation(label);
    }
}

void CBarrageWidget::createAnimation(QLabel *label)
{
    CBarrageAnimation *anim = new CBarrageAnimation(label, "pos");
    anim->setSize(m_parentSize);
    anim->setDirection(QAbstractAnimation::Backward);
    m_animations << anim;
}

void CBarrageWidget::setLabelBackground(QLabel *label)
{
    /*QString colorString = QString("QLabel{background-color:rgb(%1,%2,%3);}")
            .arg(m_backgroundColor.red()).arg(m_backgroundColor.green())
            .arg(m_backgroundColor.blue());
            label->setStyleSheet(label->styleSheet() + colorString);*/
}

void CBarrageWidget::setLabelTextSize(QLabel *label)
{
    QFont ft = label->font();
    ft.setPointSize(m_fontSize);
    label->setFont(ft);
    QFontMetrics ftMcs(ft);
    label->resize(ftMcs.width(label->text()), ftMcs.height());
}

