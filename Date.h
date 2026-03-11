#ifndef DATE_H
#define DATE_H

#include <iostream>

    /**
     * @class Date
     * @brief This class is utilized to store and contain date information such as day, month, year.
     *        Provides functionality to create, modify and compare date objects
     *
     *
     * @version 0.4
     * @date    May 2024
     * @author  William Halling
     */
class Date
{
    public:
            /**
             * @brief Default constructor.
             * @brief Used to create a date object
             */
        Date();


            /**
             * @brief Non Default constructor.
             * @param newDay   int value to set the day
             * @param newMonth int value to set the month
             * @param newYear  int value to set the year
             */
        Date(int newDay, int newMonth, int newYear);


            /**
             * @brief Date Copy Constructor
             * @param otherDate The date object to copy data from
             * @return a copy of a date object
             */
        Date(const Date& otherDate);


            /**
             * @brief  Destructor.
             * Used to destory the Date object and release resources.
             * @return destroyed Date object / NA
             */
       ~Date();


            /**
             * @brief  setYear()
             * @brief  Used to set the year value with a temporary year
             * @param  newYear an integer used to set the year variable
             */
        void setYear(int newYear);


            /**
             * @brief  setMonth()
             * Used to set the month value with a temporary month
             * @param  newMonth an integer used to set the month variable
             */
        void setMonth(int newMonth);


            /**
             * @brief  setDay()
             *         Used to set the day value with a temporary day
             * @param  newDay an integer used to set the day variable
             */
        void setDay(int newDay);


            /**
             * @brief  getYear()
             * Used to get the year
             * @return an integer representing the year
             */
        int getYear() const;


            /**
             * @brief  getMonth()
             * Used to get the month
             * @return an integer representing the month
             */
        int getMonth() const;


            /**
             * @brief  getDay()
             * Used to get the day
             * @return an integer representing the day
             */
        int getDay() const;


            /**
             * @brief  asignment operator.
             * Used to assign the values of one date to another date object, allowing for deep copies of date objects to be made
             * @param  otherDate the date object to assign values from
             * @return A referenence to the assigned date object
             */
        Date& operator=(const Date& otherDate);


            /**
             * @brief  Equality operator.
             * Used to compare one Date object against another date object
             * @param  otherDate the Date object to compare against
             * @return true if one date object equals another date object, false otherwise
             */
        bool operator==(const Date& otherDate) const;


            /**
             * @brief  Less than operator
             * Used to check if one date is less than / a day or month or year before the other
             * @param  otherDate the Date object to compare against
             * @return bool true if one date is less than the other date. e.g 1/1/2020 1/2/2020
             */
        bool operator<(const Date& otherDate) const;


            /**
             * @brief  greater than operator
             * Used to check if one date is greater than / a day or month or year before the other
             * @param  otherDate the Date object to compare against
             * @return bool true if one date is less than the other date. e.g 1/1/2020 1/2/2020
             */
        bool operator>(const Date& otherDate) const;


            /**
             * @brief  Not Equals operator
             * Used to check if one date object doesnt equal another date object
             * @param  otherDate - Date object to compare against
             * @return bool true if dates are not equal else false
             */
        bool operator!=(const Date& otherDate) const;


            /**
             * @brief  isValidMonth
             * checks if the month is between the range of 1 to 12
             * @param  checkMonth the month to validate
             * @return True if the month is valid false otherwise
             */
        bool isValidMonth(int checkMonth) const;


            /**
             * @brief  isValidYear
             * checks if the year is between the range of 1900 to 2100
             * @param  checkYear the year to validate
             * @return True if the year is valid false otherwise
             */
        bool isValidYear(int checkYear) const;


    private:

        int m_Day;      /// day of the month
        int m_Month;    /// month of the year as an int range between 1 and 12
        int m_Year;     /// The Year as an int


            /**
             * @brief  isValidDay
             * checks if the day is valid for current month and year
             * @param  checkDay the day to validate
             * @return True if the day is valid false otherwise
             */
        bool isValidDay(int checkDay) const;


            /**
             * @brief  isLeapYear
             * checks if the year is a leap year or not
             * @param  year the year to check
             * @return True if the year is a leap year false otherwise
             */
        bool isLeapYear(int year) const;


            /**
             * @brief  isValidDate
             * validates the entire date, by checking if the day month and year form a valid date.
             * @param  day   an integer representing the day
             * @param  month an integer representing the month
             * @param  year an integer representing the  year
             * @return True if the date is valid, false otherwise
             */
        bool isValidDate(int day, int month, int year) const;
};

std::istream& operator>>(std::istream& inputs, Date& D);


#endif // DATE_H
