#ifndef CSVFILE_H
#define CSVFILE_H


#include "Vector.h"
#include "TextFile.h"
#include "TemplatedMap.h"
#include "BinarySearchTree.h"
#include "WeatherRecordsType.h"


#include <string>
#include <fstream>
#include <sstream>


    /**
     * @class  CsvFile
     * @brief  Used to read data from a Csv File
     *
     * This class enables the program to read data from a Csv File and store the data withn a Binary Search Tree, where each node contians a WeatherRecordsType struct
     * The class follows the SOLID Principles to ensure maintainability, and scalability. This is shown when the class utilizes the  Dependency Inversion Principle (DIP)
     * To decouple the CsvFile calss from TextFile class all while having a textfile object.
     *
     * Advantages of DIP:
     * Increased Modularity through reduced coupling between CsvFile and TextFile
     * Increased class maintainability and flexibility
     * This class was primarily utilized to read WeatherRecordsTypes into a binary search tree of weather records, while adhearing to the SOLID principles as the class had one function and that was to read a csv file

     * @author  William Halling 32233703
     * @date    April 2024
     * @version 0.5
     */
class CsvFile
{
    public:

            /**
             * @brief Default Constructor
             * Used to construct a CsvFile object.
             */
        CsvFile();


            /**
             * @brief Constructor with TextFile Dependency
             * Used to construct a CsvFile object.
             *
             * @param textfile the TextFile object to be used by CsvFile
             */
        CsvFile(const TextFile& textFile);


            /**
             * @brief Copy constructor
             * Used to construct a copy of the CsvFile Object
             *
             * @param otherFile the csvFile object to copy
             */
        CsvFile(const CsvFile& otherFile);


            /**
             * @brief Destructor
             * Used to destory the CsvFile object and release resources.
             */
       ~CsvFile();


            /**
             * @brief getColumnNumber()
             * Used to get the column numbers of our weather type IDS
             *
             * @param  columnData - the name of the columnData
             * @return the columnNumbers for WAST, SR, S & T
             */
        int getColumnNumber(const std::string& columnData) const;


            /**
             * @brief setRecords
             * Used to set the Vector for WeatherRecordsType
             *
             * @param BST<WeatherRecordsType> tempRecords
             */
        void setRecords(BST<WeatherRecordsType> tempRecords);


            /**
             * @brief getRecords
             * Used to get the Vector for WeatherRecordsType
             *
             * @return the BST with populated full of weatherRecordsStructs.
             */
        BST<WeatherRecordsType> getRecords() const;


            /**
             * @brief readFiles
             * Reads weather records from multiple csv files
             *
             * @param fileName The name of the CSV file to read.
             * @param recordedData The Bst that will be populated full of WeatherRecordsType
             */
        BST<WeatherRecordsType> getFileData(const TextFile textFile, BST<WeatherRecordsType>& recordedData);


    private:


        BST<WeatherRecordsType> m_Records;           /// a binary search tree of weatherRecordsType
        TemplatedMap<std::string, int> m_ColumnMap; ///  a map that contains the column numbers for the WAST, SR, S & T columns
        TextFile m_TextFile;                       ///  a refference to a TextFile Object


            /**
             * @brief getTextFile
             * Used to get the textFile object
             *
             * @return the TextFile object
             */
        const TextFile& getTextFile() const;


            /**
             * @brief getTextFile
             * Used to set a textFile object
             *
             * @param tempFile a temporary TextFile Object
             */
        void setTextFile(const TextFile& tempFile);


            /**
             * @brief findColumns
             * Finds the column numbers for WAST, S, SR, and T columns
             *
             * @param idCodes   the stringstream containing the columnIds containing the column ids
             * @param columnMap TemplatedMap<std::string, int>
             */
        void findColumns(std::stringstream& idCodes, TemplatedMap<std::string, int>& columnMap);


            /**
             * @brief readLine
             * Used to read a csv file line by line
             *
             * @param thisRow the current row from the CSV file
             * @param weatherRecords the BST of weatherRecordsType that will be populated full of weather records as row of the csv file is read
             */
        void readLine(const std::string& thisRow, BST<WeatherRecordsType>& weatherRecords);



            /**
             * @brief readDataFile
             * Reads weather records from a CSV file.
             *
             * @param fileName The name of the CSV file to read.
             * @param recordedData the BST of weatherRecordsType that will be populated full of weather records as each file is read
             */
        void readCSVFileData(const std::string& fileName, BST<WeatherRecordsType>& recordedData);


            /**
             * @brief processDateTime
             * Used to processes date and time
             *
             * @param thisRow the current row from the CSV file
             * @param weatherRecords object to store the processed date and time
             */
        void processDateTime(const std::string& dateTimeStr, WeatherRecordsType& weatherRecord);


            /**
             * @brief processSolarRadiation
             * Used to processes solar radiation
             *
             * @param solarStr the string containing solar radiation data
             * @param weatherRecords the weatherRecordsType object to store the processed data
             */
        void processSolarRadiation(const std::string& solarStr, WeatherRecordsType& weatherRecord);


            /**
             * @brief processTemperature
             * Used to processes temperature
             *
             * @param tempStr the string containing temperature data
             * @param weatherRecords the weatherRecordsType object to store the processed data
             */
        void processTemperature(const std::string& tempStr, WeatherRecordsType& weatherRecord);


            /**
             * @brief processSpeed
             * Used to process the speed data.
             *
             * @param speedStr  the string containing the speed data
             * @param weatherRecords the weatherRecordsType object to store the processed data
             */
        void processSpeed(const std::string& speedStr, WeatherRecordsType& weatherRecord);
};

#endif // CSV_H
