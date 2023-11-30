#ifndef DATA_ANALYZER_H
#define DATA_ANALYZER_H

#include <vector>

class DataAnalyzer {
    public:
        void start();

    private:
        std::vector<double> dataset;
        std::vector<double> workset;

    void inputDataset();
    void calculateDescriptiveStatistics();
    void calculateMean();
    void getMinimum();
    void getMaximum();
    void sortDataset();
    void filterDataset(double thresholdMin, double thresholdMax);
    void menu();
    void help();
};

#endif