#include <iostream>
#include "DataAnalyzer.h"
#include "DataManager.h"

int main() {
    //DataAnalyzer analyzer;
    //analyzer.start();
    
    DataManager dataManager;
    std::map<std::string, std::vector<std::string>> importedDataset = dataManager.importDataset("..\\resouces\\AverageWorldTemp2020.csv", ',');
    std::cout << "Dataset:" << std::endl;
    for (auto it = importedDataset.begin(); it != importedDataset.end(); ++it) {
        std::cout << it->first << "\t";
    }
    std::string selector = "Jan";
    std::vector<std::string> selected = importedDataset[selector];

    for(std::string value : selected) {
        std::cout << value << std::endl;
    }

    DataAnalyzer dataAnalyzer;
    dataAnalyzer.calculateMean(selector, selected);

    std::getchar();
    return 0;
}