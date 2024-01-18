#pragma once

#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <map>
#include <vector>
#include <string>

struct DataSet
{
    std::string origin;
    std::vector<std::string> columns;
    std::map<std::string, std::vector<std::string>> data;
};

class DataManager  {
    public:
        DataSet importDataset(const std::string& path, const char& separator);
        std::vector<double> parseVariables(std::vector<std::string> dataSet);
        std::map<std::string, DataSet> datasetMemory;

    private:
        std::vector<std::string> retrievePropsFromLine(const std::string& line, const char& separator);
};

#endif