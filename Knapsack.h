#pragma once
#include <vector>
#include <map>

template<class T, class V>
inline bool checkIfMapKeyExists(const std::map<T, V>& map, T key)
{
	if (map.find(key) == map.end())
		return false;

	return true;
}

class Knapsack
{
	int capacity;
	int amountOfItems;
	int maxAmountOfEachItem;

	std::vector<std::pair<int, int>> items;
	std::map<int, std::map<int, int>> amountOfEachItem;

	std::vector<std::pair<int, int>> resultKnapsack;
	int resultValue;
	
public:
	Knapsack();
	Knapsack(int capacity, int maxAmountOfEachItem);

	void setCapacity(int cap);
	void setMaxAmountOfEachItem(int maxAmount);

	void calculateKnapsack();
	void addItem(int volume, int value);
	void clear();

	int getResultValue();
	std::vector<std::pair<int, int>> getResultKnapsack();

private:
	int max(int a, int b);
	void calcResultKnapsack(const std::vector<std::vector<int>>& tempKnapsackValues);
	bool checkIfCanAddElement(int volume, int value);
	bool checkIfElementAlreadyExists(int volume, int value);
	void pushNewItem(int volume, int value);
};


