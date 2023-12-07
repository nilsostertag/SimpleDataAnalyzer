#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
#include <sstream>

#include "DataAnalyzer.h"
#include "InteractionManager.h"

void DataAnalyzer::start() {
    inputDataset();
    calculateDescriptiveStatistics();
    //sortDataset();
    //filterDataset(0.3, 5.75);
    //InteractionManager interactionManager;
    //interactionManager.showMenu();
}

void DataAnalyzer::inputDataset() {
    std::cout << "Enter dataset values (non-numeric value will stop the input)" << std::endl;
    
    std::string input;
    while (std::cin >> input) {
        // Exit loop if the user enters 'q' or 'Q'
        if (input == "q" || input == "Q") {
            std::getchar();
            break; 
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
    getMinimum();
    getMaximum();
}

double DataAnalyzer::calculateMean(const std::string& key, const std::vector<std::string>& dataSet) {
    if (dataSet.empty()) {
        std::cerr << "Error: The dataset is empty. Please enter data first." << std::endl;
        return 0;
    }

    //double mean = std::accumulate(dataSet.begin(), dataSet.end(), 0.0) / dataSet.size();
    double acc = 0;
    for(int i = 0; i < dataSet.size(); i++) {
        acc += std::stod(dataSet[i]);
    }
    double mean = acc / dataSet.size();
    std::cout << "Mean of " << key << ": " << mean << std::endl;
    return mean;
}

double DataAnalyzer::getMinimum() {
    if (dataset.empty()) {
        std::cerr << "Error: The dataset is empty. Please enter data first." << std::endl;
        return 0;
    }
    double minimum = *std::min_element(dataset.begin(), dataset.end());
    std::cout << "Minimum: " << minimum << std::endl;
    return minimum;
}

double DataAnalyzer::getMaximum() {
    if (dataset.empty()) {
        std::cerr << "Error: The dataset is empty. Please enter data first." << std::endl;
        return 0;
    }
    double maximum = *std::max_element(dataset.begin(), dataset.end());
    std::cout << "Maximum: " << maximum << std::endl;
    return maximum;
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