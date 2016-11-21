#include "weatherinfo.h"

WeatherInfo::WeatherInfo()
{
}


//QDebug operator<<(QDebug dbg, const WeatherDetail &w)
//{
//    dbg.nospace() << "("
//                  << "Description: " << w.desc() << "; "
//                  << "Icon: " << w.icon()
//                  << ")";
//    return dbg.space();
//}

//QDebug operator <<(QDebug dbg, const WeatherInfo &w)
//{
//    dbg.nospace() << "("
//                  << "id: " << w.id() << "; "
//                  << "City name: " << w.cityName() << "; "
//                  << "Date time: " << w.dateTime().toString(Qt::DefaultLocaleLongDate) << ": " << endl
//                  << "Temperature: " << w.temperature() << ", "
//                  << "Pressure: " << w.pressure() << ", "
//                  << "Humidity: " << w.humidity() << endl
//                  << "Details: [";
//    foreach (WeatherDetail *detail, w.details()) {
//        dbg.nospace() << "( Description: " << detail->desc() << ", "
//                      << "Icon: " << detail->icon() << "), ";
//    }
//    dbg.nospace() << "] )";
//    return dbg.space();
//}
