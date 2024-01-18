#pragma once

#ifndef INTERACTION_MANAGER_H
#define INTERACTION_MANAGER_H

#include <vector>
#include <string>
#include <iostream>

class InteractionManager {
    public:
        InteractionManager() {
            std::cout << "Welcome!\n\n\tPlease enter the path to your data directory: ";
            std::cin >> this->dirPath;
            showMenu(dirPath);
        }
        void showMenu(const std::string& dirPath);
        std::vector<std::string> getDirOverview(const std::string& dirPath);
        void help();
        void awaitUserInput();

    private:
        std::vector<std::string> processCommand(std::string command);
        void executeCommand(const std::vector<std::string>& arguments);
        std::string dirPath;
};

#endif