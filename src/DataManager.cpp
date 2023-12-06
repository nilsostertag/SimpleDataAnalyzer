#include <iostream>
#include <fstream>
#include <sstream>

#include "DataManager.h"

std::map<std::string, std::vector<std::string>> DataManager::importDataset(std::string path) {
    
    std::map<std::string, std::vector<std::string>> importedDataset;
    
    std::ifstream file(path);

    if(!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return importedDataset;
    }


}

std::vector<std::string> DataManager::retrievePropsFromLine(std::string line) {
    std::vector<std::string> retrievedProps;

    
}