#include "CBVerticalScreenData.h"

CBVerticalScreenData::CBVerticalScreenData()
{
    m_sDescription = "";
    m_sSenderName = "";
}

void CBVerticalScreenData::initData(const STRU_TVSHOW_UI_BARRAGE_APPEND_DATA *apData)
{
    if (apData == nullptr)
    {
        return;
    }
//    m_sSenderName = QString::fromStdWString(apData->m_szSenderNickName);
    //    m_sDescription = QString::fromStdWString(apData->m_szText);
}

void CBVerticalScreenData::initData(const QString csData)
{
    m_sDescription = csData;
}

