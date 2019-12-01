#include "Knapsack.h"

using namespace Dynamic;

Knapsack::Knapsack()
{
}

Knapsack::~Knapsack() = default;

int Knapsack::getOptimalSolution()
{
	valuesFromFile();

	std::vector<std::vector<int>>(values.size(), std::vector<int>(weights.size(), 0));

	for (int i=0; i<values.size(); ++i)
	{
		
	}
}

void Knapsack::valuesFromFile()
{
}
