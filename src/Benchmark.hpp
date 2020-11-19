#pragma once

#include <chrono>
#include <iostream>
#include <vector>

class Benchmark
{
public:
    Benchmark();
    void run(bool naive);
    void setStartNumItems(int start);
    void setCapacity(int capacity);
    void setNumProblems(int problems);
    void setNumInstances(int instances);
    void setStep(int step);
    void setMaxDuplicates(int max);

private:
    int numProblems;
    int numInstances;
    int step;
    int startNumItems;

    int numItems;
    int capacity;
    int maxDuplicates;
    std::vector<std::chrono::duration<double>> times;

    static const int DEFAULT_NUM_INSTANCES;
    static const int DEFAULT_STEP;
    static const int DEFAULT_NUM_PROBLEMS;

    void runInstance(bool naive);
    void printInstance();
    void printProblem();
};
