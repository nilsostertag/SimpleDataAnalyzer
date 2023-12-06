#pragma once

#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <map>
#include <vector>
#include <string>

class DataManager  {
    public:
        std::map<std::string, std::vector<std::string>> importDataset(std::string path);

    private:
        std::vector<std::string> retrievePropsFromLine(std::string line);
};

#endif