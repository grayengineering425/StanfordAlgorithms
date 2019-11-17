#include "Scheduling.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace Greedy;

Scheduling::Scheduling(bool dif)
	:	jobPath	(L"C:/modules/StanfordAlgorithms/Debug/jobs.txt")
	,	dif		(dif)
{
	jobsFromFile();
}

Scheduling::~Scheduling() = default;

int Scheduling::getCompletionTime()
{
	return dif ? getCompletionTimeDifference() : getCompletionTimeRatio();
}

int Scheduling::getCompletionTimeDifference()
{
	std::sort(jobs.begin(), jobs.end(), [this](const Job& lhs, const Job& rhs)
	{
		if (lhs.score == rhs.score) return lhs.weight > rhs.weight;
	
		return lhs.score > rhs.score;
	});

	int length = 0;
	int cost   = 0;

	for (const auto& job : jobs) { length = length + job.length; cost += length * job.weight; }

	return cost;
}

int Scheduling::getCompletionTimeRatio()
{
	std::sort(jobs.begin(), jobs.end(), [this](const Job& lhs, const Job& rhs)
	{
		return lhs.score > rhs.score;
	});

	int length = 0;
	int cost   = 0;

	for (const auto& job : jobs) { length = length + job.length; cost += length * job.weight; }

	return cost;
}

void Scheduling::jobsFromFile()
{
	std::ifstream jobFile(jobPath);
	std::string line;

	if (jobFile.is_open())
	{
		std::getline(jobFile, line);

		while (std::getline(jobFile, line))
		{
			std::istringstream iss(line);
			std::vector<std::string> results(std::istream_iterator<std::string>{iss},
				std::istream_iterator<std::string>());

			if (results.size() != 2) continue;

			int weight  = std::atoi(results[0].c_str());
			int length  = std::atoi(results[1].c_str());

			Job j(weight, length, dif);

			jobs.emplace_back(j);
		}
	}
}
