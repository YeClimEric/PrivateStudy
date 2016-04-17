#include "weatherinfo.h"

WeatherInfo::WeatherInfo()
{
}

WeatherInfo::~WeatherInfo()
{

}

QString WeatherInfo::cityName() const
{
    return m_sCityname;
}

void WeatherInfo::setCityName(const QString &cityname)
{
    m_sCityname = cityname;
}

quint32 WeatherInfo::id() const
{
    return m_quId;
}

void WeatherInfo::setId(quint32 id)
{
    m_quId = id;
}

QDateTime WeatherInfo::dateTime() const
{
    return m_oDateTime;
}

void WeatherInfo::setDateTime(const QDateTime &dateTime)
{
    m_oDateTime = dateTime;
}

float WeatherInfo::tempertuare() const
{
    return m_fTem;
}

void WeatherInfo::setTempertuare(float tempertuare)
{
    m_fTem = tempertuare;
}

float WeatherInfo::humidity() const
{
    return m_fHum;
}

void WeatherInfo::setHumidity(float humidity)
{
    m_fHum = humidity;
}

float WeatherInfo::pressure() const
{
    return m_fPre;
}

void WeatherInfo::setPressure(float pressure)
{
    m_fPre = pressure;
}

WeatherDetailList WeatherInfo::details() const
{
    return m_oDetails;
}

void WeatherInfo::setDetails(const WeatherDetailList details)
{
    m_oDetails = details;
}


WeatherDetail::WeatherDetail()
{

}

WeatherDetail::~WeatherDetail()
{

}

QString WeatherDetail::desc() const
{
    return m_sDesc;
}

void WeatherDetail::setDesc(const QString &desc)
{
    m_sDesc = desc;
}

QString WeatherDetail::icon() const
{
    return m_sIcon;
}

void WeatherDetail::setIcon(const QString &icon)
{
    m_sIcon = icon;
}


QDebug operator<<(QDebug dbg, const WeatherDetail &w)
{
    dbg.nospace() << "("
                  <<"Description:" <<w.desc()<<";"
                 <<"Icon:"<<w.icon()
                <<")";
    return dbg.space();
}


QDebug operator<<(QDebug dbg, const WeatherInfo &w)
{
    dbg.nospace() << "("
                      << "id: " << w.id() << "; "
                      << "City name: " << w.cityName() << "; "
                      << "Date time: " << w.dateTime().toString(Qt::DefaultLocaleLongDate) << ": " << endl
                      << "Temperature: " << w.tempertuare() << ", "
                      << "Pressure: " << w.pressure() << ", "
                      << "Humidity: " << w.humidity() << endl
                      << "Details: [";
    foreach (WeatherDetail *detail, w.details()) {
        dbg.nospace() << "( Description: " << detail->desc() << ", "
                      << "Icon: " << detail->icon() << "), ";
    }
    dbg.nospace() << "]";

    return dbg.space();
}
