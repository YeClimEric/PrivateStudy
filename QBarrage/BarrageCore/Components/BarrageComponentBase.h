#ifndef BARRAGECOMPONENTBASE_H
#define BARRAGECOMPONENTBASE_H

#include <QWidget>

class CBDataBase;

class CBarrageComponentBase : public QWidget
{
	Q_OBJECT

public:
	CBarrageComponentBase(QWidget *parent);
	~CBarrageComponentBase();

    //写入弹幕的数据，子类实现
    virtual void setData(const CBDataBase* data){}

private:
	
};



#endif // BARRAGECOMPONENTBASE_H
