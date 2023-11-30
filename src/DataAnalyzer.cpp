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
    filterDataset(0.3, 5.75);
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

    std::cout << "Entered dataset: " << std::endl;
    for(double val : dataset) {
        std::cout << val << std::endl;
    }
}

void DataAnalyzer::calculateDescriptiveStatistics() {
    std::cout << "\nDescriptive Statistics:\n";
    calculateMean();
    getMinimum();
    getMaximum();
}

void DataAnalyzer::calculateMean() {
    if (dataset.empty()) {
        std::cerr << "Error: The dataset is empty. Please enter data first." << std::endl;
        return;
    }

    double mean = std::accumulate(dataset.begin(), dataset.end(), 0.0) / dataset.size();
    std::cout << "Mean: " << mean << std::endl;
}

void DataAnalyzer::getMinimum() {
    if (dataset.empty()) {
        std::cerr << "Error: The dataset is empty. Please enter data first." << std::endl;
        return;
    }
    double minimum = *std::min_element(dataset.begin(), dataset.end());
    std::cout << "Minimum: " << minimum << std::endl;
}

void DataAnalyzer::getMaximum() {
    if (dataset.empty()) {
        std::cerr << "Error: The dataset is empty. Please enter data first." << std::endl;
        return;
    }
    double maximum = *std::max_element(dataset.begin(), dataset.end());
    std::cout << "Maximum: " << maximum << std::endl;
}

void DataAnalyzer::filterDataset(double thresholdMin, double thresholdMax) {
    workset = dataset;
    workset.erase(std::remove_if(workset.begin(), workset.end(), [thresholdMin, thresholdMax](double val) {
        return val < thresholdMin || val > thresholdMax;
    }), workset.end());

    std::cout << "\nFiltered Datset (values between " << thresholdMin << " and " << thresholdMax << "): " << std::endl;
    for(double val : workset) {
        std::cout << val << std::endl;
    }
}