#pragma once

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <filesystem>
#include <vector>
#include <string>

class FileManager {
    public:
        std::vector<std::string> getAllFilesInDir(const std::string& dirPath);
        std::string getFileName(const std::string& path);

};

#endif