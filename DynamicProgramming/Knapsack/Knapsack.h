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

private:
	void valuesFromFile(bool test=false);

private:
	std::vector<int> values;
	std::vector<int> weights;

	int capacity;

	std::wstring fileName;
};

}