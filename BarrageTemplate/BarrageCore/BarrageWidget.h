#ifndef BARRAGEWIDGET_H
#define BARRAGEWIDGET_H

#include <QWidget>

class QLabel;
class CBarrageAnimation;
class CRoomUI;
class CBarrageComponentBase;

class CBarrageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CBarrageWidget(QWidget* parent);
    ~CBarrageWidget();

    void OnMove();

    void start();
    void pause();
    void stop();

    void barrageStateChanged(bool on);
    void setSize(const QSize &size);

    void setLabelBackground(const QColor &color);
    void setLabelTextSize(int size);
    void addBarrage(const QString &string);

protected:
    void deleteItems();
    void createLabel();
    void createLabel(QLabel *label);
    void createAnimation();
    void createAnimation(QLabel *label);
    void setLabelBackground(QLabel *label);
    void setLabelTextSize(QLabel *label);

private:
    CRoomUI* m_pRoomUI;

    QWidget *m_parentClass;
    bool m_barrageState;
    QSize m_parentSize;
    int m_fontSize;
    QColor m_backgroundColor;
    QList<QLabel*> m_labels;
    QList<CBarrageAnimation*> m_animations;
    QStringList m_barrageLists;

};

#endif // BARRAGEWIDGET_H
