#include "Time.h"

Time::Time() : m_Hour(), m_Minute(), m_Second()
{}


Time::~Time()
{
    //dtor
}


Time::Time(int tempHour, int tempMinute, int tempSecond) : m_Hour(tempHour), m_Minute(tempMinute), m_Second(tempSecond)
{

}


Time::Time(const Time& otherTime) : m_Hour(otherTime.m_Hour), m_Minute(otherTime.m_Minute), m_Second(otherTime.m_Second)
{

}


const Time& Time::operator=(const Time& otherTime)
{
    if (this != &otherTime)
    {
        m_Hour   = otherTime.m_Hour;
        m_Minute = otherTime.m_Minute;
        m_Second = otherTime.m_Second;
    }

    return *this;
}


bool Time::operator ==(const Time& otherTime) const
{
    return (m_Hour == otherTime.m_Hour && m_Minute == otherTime.m_Minute && m_Second == otherTime.m_Second);
}


bool Time::operator<(const Time& otherTime) const
{
    if (m_Hour < otherTime.m_Hour)
    {
        return true;
    }
    if (m_Hour == otherTime.m_Hour && m_Minute < otherTime.m_Minute)
    {
        return true;
    }
    return false;
}


bool Time::operator>(const Time& otherTime) const
{
    if (m_Hour > otherTime.m_Hour)
    {
        return true;
    }
    if (m_Hour == otherTime.m_Hour && m_Minute > otherTime.m_Minute)
    {
        return true;
    }
    return false;
}


bool Time::operator!=(const Time& otherTime) const
{
    return !(*this == otherTime);
}


int Time::getHour()   const { return m_Hour;   }
int Time::getMinute() const { return m_Minute; }
int Time::getSecond() const { return m_Second; }


void Time::setSecond(int newSecond)
{
    if(!isValidTime(newSecond))
    {
        throw std::invalid_argument("Invalid Second: " + std::to_string(newSecond));
    }

    m_Second = newSecond;
}


void Time::setMinute(int newMinute)
{
    if(!isValidTime(newMinute))
    {
        throw std::invalid_argument("Invalid Minute: " + std::to_string(newMinute));
    }

    m_Minute = newMinute;
}


void Time::setHour(int newHour)
{
    if(!isValidHour(newHour))
    {
        throw std::invalid_argument("Invalid Hour: " + std::to_string(newHour));
    }

    m_Hour = newHour;
}


bool Time::isValidTime(int newTime) const
{
    return (newTime >= 0 && newTime <= 59);
}


bool Time::isValidHour(int checkHour) const
{
    return (checkHour >= 0 && checkHour <= 23);
}
