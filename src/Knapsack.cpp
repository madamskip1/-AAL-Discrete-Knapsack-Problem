#include "Knapsack.hpp"

Knapsack::Knapsack(int capacity, int maxDuplicates)
    : capacity(capacity)
    , maxDuplicates(maxDuplicates)
    , numItems(0)
    , resultValue(0)
{
}

void Knapsack::calculateKnapsack()
{
    std::vector<std::vector<int>> temp(numItems + 1, std::vector<int>(capacity + 1, 0));

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

    resultValue = temp[numItems][capacity];
    calcResultKnapsack(temp);
}

void Knapsack::addItem(int volume, int value)
{
    Item item = {volume, value};

    auto it = itemCount.find(item);
    if (it == itemCount.end())
    {
        itemCount[item] = 1;
    }
    else
    {
        if (it->second < maxDuplicates)
        {
            ++it->second;
        }
        else
        {
            return;
        }
    }

    items.push_back(item);
    ++numItems;
}

int Knapsack::getResultValue()
{
    return resultValue;
}

std::vector<Item> Knapsack::getResultKnapsack()
{
    return resultKnapsack;
}

void Knapsack::calcResultKnapsack(const std::vector<std::vector<int>> &temp)
{
    std::vector<Item> result;

    int i = numItems;
    int currentValue = resultValue;
    int currentCapacity = capacity;

    while (i >= 0 && currentValue > 0)
    {
        if (currentValue != temp[i - 1][currentCapacity])
        {
            currentValue -= items[i - 1].value;
            currentCapacity -= items[i - 1].volume;
            result.push_back(items[i - 1]);
        }

        --i;
    }

    resultKnapsack = result;
}
