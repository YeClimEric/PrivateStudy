#ifndef CDYNOBJECTFACTORY_H
#define CDYNOBJECTFACTORY_H

#include <QMap>
#include <QString>
#include <QWidget>
using  namespace std;

typedef  void *(*CREATE_FUNC)(QWidget*);

class CDynObjectFactory
{
public:
    static  void *CreateObject( const QString &name, QWidget* parent)
    {
        QMap<QString, CREATE_FUNC>::const_iterator it;
        it = mapCls_.find(name);
         if (it == mapCls_.end())
             return  0;
         else
             it.value()(parent);
    }

     static  void Register( const QString &name, CREATE_FUNC func)
    {
        mapCls_[name] = func;
    }
private:
     static QMap<QString, CREATE_FUNC> mapCls_;
};

// g++
//__attribute ((weak))
__declspec(selectany) QMap<QString, CREATE_FUNC> CDynObjectFactory::mapCls_;
//头文件被包含多次，也只定义一次mapCls_,但是mingw和vs的支持度不一样，在vs下可以，mingw不行，还是会重新定义;

class Register
{
public:
    Register( const QString &name, CREATE_FUNC func)
    {
        CDynObjectFactory::Register(name, func);
    }
};

#define REGISTER_CLASS(class_name) \
class class_name##Register { \
public: \
     static  void* NewInstance(QWidget* parent) \
    { \
         return  new class_name(parent); \
    } \
private: \
     static Register reg_; \
}; \
__declspec(selectany) Register class_name##Register::reg_(#class_name, class_name##Register::NewInstance)

#endif // CDynObjectFactory_H
