#include "FileIO.h"

std::istream& operator>>(std::istream& inputs, Date& D)
{
    int day, month, year;

    inputs >> day;
    D.setDay(day);
    inputs.ignore(1, '/');


    inputs  >> month;
    D.setMonth(month);
    inputs.ignore(1, '/');

    inputs >> year;
    D.setYear(year);


    return inputs;
}


std::istream& operator>>(std::istream& inputs, Time& time)
{
    int hour, minute, second;
    char delimiter;

    inputs >> hour;
    time.setHour(hour);
    inputs.ignore();

    inputs >> minute;
    time.setMinute(minute);


    return inputs;
}


std::ostream& operator<<(std::ostream& os, const WeatherRecordsType& weatherRecord)
{
    os << weatherRecord.m_Date.getDay() << "/" << weatherRecord.m_Date.getMonth() << "/" << weatherRecord.m_Date.getYear() << " " << weatherRecord.m_Time.getHour() << ":" << weatherRecord.m_Time.getMinute() << ":" << weatherRecord.m_Time.getSecond()
       << ", Speed: " << weatherRecord.m_Speed << ", Solar Radiation: " << weatherRecord.m_SolarRadiation << ", Temperature: " << weatherRecord.m_Temperature << std::endl;

    return os;
}
