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

    int resultValue;
    std::vector<Item> resultKnapsack;

    void generateResultValue(const std::vector<std::vector<int>> &temp);
    void generateResultKnapsack(const std::vector<std::vector<int>> &temp);

public:
    Knapsack(int capacity, int maxDuplicates);

    void addItem(int volume, int value);
    void calculateKnapsack();

    int getResultValue();
    std::vector<Item> getResultKnapsack();
};
