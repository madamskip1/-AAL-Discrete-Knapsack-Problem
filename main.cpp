#include <vector>
#include <iostream>
#include "Knapsack.h"

int main()
{

	Knapsack knapsack(10, 2);

	knapsack.add(2, 13);
	knapsack.add(2, 50);
	knapsack.add(2, 50);
	knapsack.add(2, 50);
	knapsack.add(2, 50);
	knapsack.add(2, 50);
	knapsack.add(2, 50);
	knapsack.add(2, 50);
	knapsack.add(2, 50);
	knapsack.add(2, 50);
	knapsack.add(3, 10);
	knapsack.add(5, 18);
	knapsack.add(6, 22);
	knapsack.add(7, 24);


	knapsack.calc();

	std::cout << knapsack.getResultValue();
	std::vector<std::pair<int, int>> test = knapsack.getResultKnapsack();

	return 0;
}