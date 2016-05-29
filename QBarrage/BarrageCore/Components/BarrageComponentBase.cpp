#include "BarrageComponentBase.h"

#include <QPushButton>

CBarrageComponentBase::CBarrageComponentBase(QWidget *parent)
	: QWidget(parent)
{

}

CBarrageComponentBase::~CBarrageComponentBase()
{

}

//void CBarrageComponentBase::setCompStyleSheet(const QString &asStyle)
//{
//    QString color = QString("QWidget#%1{color:rgb(%2,%3,%4);}")
//            .arg(objectName())
//            .arg(qrand()%255).arg(qrand()%255).arg(qrand()%255);
////    label->setStyleSheet(color);
//}
