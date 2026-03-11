#include "CsvFile.h"
#include <iostream>


CsvFile::CsvFile() : m_Records(), m_ColumnMap(), m_TextFile()
{
    m_ColumnMap.setMappedData("WAST", -1);
    m_ColumnMap.setMappedData("S", -1);
    m_ColumnMap.setMappedData("SR", -1);
    m_ColumnMap.setMappedData("T", -1);

}


CsvFile::CsvFile(const CsvFile& otherFile) : m_Records(otherFile.m_Records), m_ColumnMap(otherFile.m_ColumnMap), m_TextFile(otherFile.m_TextFile) {}



CsvFile::~CsvFile() {}



BST<WeatherRecordsType> CsvFile::getRecords() const
{
    return m_Records;
}


void CsvFile::setRecords(BST<WeatherRecordsType> tempRecords)
{
    m_Records = tempRecords;
}


const TextFile& CsvFile::getTextFile() const
{
    return m_TextFile;
}


void CsvFile::setTextFile(const TextFile& tempFile)
{
    m_TextFile = tempFile;
}


int CsvFile::getColumnNumber(const std::string& columnName) const
{
    if (m_ColumnMap.contains(columnName))
    {
        return m_ColumnMap.getData(columnName);
    }

    return -1;
}


void CsvFile::findColumns(std::stringstream& idCodes, TemplatedMap<std::string, int>& columnMap)
{
    std::string columnID;

    int columnCount = 0;


    while(std::getline(idCodes, columnID, ','))
    {
        if(columnMap.contains(columnID))
        {
            columnMap.setMappedData(columnID, columnCount);
        }

        columnCount++;
    }
}



void CsvFile::readCSVFileData(const std::string& fileName, BST<WeatherRecordsType>& recordedData)
{
    std::ifstream infile(fileName);

    if (!infile)
    {
        throw std::runtime_error("Error: could not find file " + fileName);

        return;
    }


    std::string header;
    std::getline(infile, header);
    std::stringstream headerStream(header);

    findColumns(headerStream, m_ColumnMap);
    std::string currentLine;


    while (std::getline(infile, currentLine))
    {
        readLine(currentLine, m_Records);
    }

    infile.close();
}



BST<WeatherRecordsType> CsvFile::getFileData(const TextFile textFile, BST<WeatherRecordsType>& recordedData)
{
    Vector<std::string> dataFiles = textFile.getDataFiles();

    for(int i = 0; i < dataFiles.size(); ++i)
    {
        readCSVFileData(dataFiles[i], recordedData);
    }

    return m_Records;
}


void CsvFile::readLine(const std::string& thisRow, BST<WeatherRecordsType>& weatherRecords)
{
    std::stringstream currentRow(thisRow);
    WeatherRecordsType tempWeatherRecords;

    std::string columnData;


    int currentColumn = 0;

    while (std::getline(currentRow, columnData, ','))
    {
        if (currentColumn == m_ColumnMap.getData("WAST"))
        {
            processDateTime(columnData, tempWeatherRecords);
        }


        else if (currentColumn == m_ColumnMap.getData("SR"))
        {
            processSolarRadiation(columnData, tempWeatherRecords);
        }


        else if (currentColumn == m_ColumnMap.getData("T"))
        {
            processTemperature(columnData, tempWeatherRecords);
        }


        else if (currentColumn == m_ColumnMap.getData("S"))
        {
            processSpeed(columnData, tempWeatherRecords);
        }

        currentColumn++;
    }
    weatherRecords.insert(tempWeatherRecords);
}


void CsvFile::processDateTime(const std::string& dateTimeStr, WeatherRecordsType& weatherRecord)
{
    std::stringstream dateTimeStream(dateTimeStr);

    dateTimeStream >> weatherRecord.m_Date >> weatherRecord.m_Time;
}



void CsvFile::processSolarRadiation(const std::string& solarStr, WeatherRecordsType& weatherRecord)
{
    float solarData = 0.0f;

    std::stringstream solarRadiationSS(solarStr);
    solarRadiationSS >> solarData;
    weatherRecord.m_SolarRadiation = solarData * (1.0 / 6.0) / 100.0;
}


void CsvFile::processTemperature(const std::string& tempStr, WeatherRecordsType& weatherRecord)
{
    std::stringstream temperatureSS(tempStr);

    temperatureSS >> weatherRecord.m_Temperature;
}


void CsvFile::processSpeed(const std::string& speedStr, WeatherRecordsType& weatherRecord)
{
    std::stringstream speedSS(speedStr);

    speedSS >> weatherRecord.m_Speed;
}
