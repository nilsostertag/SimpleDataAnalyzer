#include <iostream>
#include <sstream>

#include "InteractionManager.h"

void InteractionManager::showMenu() {
    system("cls");    
    help();

    awaitUserInput();
}

void InteractionManager::awaitUserInput() {
    std::string userInput;
    std::cin >> userInput;

    std::vector<std::string> arguments = processCommand(userInput);
    executeCommand(arguments);
}

void InteractionManager::awaitUserInput() {
    std::string userInput;
    std::cin >> userInput;

    std::vector<std::string> arguments = processCommand(userInput);
    executeCommand(arguments);
}

void InteractionManager::help() {
    std::cout << "SimpleDataAnalyzer Menu\n\tOperation options:" << std::endl;
    std::cout << "<dataset> mean - Calculate the mean value of the dataset" << std::endl;
    std::cout << "<dataset> min - Determine the minimum value of the dataset" << std::endl;
    std::cout << "<dataset> max - Determine the maximum value of the dataset" << std::endl;

    awaitUserInput();
}

std::vector<std::string> InteractionManager::processCommand(std::string command) {
    std::istringstream iss(command);
    std::vector<std::string> arguments;
    // Tokenize the command using std::getline
    std::string argument;
    while (std::getline(iss, argument, ' ')) {
        arguments.push_back(argument);
    }
    return arguments;
}

void InteractionManager::executeCommand(const std::vector<std::string>& arguments) {
    //TODO
}
