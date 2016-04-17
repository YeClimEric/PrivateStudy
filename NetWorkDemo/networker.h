#ifndef NETWORKER_H
#define NETWORKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class NetWorker : public QObject
{
    Q_OBJECT
public:


    static NetWorker* getInstance();
    ~NetWorker();

    void get(QString url);

signals:
    void finished(QNetworkReply *reply);

public slots:

private:
    //创建内部类，为保证程序的二进制兼容，将所有的私有变量通通放到内部类中
    class Private;
    friend class Private;
    Private *data;

    explicit NetWorker(QObject *parent = 0);
    NetWorker(const NetWorker&);Q_DECL_EQ_DELETE
    NetWorker &operator =(NetWorker rth);Q_DECL_EQ_DELETE

};

class NetWorker::Private
{
public:
    explicit Private(NetWorker* w = 0):manager(new QNetworkAccessManager(w)){}
    QNetworkAccessManager *manager;

};

#endif // NETWORKER_H
