#include "CNetWorker.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>

CNetWorker *CNetWorker::Instance()
{
    static CNetWorker oNetWorker;
    return &oNetWorker;
}

CNetWorker::~CNetWorker()
{
    delete m_pData;
    m_pData = nullptr;
}

void CNetWorker::Get(const QUrl &url)
{
    QNetworkRequest oRequest(url);
    m_pData->m_pManager->get(oRequest);
}

CNetWorker::CNetWorker(QObject *parent) : QObject(parent),
  m_pData(new CNetWorker::CPrivate(this))
{
    connect(m_pData->m_pManager, &QNetworkAccessManager::finished, this,&CNetWorker::finished);
}

CNetWorker::CPrivate::CPrivate(CNetWorker *q):
    m_pManager(new QNetworkAccessManager(q))
{

}
