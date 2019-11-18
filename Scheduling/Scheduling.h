#pragma once
#include <vector>

namespace Greedy
{

struct Job
{
	Job(int weight, int length, bool dif)
		:	weight(weight)
		,	length(length)
		,	score(dif ? weight - length : (double)weight / (double)length)
	{}

	int		weight;
	int		length;
	double	score;
};

class Scheduling
{
public:
	Scheduling (bool dif=true);
	~Scheduling();

	long long getCompletionTime();

private:
	long long getCompletionTimeDifference	();
	long long getCompletionTimeRatio		();

	void jobsFromFile();

private:
	std::vector<Job> jobs;

	std::wstring jobPath;

	bool dif;
};

}