#include "Date.h"

Date::Date() : m_Day(), m_Month(), m_Year()
{

}


Date::Date(int newDay, int newMonth, int newYear)
{
    if(isValidDate(newDay, newMonth, newYear))
    {
        m_Day   = newDay;
        m_Month = newMonth;
        m_Year  = newYear;
    }
    else
    {
        std::cerr << "Invalid Date. Date set to a default value of 01/01/1900 dd/mm/yyyy " << std::endl;

        m_Day   = 1;
        m_Month = 1;
        m_Year  = 1900;
    }
}


Date::~Date()
{
    //dtor
}


Date::Date(const Date& otherDate)
{
    m_Day   = otherDate.m_Day;
    m_Month = otherDate.m_Month;
    m_Year  = otherDate.m_Year;

}


Date& Date::operator=(const Date& otherDate)
{
    if (this != &otherDate)
    {
        m_Day   = otherDate.m_Day;
        m_Month = otherDate.m_Month;
        m_Year  = otherDate.m_Year;
    }

    return *this;
}


bool Date::operator==(const Date& otherDate) const
{
    return (m_Year == otherDate.m_Year && m_Month == otherDate.m_Month && m_Day == otherDate.m_Day);
}


bool Date::operator!=(const Date& otherDate) const
{
    return !(*this == otherDate);
}


bool Date::operator<(const Date& otherDate) const
{
    if (m_Year < otherDate.m_Year)
    {
        return true;
    }

    if (m_Year == otherDate.m_Year && m_Month < otherDate.m_Month)
    {
        return true;
    }

    if(m_Year == otherDate.m_Year && m_Month == otherDate.m_Month && m_Day < otherDate.m_Day)
    {
        return true;
    }

    return false;
}


bool Date::operator>(const Date& otherDate) const
{
    return otherDate < *this;
}


int Date::getDay() const
{
    return m_Day;
}


int Date::getMonth() const
{
    return m_Month;
}


int Date::getYear() const
{
    return m_Year;
}


void Date::setDay(int tempDay)
{
    if (!isValidDay(tempDay))
    {
        throw std::invalid_argument("Invalid Day: " + std::to_string(tempDay));
    }

    m_Day = tempDay;
}


void Date::setMonth(int tempMonth)
{
    if (!isValidMonth(tempMonth))
    {
        throw std::invalid_argument("Invalid Month: " + std::to_string(tempMonth));
    }

    m_Month = tempMonth;
}


void Date::setYear(int tempYear)
{
    if (!isValidYear(tempYear))
    {
        throw std::invalid_argument("Invalid Year: " + std::to_string(tempYear));
    }

    m_Year = tempYear;
}


bool Date::isValidDay(int checkDay) const
{
    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    int maximumDays = daysInMonth[m_Month];


    if(m_Month == 2 && isLeapYear(m_Year))
    {
        maximumDays++;
    }

    return (checkDay >= 1 && checkDay <= maximumDays);
}


bool Date::isValidMonth(int checkMonth) const
{
    return (checkMonth >= 1 && checkMonth <= 12);
}


bool Date::isValidYear(int checkYear) const
{
    return (checkYear >= 0 && checkYear <= 2100);
}


bool Date::isLeapYear(int year) const
{
    return (year % 400 == 0 || (year % 4 == 0 && year %100 != 0));
}


bool Date::isValidDate(int day, int month, int year) const
{
    if(!isValidYear(year) || !isValidMonth(month))
    {
        return false;
    }

    return isValidDay(day);
}
