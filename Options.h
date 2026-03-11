#ifndef OPTIONS_H
#define OPTIONS_H

#include <iostream>
#include <limits>

#include "Date.h"
#include "Vector.h"
#include "Statistics.h"
#include "TemplatedMap.h"

    /**
     * @class   Options
     * @brief   A class that is utilized to process options 1 - 4
     * This class follows the solid principles as it deals wiht the main functionality of processing the option entered
     * @author  William Halling 32233703
     * @date    April 2024
     * @version 0.3
     */
class Options
{
    public:
            /**
             * @brief Default Constructor
             * Used to construct a Options object.
             */
        Options();


            /**
             * @brief Parameterized Constructor
             * Used to construct an Options object with a Statistics Object
             *
             * @param statistics Statistics object used to perform calculations
             */
        Options(const Statistics& statistics);


            /**
             * @brief Destructor
             * Used to destory the Options object and release resources.
             */
       ~Options();


            /**
             * @brief getStatistics()
             * Used to get statistics object so calculations can be performed.
             *
             * @return m_Statistics Statistics object
             */
        const Statistics& getStatistics() const;


            /**
             * @brief setStatistics()
             * Used to set a Statistics Object for our Options class
             *
             * @param newStats Statistics Object used for calculations
             */
        void setStatistics(const Statistics& newStats);


            /**
             * @brief getValidYear()
             * Prompts the user to enter a year
             *
             * @return the year entered by the user
             */
        int getValidYear();


            /**
             * @brief getValidMonth()
             * Prompts the user to enter a month
             *
             * @return the month entered by the user
             */
        int getValidMonth();


            /**
             * @brief getValidInput()
             * Prompts the user to enter an option from the menu
             *
             * @return the option entered by the user
             */
        int getValidInput();


            /**
             * @brief displayOptions()
             * Used to present the menu of options to the user
             */
        void displayOptions();


            /**
             * @brief displayWindspeedData()
             * Takes our recordedWeatherData vector and filters it based on the month and year entered
             * Then displays the Average and standard deviation of windspeed
             *
             * @param recordedData The Vector of WeatherRecordsType
             */
        void displayWindspeedData(int month, int year, const Statistics& stats) const;


            /**
             * @brief displayTemperatureData()
             * Takes our recordedWeatherData vector and filters it based off of the year entered
             * Displays the average and stddev of temperature for each month the entered the year
             *
             * @param recordedData the Vector of WeatherRecordsType
             */
         void displayTemperatureData(int month, int year, Statistics& stats);


            /**
             * @brief displaySPCCData()
             * Used to display no data
             *
             * @param recordedData The Vector of WeatherRecordsType
             * @param enteredYear The year entered by the user
             */
        void displaySPCCData(int month, const Statistics& stats) const;

    private:

            /**
             * @brief displayNoData
             * Used to display no data
             * @param monthName the name of the month that has no data
             * @param the year which has no data
             * @return name of the month based off of the month entered
             */
        void displayNoData(const std::string& monthName, int year) const;


        Statistics m_Stats;       ///Statistics an object used to perform statisitcs on the WeatherRecordsType Vector
};



namespace DateUtility
{
        /**
         * @brief convertName
         * Used to convert the name of the month to a string
         *
         * @return name of the month based off of the month entered
         */
    std::string convertName(int enteredMonth);


        /**
         * @brief getEnteredMonthName
         * Used to getEnteredMonthName the month the user wants to recieve
         *
         * @param  enteredMonth - a temporary int variable as a range between 1 - 12 for the names of the month.
         * @return name of the month as an std::string
         */
    std::string getEnteredMonthName(int enteredMonth);


    const int MAX_MONTHS = 12;
}

#endif // OPTIONS_H
