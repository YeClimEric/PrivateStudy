#ifndef CBVERTICALSCREENDATA_H
#define CBVERTICALSCREENDATA_H

#include "cbdatabase.h"
#include <QString>

class CBVerticalScreenData : public CBDataBase
{
public:
    CBVerticalScreenData();

    void initData(const QString &str);
    inline QString getDescription(){ return m_sDescription;}
    inline QString getSenderName(){ return m_sSenderName;}

private:
    QString m_sDescription;
    QString m_sSenderName;
};

#endif // CBVERTICALSCREENDATA_H
