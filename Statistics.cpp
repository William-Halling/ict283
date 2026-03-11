#include "Statistics.h"

Statistics::Statistics(){}

Statistics::Statistics(const Statistics& otherStats)
{
    m_Total        = otherStats.m_Total;
    m_Average      = otherStats.m_Average;
    m_StdDev       = otherStats.m_StdDev;
    m_Windspeeds   = otherStats.m_Windspeeds;
    m_Temperatures = otherStats.m_Temperatures;
    m_Solar        = otherStats.m_Solar;
}

Statistics::~Statistics()
{

}

void Statistics::clearData()
{
    m_Windspeeds.clear();
    m_Temperatures.clear();
    m_Solar.clear();
}


Vector<float> Statistics::getWindspeeds() const
{
    return m_Windspeeds;
}


Vector<float> Statistics::getSolarRadiation() const
{
    return m_Solar;
}


Vector<float> Statistics::getTemperatures() const
{
    return m_Temperatures;
}


void Statistics::setWindspeeds(float windspeed)
{
    m_Windspeeds.push_back(windspeed);
}



void Statistics::setTemperatures(float temperature)
{
    m_Temperatures.push_back(temperature);
}


void Statistics::setSolarRadiation(float tempSolar)
{
    m_Solar.push_back(tempSolar);
}



bool Statistics::divideByZero(const Vector<float>& recordedData) const
{
    return recordedData.size() == 0;
}


float Statistics::roundStats(float value) const
{
    return roundf(value * 10.0f) / 10.0f;
}


float Statistics::calculateTotal(const Vector<float>& recordedData) const
{
    float total = 0.0f;

    for(int i = 0; i < recordedData.size(); ++i)
    {
        total += recordedData[i];
    }

    return total;
}


float Statistics::calculateAverage(const Vector<float>& recordedData) const
{
    float total = calculateTotal(recordedData);


    return total / recordedData.size();
}


float Statistics::calculateStdDev(const Vector<float>& recordedData, float average) const
{
    float sqrdRangeDif = 0.0f;

    for(int i = 0; i < recordedData.size(); ++i)
    {
         float variation = recordedData[i] - average;

         sqrdRangeDif   += variation * variation;
    }

    float range = sqrdRangeDif / recordedData.size();


    return sqrt(range);
}



float Statistics::calculateSPCC(const Vector<float>& VectorA, const Vector<float>& VectorB) const
{
    int numItems = VectorA.size();

    float meanVectorA = calculateAverage(VectorA);
    float meanVectorB = calculateAverage(VectorB);
    float numerator = 0.0;
    float totalSquaredDifferenceA  = 0.0;
    float totalSquaredDifferenceB  = 0.0;


    for(int i = 0; i < numItems; ++i)
    {
        float varianceA           = VectorA[i] - meanVectorA;
        numerator                += varianceA * (VectorB[i] - meanVectorB);
        totalSquaredDifferenceA  += varianceA * varianceA;
    }

    for(int i = 0; i < numItems; ++i)
    {
        float varianceB          = VectorB[i] - meanVectorB;
        totalSquaredDifferenceB += varianceB * varianceB;
    }

    float denominator = std::sqrt(totalSquaredDifferenceA * totalSquaredDifferenceB);

    float spcc = numerator / denominator;
    //std::cout << "SPCC: " << spcc << std::endl;
    return std::round(spcc * 100) / 100;
}
