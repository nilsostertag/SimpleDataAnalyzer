#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
#include <sstream>

#include "DataAnalyzer.h"

void DataAnalyzer::start() {
    inputDataset();
    calculateDescriptiveStatistics();
    //sortDataset();
    filterDataset(5.0);
}

void DataAnalyzer::inputDataset() {
    std::cout << "Enter dataset values (non-numeric value will stop the input)" << std::endl;
    
    std::string input;
    while (std::cin >> input) {
        if (input == "q" || input == "Q") {
            std::getchar();
            break; // Exit loop if the user enters 'q' or 'Q'
        }

        try {
            // Convert the string to a double
            double value = std::stod(input);
            dataset.push_back(value);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Continuing with the next input..." << std::endl;
        }
    }

    std::cout << "Entered dataset: ";
    for(double val : dataset) {
        std::cout << val << std::endl;
    }
}

void DataAnalyzer::calculateDescriptiveStatistics() {
    if (dataset.empty()) {
        std::cerr << "Error: The dataset is empty. Please enter data first." << std::endl;
        return;
    }

    double mean = std::accumulate(dataset.begin(), dataset.end(), 0.0) / dataset.size();

    std::cout << "\nDescriptive Statistics:\n";
    std::cout << "Mean: " << mean << std::endl;
}

void DataAnalyzer::filterDataset(double threshold) {
    dataset.erase(std::remove_if(dataset.begin(), dataset.end(), [threshold](double val) {
        return val < threshold;
    }), dataset.end());

    std::cout << "\nFiltered Datset (values >= " << threshold << "): " << std::endl;
    for(double val : dataset) {
        std::cout << val << std::endl;
    }
}