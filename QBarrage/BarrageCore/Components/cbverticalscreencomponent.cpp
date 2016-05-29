#include "cbverticalscreencomponent.h"
#include "DataClass/cbverticalscreendata.h"

#include <QHBoxLayout>
#include <QLabel>

CBVerticalScreenComponent::CBVerticalScreenComponent(QWidget* parent):
    CBarrageComponentBase(parent),
    m_pMainLayout(nullptr),
    m_pSenderNameLabel(nullptr),
    m_pDesLabel(nullptr)
{
    m_pMainLayout = new QHBoxLayout(this);
    m_pSenderNameLabel = new QLabel();
    m_pDesLabel = new QLabel();

    m_pMainLayout->addWidget(m_pSenderNameLabel);
    m_pMainLayout->addWidget(m_pDesLabel);
}

void CBVerticalScreenComponent::setData(const CBDataBase* acpData)
{
    if(acpData == nullptr)
        return;

    CBDataBase* pDataBase = const_cast<CBDataBase*>(acpData);
    if(pDataBase == nullptr)
        return;
    CBVerticalScreenData* pVerticalData = (CBVerticalScreenData*)pDataBase;

    if(pVerticalData == nullptr)
        return;

    m_pDesLabel->setText(pVerticalData->getDescription());

}

