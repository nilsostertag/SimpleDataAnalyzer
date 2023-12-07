#pragma once

#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <map>
#include <vector>
#include <string>

class DataManager  {
    public:
        std::map<std::string, std::vector<std::string>> importDataset(const std::string& path, const char& separator);
        std::vector<double> parseVariables(std::vector<std::string> dataSet);

    private:
        std::vector<std::string> retrievePropsFromLine(const std::string& line, const char& separator);
};

#endif