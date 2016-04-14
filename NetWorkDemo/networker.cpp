#include "networker.h"
#include <QDebug>

NetWorker *NetWorker::getInstance()
{
    //C++标准要求构造函数不能被打断，这样操作线程安全
    static NetWorker networker;
    return &networker;
}

NetWorker::~NetWorker()
{
    delete data;
    data = 0;
}

void NetWorker::get(QString url)
{
    qDebug()<<"get data";
    data->manager->get(QNetworkRequest(QUrl(url)));
}

NetWorker::NetWorker(QObject *parent) :
    QObject(parent),
    data(new NetWorker::Private(this))
{
    connect(data->manager, &QNetworkAccessManager::finished, this , &NetWorker::finished);
}
