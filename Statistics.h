#ifndef STATISTICS_H
#define STATISTICS_H

#include <cmath>
#include <fstream>
#include <iostream>


#include "WeatherRecordsType.h"
#include "BinarySearchTree.h"
#include "Vector.h"
#include "Node.h"


    /**
     * @class   Statistics
     * @brief   A class that is utilized to perform statistical calculations on our Vector such as calculating the total, the average and stdDev
     * This class provides the functionality to calculate total, average, standard deviation and correlation coefficient of weather data
     * collects weather records from a binary search tree based on month and year
     * This class adhears to SOLID principles for scaleability and maintainability.
     *
     * @author  William Halling 32233703
     * @date    June 2024
     * @version 0.5
     */
class Statistics
{
    public:
            /**
             * @brief Statistics Default Constructor
             * Used to create a Statistics object enabling access to our calculate functions.
             */
        Statistics();


            /**
             * @brief Statistics Copy Constructor
             * Used to create a copy of the Statistics object
             */
        Statistics(const Statistics& otherStats);


            /**
             * @brief Destructor
             * Used to destory the Statistics object and release resources.
             */
        ~Statistics();


            /**
             * @brief getWindspeeds()
             * Retrieves the windspeeds Vector
             * @return m_Windspeeds a vector of floats
             */
        Vector<float> getWindspeeds() const;


            /**
             * @brief getSolarRadiation()
             * Used to get the solar radiation Vector
             * @return the m_Solar float Vector
             */
        Vector<float> getSolarRadiation() const;


            /**
             * @brief getTemperatures()
             * Used to get the temperature Vector
             * @param  month - the current month to retrieve
             * @return the m_Temperature float vector
             */
        Vector<float> getTemperatures() const;


            /**
             * @brief setWindspeeds
             * Used to set a vector of windspeed floats
             * @param windspeed a series of windspeeds floats from the binary search tree
             */
        void setWindspeeds(float windspeed);


            /**
             * @brief setTemperatures()
             * Used to set a vector full of temperature floats
             * @param tempTemperatures a series of temperature floats from the binary search tree
             */
        void setTemperatures(float temperature);


            /**
             * @brief setSolarRadiation
             * Used to set a vector full of solarRadiation floats
             * @param tempSolar the
             */
        void setSolarRadiation(float tempSolar);



            /**
             * @brief clearData()
             * Used to clear the data within each of the vectors
             */
        void clearData();


            /**
             * @brief roundStats
             * Used to round statistics to one decimal places
             *
             * @param  value to be rounded to one decmial place
             * @return float the rounded statistic
             */
        float roundStats(float value) const;


            /**
             * @brief  calculateTotal
             * @brief  calculates the total value from the data stored within vector
             *
             * @param  recordedData the vector which contains our recorded data
             * @return m_Total- the total of the set of values
             */
        float calculateTotal(const Vector<float>& recordedData) const;


            /**
             * @brief  calculateAverage
             * @brief  calculates the average value from the data stored within vector
             *
             * @param  recordedData the vector which contains our recorded data
             * @return m_Average - the average of the set of values
             */
        float calculateAverage(const Vector<float>& recordedData) const;


            /**
             * @brief  calculateStdDev
             * @brief  calculates the standard deviation from the set of data stored within vector
             *
             * @param  recordedData the vector which contains our recorded data
             * @param  average value of the recoded data
             * @return m_StdDev - the standard deviation
             */
        float calculateStdDev(const Vector<float>& recordedData, float average) const;



            /**
             * @brief  calculateSPCC
             * @brief  calculates the Sample Pearson Coefficient between two vectors
             *
             * @param  VectorA the first vector in the data set
             * @param  VectorB the second Vector in the data set
             * @return the spcc for a given weather type
             */
        float calculateSPCC(const Vector<float>& VectorA, const Vector<float>& VectorB) const;


    private:

        Vector<float> m_Windspeeds;     /// vector of floats radition used to store all the used to store all the windspeeds of an entered date
        Vector<float> m_Temperatures;   /// vector of floats used to store all the temperatures of an entered date
        Vector<float> m_Solar;          /// vector of floats solar radition used to store all the solar radiation of an entered date
        float m_Total;                  ///the total   of a set of numbers within our vector used for getting the total  of a weather statistic such as windspeed,  or temperature
        float m_Average;                ///the average of a set of numbers within our vector used for getting the average of a weather statistic such as windspeed, or temperature
        float m_StdDev;                 ///the stdDev  of a set of numbers within our vector used for getting the standard deviation of a weather statistic such as windspeed, or temperature


            /**
             * @brief  divideByZero
             * @brief  Checks if we are attempting to divide by 0
             *
             * @param  recordedData the vector which contains recorded weather data
             * @return true if recorded data is empty otherwise return false
             */
        bool divideByZero(const Vector<float>& recordedData) const;
};
#endif
