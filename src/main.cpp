#include <iostream>
#include <vector>

#include "Knapsack.hpp"

void m1Mode()
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
    knapsack.calculateKnapsack();

    std::cout << knapsack.getResultValue() << std::endl;
}

void m2Mode()
{
    // TODO
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Nie wybrano trybu uruchomienia." << std::endl;
        return 1;
    }

    if (argv[1] == std::string("-m1"))
    {
        m1Mode();
    }
    else if (argv[1] == std::string("-m2"))
    {
        m2Mode();
    }
    else
    {
        std::cout << "Wybrano nieistniejacy tryb uruchomienia." << std::endl;
        return 1;
    }

    return 0;
}
