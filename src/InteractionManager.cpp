#include <iostream>
#include <sstream>

#include <InteractionManager.hpp>
#include <DataManager.hpp>
#include <FileManager.hpp>

void InteractionManager::showMenu(const std::string& dirPath) {
    system("cls");    
    help();

    awaitUserInput();
}

std::vector<std::string> InteractionManager::getDirOverview(const std::string& dirPath) {
    FileManager fileManager;
    std::vector<std::string> filePaths = fileManager.getAllFilesInDir(dirPath);

    std::cout << "\tFiles inside chosen directory: " << dirPath << std::endl;
    for(int i = 0; i < filePaths.size(); i++) {
        std::string retrievedFileName = fileManager.getFileName(filePaths[i]);
        std::cout << "\t" << i << "\t-\t" << retrievedFileName << std::endl;
    }

    return filePaths;
}

void InteractionManager::awaitUserInput() {
    std::string userInput;
    std::cin >> userInput;

    std::vector<std::string> arguments = processCommand(userInput);
    executeCommand(arguments);
}

void InteractionManager::help() {
    std::cout << "\tSimpleDataAnalyzer Menu\n\tOperation options:" << std::endl;
    std::cout << "\timport\t-\tImport a dataset" << std::endl;
    std::cout << "\tmean\t-\tCalculate the mean value of the dataset" << std::endl;
    std::cout << "\tmin\t-\tDetermine the minimum value of the dataset" << std::endl;
    std::cout << "\tmax\t-\tDetermine the maximum value of the dataset\n\n" << std::endl;

    //awaitUserInput();
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
    if(arguments[0] == "import") {
        std::vector<std::string> filesInDir = getDirOverview(dirPath);
        std::cout << "\n\tPlease enter the index of which dataset you want to import: ";
        char index;
        std::cin >> index;
        DataManager dataManeger;
        dataManeger.importDataset(filesInDir[int(index)], '/');
    }
    return;
}
