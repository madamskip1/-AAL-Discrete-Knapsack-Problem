#include "Knapsack.hpp"

#include <iostream>

Knapsack::Knapsack(int capacity, int maxDuplicates)
    : capacity(capacity)
    , maxDuplicates(maxDuplicates)
    , numItems(0)
    , resultValue(0)
{
}

void Knapsack::addItem(int volume, int value)
{
    Item item = {volume, value};
    auto it = itemCount.find(item);

    if (it == itemCount.end())
    {
        itemCount[item] = 1;
    }
    else if (it->second < maxDuplicates)
    {
        ++it->second;
    }
    else
    {
        return;
    }

    items.push_back(item);
    ++numItems;
}

void Knapsack::fromVector(const std::vector<Item> &vec)
{
    int items = vec.size();
    for (int i = 0; i < items; i++)
    {
        addItem(vec[i].volume, vec[i].value);
    }
}

int Knapsack::naiveKnapsack(std::vector<Item> toProcess, std::vector<Item> current, int vol, int val, int bestVal, std::vector<Item> &bestItems)
{
    if (vol > capacity)
    {
        return bestVal;
    }

    if (toProcess.empty())
    {
        if (val > bestVal)
        {
            bestVal = val;
            bestItems = current;
        }
        else if (val == bestVal)
        {
            // if same value, then minimize weight
            int temp = 0;
            for (auto x : bestItems)
            {
                temp += x.volume;
            }

            if (vol < temp)
            {
                bestItems = current;
            }
            else if (vol == temp)
            {
                // if same value and weight, then minimize count
                if (current.size() < bestItems.size())
                {
                    bestItems = current;
                }
            }
        }

        return bestVal;
    }
    else
    {
        Item item = toProcess.back();
        toProcess.pop_back();

        // Path A: add the item
        current.push_back(item);
        bestVal = naiveKnapsack(toProcess, current, vol + item.volume, val + item.value, bestVal, bestItems);
        current.pop_back();

        // Path B: skip the item
        bestVal = naiveKnapsack(toProcess, current, vol, val, bestVal, bestItems);
    }

    return bestVal;
}

void Knapsack::calculateKnapsack(bool naive)
{
    if (naive)
    {
        std::vector<Item> toProcess = items;
        std::vector<Item> current;
        resultValue = naiveKnapsack(toProcess, current, 0, 0, 0, resultKnapsack);
    }
    else
    {
        std::vector<std::vector<int>> temp = std::vector(numItems + 1, std::vector<int>(capacity + 1, 0));

        for (int i = 1; i <= numItems; ++i)
        {
            for (int j = 1; j <= capacity; ++j)
            {
                if (items[i - 1].volume > j)
                {
                    temp[i][j] = temp[i - 1][j];
                }
                else
                {
                    temp[i][j] = std::max(temp[i - 1][j], temp[i - 1][j - items[i - 1].volume] + items[i - 1].value);
                }
            }
        }

        generateResultValue(temp);
        generateResultKnapsack(temp);
    }
}

void Knapsack::generateResultValue(const std::vector<std::vector<int>> &temp)
{
    resultValue = temp[numItems][capacity];
}

void Knapsack::generateResultKnapsack(const std::vector<std::vector<int>> &temp)
{
    resultKnapsack.clear();

    int i = numItems;
    int currentValue = getResultValue();
    int currentCapacity = capacity;

    while (i >= 0 && currentValue > 0)
    {
        if (currentValue != temp[i - 1][currentCapacity])
        {
            currentValue -= items[i - 1].value;
            currentCapacity -= items[i - 1].volume;
            resultKnapsack.push_back(items[i - 1]);
        }

        --i;
    }
}

int Knapsack::getResultValue()
{
    return resultValue;
}

std::vector<Item> Knapsack::getResultKnapsack()
{
    return resultKnapsack;
}
