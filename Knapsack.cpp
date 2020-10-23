#include "Knapsack.h"
#include <vector>
#include <iostream>

Knapsack::Knapsack() : capacity(0), amountOfItems(0), maxAmountOfEachItem(0), resultValue(0)
{
}

Knapsack::Knapsack(int capacity, int maxAmountOfEachItem) : capacity(capacity), maxAmountOfEachItem(maxAmountOfEachItem), amountOfItems(0), resultValue(0)
{
}

void Knapsack::setAmountOfItems(int amount)
{
	amountOfItems = amount;
}

void Knapsack::setCapacity(int cap)
{
	capacity = cap;
}

void Knapsack::setMaxAmountOfEachItem(int maxAmount)
{
	maxAmountOfEachItem = maxAmount;
}

void Knapsack::calc()
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

void Knapsack::add(int volume, int value)
{
	if (checkIfMapKeyExists(amountOfEachItem, volume) && checkIfMapKeyExists(amountOfEachItem[volume], value))
	{
		if (amountOfEachItem[volume][value] >= maxAmountOfEachItem)
			return;

		amountOfEachItem[volume][value]++;
	}
	else
		amountOfEachItem[volume][value] = 1;

	std::pair<int, int> newItem = std::make_pair(volume, value);
	items.push_back(newItem);
	amountOfItems++;
}

int Knapsack::getResultValue()
{
	return resultValue;
}

std::vector<std::pair<int, int>> Knapsack::getResultKnapsack()
{
	return resultKnapsack;
}

void Knapsack::calcResultKnapsack(const std::vector<std::vector<int>>& tempKnapsackValues)
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

int Knapsack::max(int a, int b)
{
	if (a > b)
		return a;

	return b;
}

int Knapsack::isFirstBiggerThanSecond(int a, int b)
{
	if (a > b)
		return true;

	return false;
}

