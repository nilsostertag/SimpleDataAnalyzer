#include <iostream>
#include <fstream>
#include <sstream>

#include <DataManager.h>

std::map<std::string, std::vector<std::string>> DataManager::importDataset(const std::string& path, const char* separator) {
    
    std::map<std::string, std::vector<std::string>> importedDataset;
    
    std::ifstream file(path);

    if(!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return importedDataset;
    }

    std::string line;
    bool isFirstLine = true;

    std::vector<std::string> mapKeys;
    int linecounter = 0;
    while(std::getline(file, line)) {
        if(isFirstLine) {
            mapKeys = retrievePropsFromLine(line, separator);
            isFirstLine = false;
        }
        else {
            std::vector<std::string> properties = retrievePropsFromLine(line, separator);
            if(mapKeys.size() == properties.size()) {
                for(int i = 0; i < mapKeys.size(); i++) {
                try {
                    std::string key = mapKeys[i];
                    importedDataset[key].push_back(properties[i]);
                    linecounter++;
                } catch (const std::string err) {
                    std::cerr << "Error: " << err << std::endl;
                    }
                }
            }
        }
    }
    std::cout << "Dataset import succeeded." << std::endl;
    std::cout << "Keys found: " << mapKeys.size() << std::endl;
    std::cout << "Total lines imported: " << linecounter << std::endl;
    return importedDataset;
}

std::vector<std::string> DataManager::retrievePropsFromLine(const std::string& line, const char* separator) {
    std::vector<std::string> retrievedProps;
    std::istringstream ss(line);
    std::string value;

    while(std::getline(ss, value, *separator)) {
        retrievedProps.push_back(value);
    }    
    //std::cout << "Field count: " << retrievedProps.size() << std::endl;
    return retrievedProps;
}

std::vector<double> DataManager::parseVariables(std::vector<std::string> dataSet) {
    std::vector<double> parsed;
    for(int i = 0; i < dataSet.size(); i++) {
        parsed.push_back(std::stod(dataSet[i]));
    }
    return parsed;
}

//g++ main.cpp DataManager.cpp -o "C:/Users/nilso/Documents/VSCode/SimpleDataAnalyzer/build/ImportTestRun.exe"