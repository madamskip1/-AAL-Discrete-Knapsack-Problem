#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "Knapsack.hpp"
#include "RunMode.hpp"

class FileStreamRunMode : public RunMode
{
private:
    std::string inputFileName;
    std::string outputFileName;
    Knapsack *knapsack;
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

