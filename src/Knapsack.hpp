#pragma once

#include <algorithm>
#include <map>
#include <vector>

#include "Item.hpp"

class Knapsack
{
    int capacity;
    int maxDuplicates;
    int numItems;

    std::vector<Item> items;
    std::map<Item, int> itemCount;

    std::vector<Item> resultKnapsack;

    int resultValue;

public:
    Knapsack();
    Knapsack(int capacity, int maxDuplicates);

    void calculateKnapsack();
    void addItem(int volume, int value);

    int getResultValue();
    std::vector<Item> getResultKnapsack();

private:
    void calcResultKnapsack(const std::vector<std::vector<int>> &tempKnapsackValues);
};
