#include "widget.h"
#include "ui_widget.h"

#include <QJsonParseError>
#include <QJsonDocument>

#include <QDebug>
#include <QVariantMap>
#include <QVariant>

/*
QJsonDocument要求使用 Qt5

QJsonArray              封装 JSON 数组
QJsonDocument           读写 JSON 文档
QJsonObject             封装 JSON 对象
QJsonObject::iterator	用于遍历QJsonObject的 STL 风格的非 const 遍历器
QJsonParseError         报告 JSON 处理过程中出现的错误
QJsonValue              封装 JSON 值
*/

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QString json("{"
            "\"encoding\" : \"UTF-8\","
            "\"plug-ins\" : ["
            "\"python\","
            "\"c++\","
            "\"ruby\""
            "],"
            "\"indent\" : { \"length\" : 3, \"use_space\" : true }"
            "}");
    QJsonParseError jsonError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8(), &jsonError);

    if(jsonError.error == QJsonParseError::NoError){
        if(jsonDocument.isObject()){
            QVariantMap result = jsonDocument.toVariant().toMap();
            qDebug()<<"encoding:"<< result["encoding"].toString();
            qDebug()<<"plugins:";
            foreach (QVariant plugin, result["plug-ins"].toList()) {
                qDebug()<<"\t-" <<plugin.toString();

            }

            QVariantMap nestedMap = result["indent"].toMap();
            qDebug()<<"length:" <<nestedMap["length"].toInt();
            qDebug()<<"use_space:"<<nestedMap["use_space"].toBool();
        }
    }

}

Widget::~Widget()
{
    delete ui;
}
