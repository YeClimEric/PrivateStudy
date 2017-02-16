#ifndef CNETWORKER_H
#define CNETWORKER_H

#include <QObject>
#include <QNetworkReply>
class QNetworkAccessManager;

class CNetWorker : public QObject
{
    Q_OBJECT
public:
    static CNetWorker *Instance();
    ~CNetWorker();
    void Get(const QUrl& url);
    inline QNetworkAccessManager* GetNetWorkManager(){return m_pData->m_pManager;}

signals:
    void finished(QNetworkReply* reply);

public slots:

private:
    class CPrivate
    {
    public:
        CPrivate(CNetWorker* q);
        QNetworkAccessManager* m_pManager;
    };

    friend class CPrivate;
    CPrivate* m_pData;

    explicit CNetWorker(QObject *parent = 0);
    CNetWorker(const CNetWorker&) Q_DECL_EQ_DELETE;
    CNetWorker& operator =(CNetWorker rhs) Q_DECL_EQ_DELETE;
};

#endif // CNETWORKER_H
