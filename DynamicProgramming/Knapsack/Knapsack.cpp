#include "Knapsack.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace Dynamic;

Knapsack::Knapsack()
	:	fileName(L"C:/modules/StanfordAlgorithms/x64/Debug/knapsack1.txt")
{
}

Knapsack::~Knapsack() = default;

int Knapsack::getOptimalSolution()
{
	valuesFromFile();

	std::vector<std::vector<int>> dp(values.size(), std::vector<int>(capacity + 1, 0));

	for (int i=0; i<dp	 .size(); ++i)
	for (int j=0; j<dp[i].size(); ++j)
	{
		if (i == 0 || j == 0){ dp[i][j] = 0; continue; }

		if (weights[i] > j)
			dp[i][j] = dp[i-1][j];
		else
			dp[i][j] = std::max(dp[i-1][j - weights[i]] + values[i], dp[i-1][j]);
	}

	return dp[dp.size() - 1][dp[0].size() - 1];
	//2493893
}

void Knapsack::valuesFromFile(bool test)
{
	if (test)
	{
		capacity	= 8;
		values		= { 0, 1, 2, 5, 6 };
		weights		= { 0, 2, 3, 4, 5 };
	}

	else
	{
		values .push_back(0);
		weights.push_back(0);

		std::ifstream graphFile(fileName);
		std::string line;

		if (graphFile.is_open())
		{
			std::getline(graphFile, line);

			std::istringstream meta(line);
			std::vector<std::string> resultsMeta(std::istream_iterator<std::string>{meta},
				std::istream_iterator<std::string>());

			capacity = std::atoi(resultsMeta[0].c_str());

			while (std::getline(graphFile, line))
			{
				std::istringstream iss(line);
				std::vector<std::string> results(std::istream_iterator<std::string>{iss},
					std::istream_iterator<std::string>());

				if (results.size() != 2) continue;

				values	.push_back(std::atoi(results[0].c_str()));
				weights	.push_back(std::atoi(results[1].c_str()));
			}
		}
	}
}
