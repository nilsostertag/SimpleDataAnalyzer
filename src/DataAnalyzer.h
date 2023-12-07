#pragma once

#ifndef DATA_ANALYZER_H
#define DATA_ANALYZER_H

#include <vector>

class DataAnalyzer {
    public:
        void start();
        double calculateMean(const std::string& key, const std::vector<std::string>& dataSet);
        void inputDataset();
        void calculateDescriptiveStatistics();
        double getMinimum();
        double getMaximum();
        void sortDataset();
        void filterDataset(double thresholdMin, double thresholdMax);

    private:
        std::vector<double> dataset;
        std::vector<double> workset;

    
    
};

#endif