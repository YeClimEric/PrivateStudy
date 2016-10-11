#ifndef CBVERTICALSCREENDATA_H
#define CBVERTICALSCREENDATA_H

#include "CBDataBase.h"
#include <QString>

struct STRU_TVSHOW_UI_BARRAGE_APPEND_DATA{};

class CBVerticalScreenData : public CDataBase
{
public:
    CBVerticalScreenData();

    void initData(const STRU_TVSHOW_UI_BARRAGE_APPEND_DATA *apData);
    void initData(const QString csData);
    inline QString getDescription(){ return m_sDescription;}
    inline QString getSenderName(){ return m_sSenderName;}

private:
    QString m_sDescription;
    QString m_sSenderName;
};

#endif // CBVERTICALSCREENDATA_H
