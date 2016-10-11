#ifndef CBVERTICALSCREENCOMPONENT_H
#define CBVERTICALSCREENCOMPONENT_H

#include <QWidget>
#include "ComponentBase.h"


class QLabel;
class QHBoxLayout;

class CDataBase;

class CBVerticalScreenComponent : public CComponentBase
{
public:
    CBVerticalScreenComponent(QWidget* parent);
    ~CBVerticalScreenComponent();

    //写入弹幕的数据
    virtual void setData(const CDataBase* acpData);

private:
    void setStyle();
private:
    QLabel* m_pDesLabel;
    QLabel* m_pSenderNameLabel;
    QLabel* m_pLeftLabel, *m_pRightLabel;
    QHBoxLayout* m_pMainLayout;

};

//类注册
REGISTER_CLASS(CBVerticalScreenComponent);

#endif // CBVERTICALSCREENCOMPONENT_H

