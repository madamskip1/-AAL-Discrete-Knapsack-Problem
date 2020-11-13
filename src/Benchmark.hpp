#pragma once
#include <iostream>
#include <vector>
#include <chrono>
class Benchmark
{
public:
    Benchmark();
    int numProblems;
    int step;
    int numInstances;
    int startNumItems;

    int numItems;
    int capacity;
    int maxDuplicates;
    std::vector<std::chrono::duration<double>> times;

    static const int DEFAULT_NUM_INSTANCES;
    static const int DEFAULT_STEP;
    static const int DEFAULT_NUM_PROBLEMS;
    void run();
    void runInstance();
    void printInstance();
    void printProblem();

    void setStartNumItems(int start);
    void setCapacity(int capacity);
    void setNumProblems(int problems);
    void setNumInstances(int instances);
    void setStep(int step);
    void setMaxDuplicates(int max);
};