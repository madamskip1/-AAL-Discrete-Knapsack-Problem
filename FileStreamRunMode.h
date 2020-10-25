#pragma once
#include "RunMode.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Knapsack.h"

class FileStreamRunMode :
    public RunMode
{
private:
    std::string inputFileName;
    std::string outputFileName;
    Knapsack* knapsack;
    std::fstream inputFile;
    std::ofstream outputFile;

public:
    FileStreamRunMode(std::string inputFileName, std::string outputFileName);
    ~FileStreamRunMode();
    void run();

private:
    void openFiles();
    void closeFiles();
    void readInputFile();
    void writeOutputFile();
};

