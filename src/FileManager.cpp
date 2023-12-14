#include <FileManager.hpp>

std::vector<std::string> FileManager::getAllFilesInDir(const std::string& dirPath) {
    std::vector<std::string> collected;
    for(const auto& entry : std::filesystem::directory_iterator(dirPath)) {
        if(entry.is_regular_file()) {
            collected.push_back(entry.path().string());
        }
    }
    return collected;
}

std::string FileManager::getFileName(const std::string& path) {
    std::filesystem::path file(path);
    return file.filename().string();
}