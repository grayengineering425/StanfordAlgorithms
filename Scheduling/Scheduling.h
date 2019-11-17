#pragma once
#include <vector>

namespace Greedy
{

struct Job
{
	Job(int weight, int length, bool dif)
		:	weight(weight)
		,	length(length)
		,	score(dif ? weight - length : weight / length)
	{}

	int weight;
	int length;
	int score;
};

class Scheduling
{
public:
	Scheduling (bool dif=true);
	~Scheduling();

	int getCompletionTime();

private:
	int getCompletionTimeDifference	();
	int getCompletionTimeRatio		();

	void jobsFromFile();

private:
	std::vector<Job> jobs;

	std::wstring jobPath;

	bool dif;
};

}