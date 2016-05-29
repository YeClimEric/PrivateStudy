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

    void setSize(const QSize &size);

public slots:
    void animationFinished();

protected:
    void init();
    QSize m_parentSize;
    QWidget* m_pTarget;

};

#endif // BARRAGEANIMATION_H
