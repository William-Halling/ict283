#include "WeatherRecord.h"
#include "BinarySearchTree.h"
#include "TextFile.h"
#include "CsvFile.h"
#include "Options.h"
#include "Statistics.h"

#include <iostream>
#include <limits>

using BST = BinarySearchTree<WeatherRecord>;

void menu(BST& records);

int main()
{
    try
    {
        io::TextFile fileList;
        fileList.loadFrom("data/data_source.txt");

        io::CsvFile parser(fileList);
        BST records;
        parser.loadAllInto(records);

        menu(records);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';

        return 1;
    }

    return 0;
}


void menu(BST& records)
{
    weather::Statistics stats;
    ui::Options options;

    int choice;
    do
    {
        options.displayMenu();
        choice = options.getUserChoice();

        int month = 0;
        int year = 0;

        switch (choice)
        {
            case 1:
            {
                month = options.getValidMonth();
                year = options.getValidYear();
                stats.clear();
                records.inOrderTraverse(collectWindSpeeds, month, year, stats);
                options.showWindspeedStats(month, year, stats);
                break;
            }
            case 2:
            {
                year = options.getValidYear();
                stats.clear();

                for (int m = 1; m <= 12; ++m)
                {
                    records.inOrderTraverse(collectTemperature, m, year, stats);
                    options.showTemperatureStats(m, year, stats);
                    stats.clear();
                }
                break;
            }
            case 3:
            {
                month = options.getValidMonth();
                stats.clear();
                records.inOrderTraverse(collectAllMetrics, month, 0, stats);
                options.showSolarRadiationStats(month, stats);
                break;
            }

            case 5:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice.\n";
                break;
        }
    }
    while (choice != 5);
}
