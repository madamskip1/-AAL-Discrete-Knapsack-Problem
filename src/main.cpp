#include <iostream>
#include <vector>

#include "Knapsack.hpp"
#include "Generator.hpp"
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

    for (Item &item : knapsack.getResultKnapsack())
    {
        std::cout << item << std::endl;
    }
}

void m2Mode()
{
    int numItems;
    int capacity;
    int maxDuplicates;
    float binominalParameter;


    // 0 jeœli domyœlna/wyliczana wartoœæ
    // numItems obowi¹zkowy parametr;
    std::cin >> numItems >> binominalParameter >> capacity >> maxDuplicates;

    if (numItems <= 0)
        return;

    std::cout << numItems << std::endl;

    Generator gen(numItems);

    if (binominalParameter > 0)
        gen.setBinominalParameter(binominalParameter);
    if (capacity > 0)
        gen.setCapacity(capacity);
    if (maxDuplicates > 0)
        gen.setMaxDuplicates(maxDuplicates);



    std::vector<Item> items = gen.generate();

    Knapsack knap(gen.getCapacity(), gen.getMaxDuplciates());
    knap.fromVector(items);
    knap.calculateKnapsack();

    std::cout << knap.getResultValue() << std::endl;

    for (Item &item : knap.getResultKnapsack())
    {
        std::cout << item << std::endl;
    }
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
