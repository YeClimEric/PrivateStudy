#ifndef NETWORKER_H
#define NETWORKER_H

#include <QObject>
#include <QNetworkReply>

class NetWorker : public QObject
{
    Q_OBJECT
public:
    static NetWorker* instance();

    ~NetWorker();

    void get(const QString &url);

signals:
    void finished(QNetworkReply* reply);

public slots:

private:
/*
 *为了保证二进制兼容性
*/
    class Private;
    friend class Private;
    Private* d;
/*
作为单例模式，要求构造函数、拷贝构造函数和赋值运算符都是私有的
*/

    explicit NetWorker(QObject *parent = 0);
    NetWorker(const NetWorker &) Q_DECL_EQ_DELETE;
    NetWorker& operator=(NetWorker rhs) Q_DECL_EQ_DELETE;

};

class NetWorker::Private
{
public:
    Private(NetWorker* q): manager(new QNetworkAccessManager(q)){}
    QNetworkAccessManager* manager;
};

#endif // NETWORKER_H
