#ifndef CGIFTCOMPONENT_H
#define CGIFTCOMPONENT_H

#include <QWidget>
#include "ComponentBase.h"

class CGiftComponent : public CComponentBase
{
public:
    CGiftComponent(QWidget* parent);
    ~CGiftComponent();

    virtual void setData(const CDataBase* acpData);
};

//类注册
REGISTER_CLASS(CGiftComponent);

#endif // CGIFTCOMPONENT_H
