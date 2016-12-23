#ifndef CQLABEL_H
#define CQLABEL_H
/*
    公共QLabel组件
    功能：
        1.继承QLabel
        2.支持文字滚动以及滚动方向设置：L->R, R->L, T->B, B->T
        3.文字竖向排列:竖向排列文本截取和滚屏有BUG
        4.支持文本截取:Qt::TextElideMode
*/

#include <QLabel>

class CQLabel : public QLabel
{
    Q_OBJECT
    Q_ENUMS(SCrollType)
    Q_ENUMS(TextDirection)
    Q_PROPERTY(Qt::TextElideMode elideMode READ elideMode WRITE SetElideMode)
    Q_PROPERTY(int textLength READ textLength WRITE SetTextLength)
    Q_PROPERTY(SCrollType scrollType READ scrollType WRITE SetScrollType)
    Q_PROPERTY(TextDirection textDirection READ textDirection WRITE SetTextDirection)
    Q_PROPERTY(bool scrollState READ scrollState WRITE SetScrollState)
    Q_PROPERTY(int scrollInterval READ scrollInterval WRITE SetScrollInterval)

public:
    CQLabel(QWidget * parent = 0);
    enum SCrollType{
        Horizontal_LR,
        Horizontal_RL,//Default
        Vertical_TB,
        Vertical_BT
    };
    enum TextDirection{
        Horizontal,
        Vertical
    };

public:
    Q_INVOKABLE void SetText(const QString & text);
    Q_INVOKABLE inline void SetScrollInterval(const int interval){m_iScrollInterval = interval;}
    Q_INVOKABLE inline int scrollInterval(){return m_iScrollInterval;}
    Q_INVOKABLE inline Qt::TextElideMode elideMode(){return m_oElideMode;}
    Q_INVOKABLE void SetElideMode(const Qt::TextElideMode mode){m_oElideMode = mode;}
    Q_INVOKABLE void SetTextLength(const int length);
    Q_INVOKABLE inline int textLength(){ return m_iTextLength;}
    Q_INVOKABLE void SetScrollType(SCrollType type = Horizontal_RL);
    Q_INVOKABLE inline SCrollType scrollType(){return m_oScrollType;}
    Q_INVOKABLE void SetTextDirection(TextDirection direction = Horizontal, bool wordwrap = false, Qt::Alignment alignment = Qt::AlignCenter);
    Q_INVOKABLE inline TextDirection textDirection(){return m_oTextDirection;}
    Q_INVOKABLE void SetScrollState(bool on);
    Q_INVOKABLE inline bool scrollState(){return m_bAllowScroll;}

private:
    void SetElidedText(const QString& text);
    void paintEvent(QPaintEvent *e);
    void timerEvent(QTimerEvent* e);

//内部调用公共函数
private:
    QString GetElidedText(const QString& text, int length);
private:
    int m_iTextLength;
    SCrollType m_oScrollType;
    TextDirection m_oTextDirection;
    bool m_bAllowScroll;
    bool m_bWordWrap;
    Qt::TextElideMode m_oElideMode;
    Qt::Alignment m_oAlignment;
    int m_iTextX, m_iTextY;
    int m_iScrollTimerID;
    int m_iScrollInterval;
};

#endif // CQLABEL_H
