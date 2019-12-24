#pragma once

#include <vector>

namespace Dynamic
{

class Knapsack
{
public:
	Knapsack();
	~Knapsack();

	int getOptimalSolution();
	int getOptimizedSolution();

private:
	void valuesFromFile(bool test=false);

	int getOptimizedSolution(std::vector<int>& lastRow, int row);

private:
	std::vector<int> values;
	std::vector<int> weights;

	int capacity;

	std::wstring fileName;
};

}