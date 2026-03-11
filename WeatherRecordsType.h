#ifndef WEATHERRECORDSTYPE_H
#define WEATHERRECORDSTYPE_H


#include "Date.h"
#include "Time.h"


    /**
     * @brief   WeatherRecordsType
     * @brief   A struct for holding the WeatherRecordsType
     *
     * @author  William Halling
     * @date    May 2024
     * @version 0.5
     * @note    Updated and added doccumentation to the struct
     */
struct WeatherRecordsType {
    Date m_Date;       // date
    std::string m_Time; // HH:MM format
    float m_Speed;     // wind speed
    float m_SolarR;    // solar radiation
    float m_Temperature;

    friend std::ostream& operator<<(std::ostream& os, const WeatherRecordsType& record) {
        os << record.m_Date << " " << record.m_Time 
           << " Temp: " << record.m_Temperature 
           << " Wind: " << record.m_Speed 
           << " Solar: " << record.m_SolarR;
        return os;
    }
};

#endif // WEATHERRECORDSTYPE_H
