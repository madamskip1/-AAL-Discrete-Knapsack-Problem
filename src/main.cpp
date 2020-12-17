#include <iostream>
#include <vector>

#include "Benchmark.hpp"
#include "Generator.hpp"
#include "Knapsack.hpp"

void m1Mode(bool naive)
{
    int numItems, capacity, maxDuplicates;
    std::cin >> numItems >> capacity >> maxDuplicates;

    Knapsack knapsack(capacity, maxDuplicates);

    for (int i = 0; i < numItems; ++i)
    {
        int volume, value;
        std::cin >> volume >> value;

        knapsack.addItem(volume, value);
    }

    // TODO: choose which algorithm to use (optimal or naive)
    knapsack.calculateKnapsack(naive);

    std::cout << knapsack.getResultValue() << std::endl;

    for (Item &item : knapsack.getResultKnapsack())
    {
        std::cout << item << std::endl;
    }
}

void m2Mode(bool naive)
{
    int numItems, capacity, maxDuplicates;
    float binominalParameter;
    std::cin >> numItems >> capacity >> maxDuplicates >> binominalParameter;

    if (numItems <= 0)
    {
        return;
    }

    Generator gen(numItems);

    if (binominalParameter > 0)
    {
        gen.setBinominalParameter(binominalParameter);
    }

    if (capacity > 0)
    {
        gen.setCapacity(capacity);
    }

    if (maxDuplicates == 0)
    {
        maxDuplicates = gen.getMaxDuplicates();
    }

    std::vector<Item> items = gen.generate();

    Knapsack knapsack(gen.getCapacity(), maxDuplicates);
    knapsack.fromVector(items);
    knapsack.calculateKnapsack(naive);

    std::cout << knapsack.getResultValue() << std::endl;

    for (Item &item : knapsack.getResultKnapsack())
    {
        std::cout << item << std::endl;
    }
}

void m3Mode(bool naive)
{
    Benchmark benchmark;
    benchmark.setNumProblems(100);
    benchmark.setStep(1000);
    benchmark.setNumInstances(10);
    benchmark.setStartNumItems(1000);
    benchmark.setCapacity(10000);
    benchmark.setMaxDuplicates(100000);
    benchmark.run(naive);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "usage:" << std::endl;
        std::cout << "    ./main mode algorithm" << std::endl;
        std::cout << "mode:" << std::endl;
        std::cout << "    -m1   manual" << std::endl;
        std::cout << "    -m2   automated" << std::endl;
        std::cout << "    -m3   benchmark" << std::endl;
        std::cout << "algorithm:" << std::endl;
        std::cout << "    -a1   naive" << std::endl;
        std::cout << "    -a2   optimal" << std::endl;
        return 1;
    }

    bool naive;

    if (argv[2] == std::string("-a1"))
    {
        naive = true;
    }
    else if (argv[2] == std::string("-a2"))
    {
        naive = false;
    }
    else
    {
        std::cout << "Invalid algorithm." << std::endl;
        return 1;
    }

    if (argv[1] == std::string("-m1"))
    {
        m1Mode(naive);
    }
    else if (argv[1] == std::string("-m2"))
    {
        m2Mode(naive);
    }
    else if (argv[1] == std::string("-m3"))
    {
        m3Mode(naive);
    }
    else
    {
        std::cout << "Invalid mode." << std::endl;
        return 1;
    }

    return 0;
}
