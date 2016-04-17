#ifndef WEATHERINFO_H
#define WEATHERINFO_H

#include <QtGlobal>
#include <QList>
#include <QDebug>
#include <QDateTime>

class WeatherDetail;

typedef QList<WeatherDetail*> WeatherDetailList;

class WeatherDetail
{
public:
    WeatherDetail();
    ~WeatherDetail();

    QString desc() const;
    void setDesc(const QString &desc);

    QString icon() const;
    void setIcon(const QString &icon);

private:
    QString m_sDesc, m_sIcon;
};

class WeatherInfo
{
public:
    WeatherInfo();
    ~WeatherInfo();

public:
    QString cityName() const;
    void setCityName(const QString &cityname);

    quint32 id() const;
    void setId(quint32 id);

    QDateTime dateTime() const;
    void setDateTime(const QDateTime &dateTime);

    float tempertuare() const;
    void setTempertuare(float tempertuare);

    float humidity() const ;
    void setHumidity(float humidity);

    float pressure() const;
    void setPressure(float pressure);

    WeatherDetailList details() const ;
    void setDetails(const WeatherDetailList details);

private:
    QString m_sCityname;
    quint32 m_quId;
    QDateTime m_oDateTime;
    float m_fTem, m_fHum, m_fPre;
    WeatherDetailList m_oDetails;

};

QDebug operator<<(QDebug dbg, const WeatherDetail &w);
QDebug operator<<(QDebug dbg, const WeatherInfo &w);

#endif // WEATHERINFO_H
