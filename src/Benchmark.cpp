#include "Benchmark.hpp"

#include <chrono>
#include <fstream>
#include <string>

#include "Generator.hpp"
#include "Knapsack.hpp"

const int Benchmark::DEFAULT_NUM_INSTANCES = 10;
const int Benchmark::DEFAULT_STEP = 1000;
const int Benchmark::DEFAULT_NUM_PROBLEMS = 20;

Benchmark::Benchmark()
    : numProblems(Benchmark::DEFAULT_NUM_PROBLEMS)
    , numInstances(Benchmark::DEFAULT_NUM_INSTANCES)
    , step(Benchmark::DEFAULT_STEP)
{
    capacity = numItems = maxDuplicates = startNumItems = 0;
}

void Benchmark::runInstance(bool naive)
{
    Generator gen(numItems);
    gen.setCapacity(capacity);

    std::vector<Item> items = gen.generate();

    Knapsack knap(capacity, maxDuplicates);
    knap.fromVector(items);
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
    std::chrono::duration<double> elapsed;

    start = std::chrono::high_resolution_clock::now();
    knap.calculateKnapsack(naive);
    end = std::chrono::high_resolution_clock::now();

    elapsed = end - start;
    times.push_back(elapsed);
}

void Benchmark::printInstance()
{
    std::chrono::duration<double> lastTime = times.back();
    std::cout << "Czas wykonania instancji: " << lastTime.count() << "s" << std::endl;
}

void Benchmark::printProblem()
{
    auto timeIterator = times.cend() - numInstances;
    double sumTime = 0;
    double avgTime;

    for (; timeIterator != times.cend(); timeIterator++)
    {
        sumTime += (*timeIterator).count();
    }

    avgTime = sumTime / numInstances;

    std::cout << "Czas wykonywania problemu: " << sumTime << "s. Sredni czas instancji: " << avgTime << "s" << std::endl;
}

void Benchmark::setStartNumItems(int start)
{
    startNumItems = start;
}

void Benchmark::setCapacity(int capacity)
{
    this->capacity = capacity;
}

void Benchmark::setNumProblems(int problems)
{
    numProblems = problems;
}

void Benchmark::setNumInstances(int instances)
{
    numInstances = instances;
}

void Benchmark::setStep(int step)
{
    this->step = step;
}

void Benchmark::setMaxDuplicates(int max)
{
    maxDuplicates = max;
}

void Benchmark::run(bool naive)
{
    if (capacity == 0 || startNumItems == 0 || maxDuplicates == 0)
    {
        std::cout << "Nie podano wszystkich wymaganych parametrow." << std::endl;
        return;
    }

    for (int problem = 0; problem < numProblems; problem++)
    {
        numItems = startNumItems + problem * step;
        std::cout << "Nowy problem. Ilosc przedmiotow: " << numItems << std::endl;

        std::ofstream logFile(std::to_string(numItems) + ".txt");

        if (!logFile.is_open())
        {
            std::cout << "Failed to create log file." << std::endl;
            throw;
        }

        for (int instance = 0; instance < numInstances; instance++)
        {
            runInstance(naive);
            printInstance();

            logFile << times.back().count() << std::endl;
        }

        logFile.close();

        printProblem();
    }
}
