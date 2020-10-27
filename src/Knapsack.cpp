#include "Knapsack.hpp"

#include <iostream>
#include <vector>

Knapsack::Knapsack()
    : capacity(0)
    , amountOfItems(0)
    , maxAmountOfEachItem(0)
    , resultValue(0)
{
}

Knapsack::Knapsack(int capacity, int maxAmountOfEachItem)
    : capacity(capacity)
    , maxAmountOfEachItem(maxAmountOfEachItem)
    , amountOfItems(0)
    , resultValue(0)
{
}

void Knapsack::setCapacity(int cap)
{
    capacity = cap;
}

void Knapsack::setMaxAmountOfEachItem(int maxAmount)
{
    maxAmountOfEachItem = maxAmount;
}

void Knapsack::calculateKnapsack()
{
    std::vector<std::vector<int>> tempKnapsackValues(amountOfItems + 1, std::vector<int>(capacity + 1, 0));

    int itemVolume;
    int itemValue;
    int previousItemIndex;

    for (int i = 1; i <= amountOfItems; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            previousItemIndex = i - 1;

            itemVolume = items[previousItemIndex].first;
            itemValue = items[previousItemIndex].second;

            if (itemVolume > j)
                tempKnapsackValues[i][j] = tempKnapsackValues[previousItemIndex][j];
            else
            {
                tempKnapsackValues[i][j] = max(tempKnapsackValues[previousItemIndex][j], tempKnapsackValues[previousItemIndex][j - itemVolume] + itemValue);
            }
        }
    }

    resultValue = tempKnapsackValues[amountOfItems][capacity];
    calcResultKnapsack(tempKnapsackValues);
}

void Knapsack::addItem(int volume, int value)
{
    if (checkIfElementAlreadyExists(volume, value))
    {
        if (!checkIfCanAddElement(volume, value))
            return;

        amountOfEachItem[volume][value]++;
    }
    else
        amountOfEachItem[volume][value] = 1;

    pushNewItem(volume, value);
}

void Knapsack::clear()
{
    items.clear();
    amountOfEachItem.clear();
    resultKnapsack.clear();

    capacity = 0;
    amountOfItems = 0;
    maxAmountOfEachItem = 0;
    resultValue = 0;
}

int Knapsack::getResultValue()
{
    return resultValue;
}

std::vector<std::pair<int, int>> Knapsack::getResultKnapsack()
{
    return resultKnapsack;
}

void Knapsack::calcResultKnapsack(const std::vector<std::vector<int>> &tempKnapsackValues)
{
    std::vector<std::pair<int, int>> result;
    int remainedValue = resultValue;
    int remainedCapacity = capacity;
    int itemIndex = amountOfItems;
    int previousItemIndex;
    std::pair<int, int> currentItem;

    while (itemIndex >= 0 && remainedValue > 0)
    {
        previousItemIndex = itemIndex - 1;
        if (remainedValue != tempKnapsackValues[previousItemIndex][remainedCapacity])
        {
            currentItem = items[previousItemIndex];
            remainedCapacity -= currentItem.first;
            remainedValue -= currentItem.second;
            result.push_back(currentItem);
        }

        itemIndex--;
    }

    resultKnapsack = result;
}

bool Knapsack::checkIfCanAddElement(int volume, int value)
{
    return amountOfEachItem[volume][value] < maxAmountOfEachItem;
}

bool Knapsack::checkIfElementAlreadyExists(int volume, int value)
{
    return checkIfMapKeyExists(amountOfEachItem, volume) && checkIfMapKeyExists(amountOfEachItem[volume], value);
}

void Knapsack::pushNewItem(int volume, int value)
{
    std::pair<int, int> newItem = std::make_pair(volume, value);
    items.push_back(newItem);
    amountOfItems++;
}

int Knapsack::max(int a, int b)
{
    return a > b ? a : b;
}
