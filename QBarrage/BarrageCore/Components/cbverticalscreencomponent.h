#ifndef CBVERTICALSCREENCOMPONENT_H
#define CBVERTICALSCREENCOMPONENT_H

#include <QWidget>
#include "dynobjectfactory.h"
#include "BarrageComponentBase.h"


class QLabel;
class QHBoxLayout;

class CBDataBase;

class CBVerticalScreenComponent : public CBarrageComponentBase
{
public:
    CBVerticalScreenComponent(QWidget* parent);

    //写入弹幕的数据
    virtual void setData(const CBDataBase* acpData);
    //设置样式
//    virtual void setCompStyleSheet(const QString &asStyle);

private:

private:
    QLabel* m_pDesLabel;
    QLabel* m_pSenderNameLabel;
    QHBoxLayout* m_pMainLayout;

};

//类注册
REGISTER_CLASS(CBVerticalScreenComponent);

#endif // CBVERTICALSCREENCOMPONENT_H

