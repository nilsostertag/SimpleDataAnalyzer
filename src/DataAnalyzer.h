#ifndef DATA_ANALYZER_H
#define DATA_ANALYZER_H

#include <vector>

class DataAnalyzer {
    public:
        void start();

    private:
        std::vector<double> dataset;

    void inputDataset();
    void calculateDescriptiveStatistics();
    void sortDataset();
    void filterDataset(double threshold);
};

#endif