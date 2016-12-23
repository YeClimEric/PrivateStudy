#include "CQLabel.h"
#include <QString>
#include <QPainter>
#include <QTimerEvent>
#include <QDebug>

CQLabel::CQLabel(QWidget * parent):
    QLabel(parent),
    m_iTextLength(0),
    m_oScrollType(SCrollType::Horizontal_RL),
    m_bAllowScroll(false),
    m_bWordWrap(false),
    m_oAlignment(Qt::AlignCenter),
    m_oElideMode(Qt::TextElideMode::ElideRight),
    m_iTextX(0),
    m_iTextY(0),
    m_iScrollTimerID(0),
    m_iScrollInterval(100)
{

}

void CQLabel::SetTextLength(const int length)
{
    m_iTextLength = length;
    m_bAllowScroll = false;

}

void CQLabel::SetScrollType(CQLabel::SCrollType type)
{
    m_oScrollType = type;
}

void CQLabel::SetTextDirection(CQLabel::TextDirection direction, bool wordwrap, Qt::Alignment alignment)
{
    m_oTextDirection = direction;
    m_bWordWrap = wordwrap;
    m_oAlignment = alignment;
}

void CQLabel::SetScrollState(bool on)
{
    m_bAllowScroll = on;
    if(on){
        m_iScrollTimerID = startTimer(m_iScrollInterval);
        qDebug()<<"Start Timer";
    }
    else {
        killTimer(m_iScrollTimerID);
        m_iTextX = 0;
        m_iTextY = 0;
        m_iScrollTimerID = 0;
    }
}

void CQLabel::SetElidedText(const QString &text)
{
    if(text.isEmpty()){
        return ;
    }
    else {
        0 == m_iTextLength ? m_iTextLength = width() : width();
        setText(GetElidedText(text, m_iTextLength));
    }
}

void CQLabel::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    qDebug()<<"text:"<<text();
    painter.drawText(QRectF(m_iTextX,m_iTextY, width(), height()),m_oAlignment,text());
}

void CQLabel::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == m_iScrollTimerID){
        qDebug()<<"TimerEvent";
        QFontMetrics loFontMetricsA(this->font());
        int textLength = loFontMetricsA.width(text());
        int textHeight = loFontMetricsA.height();
        int charLen = loFontMetricsA.width(text(), 1);
        qDebug()<<"x:"<<m_iTextX<<" y:"<<m_iTextY;
        switch (m_oScrollType) {
        case SCrollType::Horizontal_RL:
        {
            if((textLength + m_iTextX) <= 0){
                m_iTextX = width();
            }
            m_iTextX -= charLen;
            m_iTextY = 0;
            break;
        }
        case SCrollType::Horizontal_LR:
        {
            if((width() - m_iTextX) <= 0){
                m_iTextX = -textLength;
            }
            m_iTextX += charLen;
            m_iTextY = 0;
            break;
        }
        case SCrollType::Vertical_BT:
        {
            if((textHeight + m_iTextY) <= 0){
                m_iTextY = height();
            }
            m_iTextX = 0;
            m_iTextY -= 2;
            break;
        }
        case SCrollType::Vertical_TB:
        {
            if((height() - m_iTextY) <= 0){
                m_iTextY = -textHeight;
            }
            m_iTextX = 0;
            m_iTextY += 2;
            break;
        }
        default:
            break;
        }
    }
    update();
}

QString CQLabel::GetElidedText(const QString &text, int length)
{
    if(text.isEmpty() || 0 == length){
        return QString("");
    }
    else {
        QFontMetrics loFontMetricsA(this->font());
        qDebug()<<length;
        return loFontMetricsA.elidedText(text, m_oElideMode, length, Qt::TextHideMnemonic);
    }
}

void CQLabel::SetText(const QString &text)
{
    if(TextDirection::Vertical == m_oTextDirection){
        setWordWrap(true);
        m_oAlignment = Qt::AlignTop;
        setText(text.split("", QString::SkipEmptyParts).join("\n"));
    }
    else {
        SetElidedText(text);
    }
}
