#pragma once

#ifndef INTERACTION_MANAGER_H
#define INTERACTION_MANAGER_H

#include <vector>
#include <string>

class InteractionManager {
    public:
        void showMenu();
        void help();
        void awaitUserInput();

    private:
        std::vector<std::string> processCommand(std::string command);
        void executeCommand(const std::vector<std::string>& arguments);
};

#endif