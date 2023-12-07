#include <iostream>
#include "DataAnalyzer.h"
#include "DataManager.h"

int main() {
    //DataAnalyzer analyzer;
    //analyzer.start();
    
    DataManager dataManager;
    std::map<std::string, std::vector<std::string>> importedDataset = dataManager.importDataset("..\\resouces\\AverageWorldTemp2020.csv", ',');
    std::cout << "Keys in the Dataset:";
    for (auto it = importedDataset.begin(); it != importedDataset.end(); ++it) {
        std::cout << it->first << " ";
    }

    std::getchar();
    return 0;
}