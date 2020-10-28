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

    std::vector<std::vector<int>> temp;

public:
    Knapsack(int capacity, int maxDuplicates);

    void addItem(int volume, int value);
    void calculateKnapsack();

    int getResultValue();
    std::vector<Item> getResultKnapsack();
};
