#include "CBVerticalScreenComponent.h"
#include "DataClass/cbverticalscreendata.h"

#include <QHBoxLayout>
#include <QLabel>

#define  DEF_DEFAULT_HEIGHT 20
#define  DEF_TOP_AN_BOTTOM_MARGIN  8

CBVerticalScreenComponent::CBVerticalScreenComponent(QWidget* parent):
    CComponentBase(parent),
    m_pMainLayout(nullptr),
    m_pSenderNameLabel(nullptr),
    m_pDesLabel(nullptr)
{
    setFixedHeight(DEF_DEFAULT_HEIGHT + 2*DEF_TOP_AN_BOTTOM_MARGIN);
    m_pMainLayout = new QHBoxLayout(this);
    m_pSenderNameLabel = new QLabel();
    m_pDesLabel = new QLabel();

    m_pLeftLabel = new QLabel();
    m_pRightLabel = new QLabel();

    m_pMainLayout->setSpacing(0);
    m_pMainLayout->setContentsMargins(0, DEF_TOP_AN_BOTTOM_MARGIN, 0, DEF_TOP_AN_BOTTOM_MARGIN);

    //加入顺序别乱哈，按照显示顺序添加
    m_pMainLayout->addWidget(m_pLeftLabel);
    m_pMainLayout->addWidget(m_pSenderNameLabel);
    m_pMainLayout->addWidget(m_pDesLabel);
    m_pMainLayout->addWidget(m_pRightLabel);

    setStyle();
}

CBVerticalScreenComponent::~CBVerticalScreenComponent()
{
    delete m_pDesLabel;
    delete m_pMainLayout;
    delete m_pSenderNameLabel;
    delete m_pLeftLabel;
    delete m_pRightLabel;

    m_pDesLabel                = nullptr;
    m_pMainLayout            = nullptr;
    m_pSenderNameLabel  = nullptr;
    m_pLeftLabel = nullptr;
    m_pRightLabel = nullptr;
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
    m_pDesLabel->adjustSize();

    QFontMetrics loFontMetricsA(m_pSenderNameLabel->font());
    QString strNameA = loFontMetricsA.elidedText(pVerticalData->getSenderName(), Qt::ElideRight, m_pSenderNameLabel->maximumWidth(), Qt::TextHideMnemonic);
    if (strNameA.isEmpty())
    {
        m_pSenderNameLabel->hide();
    }
    m_pSenderNameLabel->setText(strNameA);
    adjustSize();
}

void CBVerticalScreenComponent::setStyle()
{
    m_pLeftLabel->setFixedSize(DEF_DEFAULT_HEIGHT / 2, DEF_DEFAULT_HEIGHT);
    m_pLeftLabel->setStyleSheet(QString("border-top-left-radius:%1px;border-bottom-left-radius:10px;background-color:rgba(143,146,150,100);").arg(DEF_DEFAULT_HEIGHT / 2));

    m_pSenderNameLabel->setFixedWidth(70);
    m_pSenderNameLabel->setStyleSheet("color:#33d3f0;;background-color:rgba(143,146,150,100);");
    m_pDesLabel->setStyleSheet("color:#ffffff;;background-color:rgba(143,146,150,100);");
    QFont font;
    font.setPointSize(12);
    m_pDesLabel->setFont(font);
    m_pSenderNameLabel->setFont(font);

    m_pRightLabel->setFixedSize(DEF_DEFAULT_HEIGHT / 2, DEF_DEFAULT_HEIGHT);
    m_pRightLabel->setStyleSheet(QString("border-top-right-radius:%1px;border-bottom-right-radius:10px;background-color:rgba(143,146,150,100);").arg(DEF_DEFAULT_HEIGHT / 2));
}

