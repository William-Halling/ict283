#ifndef FILEIO_H
#define FILEIO_H

#include "WeatherRecordsType.h"
#include "Date.h"
#include "Time.h"

    /**
     * @brief: istream& operator>>(std::istream& inputs, Time&T);
     * Used to overload the input operator for reading time from a file to the input stream
     * @param inputs the input stream form which data is read
     * @param T the time object used to set time variables
     * @return the inputs the input stream object
     **/
std::istream& operator>>(std::istream& inputs, Time& T);

/**
 * @brief: istream& operator>>(std::istream& inputs, Date&D);
 * Used to overload the input operator for reading dates from a file to a istream object
 * @param inputs the input stream form which data is read
 * @param D the date object used to set date variables
 * @return the inputs the input stream object
 **/
std::istream& operator>>(std::istream& inputs, Date& D);


/**
 * @brief: ostream& operator>>(std::ostream& os, WeatherRecordsType& weatherRecords);
 * Used to overload the outputs operator for writting WeatherRecordsType to a file to the output stream
 * @param os the output stream form which written
 * @param weatherRecordsType WeatherRecords the object to write weatherRecords to a file
 * @return the os the output stream object
 **/
std::ostream& operator<<(std::ostream& os, const WeatherRecordsType& weatherRecords);



#endif // FILEIO_H
