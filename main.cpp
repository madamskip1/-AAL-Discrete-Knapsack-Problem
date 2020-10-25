#include <vector>
#include <iostream>
#include "Knapsack.h"

int main()
{

	Knapsack knapsack(10, 2);

	knapsack.addItem(2, 13);
	knapsack.addItem(2, 50);
	knapsack.addItem(2, 50);
	knapsack.addItem(2, 50);
	knapsack.addItem(2, 50);
	knapsack.addItem(2, 50);
	knapsack.addItem(2, 50);
	knapsack.addItem(2, 50);
	knapsack.addItem(2, 50);
	knapsack.addItem(2, 50);
	knapsack.addItem(3, 10);
	knapsack.addItem(5, 18);
	knapsack.addItem(6, 22);
	knapsack.addItem(7, 24);


	knapsack.calculateKnapsack();

	std::cout << knapsack.getResultValue();
	std::vector<std::pair<int, int>> test = knapsack.getResultKnapsack();

	return 0;
}