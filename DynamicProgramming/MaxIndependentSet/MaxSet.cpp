#include "MaxSet.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace Dynamic;

MaxSet::MaxSet()
	:	fileName(L"C:/modules/StanfordAlgorithms/x64/Debug/mwis.txt")
{
}

MaxSet::~MaxSet() = default;

std::vector<int> MaxSet::getMaxSet()
{
	listFromFile();

	std::vector<int> dp(nums.size() + 1, -1);

	dp[0] = 0;
	dp[1] = nums[0];

	for (int i=2; i<dp.size(); ++i)
	{
		dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
	}

	auto r = reconstructSet(dp);

	return r;
}

std::vector<int> MaxSet::reconstructSet(std::vector<int>& dp)
{
	std::vector<int> recon;

	for (int i=static_cast<int>(dp.size())-1; i>=1; --i)
	{
		if (i == 1){ recon.insert(recon.begin(), i); continue; }
		
		if (dp[i-1] >= dp[i-2] + nums[i-1])		continue;
		else								{	recon.insert(recon.begin(), i); --i; }

	}

	return recon;
	//10100110
}


void MaxSet::listFromFile()
{
	std::ifstream graphFile(fileName);
	std::string line;

	if (graphFile.is_open())
	{
		std::getline(graphFile, line);

		std::istringstream meta(line);
		std::vector<std::string> resultsMeta(std::istream_iterator<std::string>{meta},
			std::istream_iterator<std::string>());

		int numNodes = std::atoi(resultsMeta[0].c_str());

		while (std::getline(graphFile, line))
		{
			std::istringstream iss(line);
			std::vector<std::string> results(std::istream_iterator<std::string>{iss},
				std::istream_iterator<std::string>());

			if (results.size() != 1) continue;

			nums.push_back(std::atoi(results[0].c_str()));
		}
	}
}
