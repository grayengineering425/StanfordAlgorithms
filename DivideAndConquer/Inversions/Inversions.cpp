#include "Inversions.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace DivandConq;

Inversions::Inversions(bool test)
	:	fileName(L"C:/modules/StanfordAlgorithms/StanfordAlgorithms/x64/Debug/IntegerArray.txt")
{
	valuesFromFile(test);
}

long long Inversions::getNumInversions()
{
	int l = 0;
	int r = nums.size() - 1;

	return numInversionsHelper(l, r);
}

long long Inversions::numInversionsHelper(int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;

		long long x = numInversionsHelper(l,		m);
		long long y = numInversionsHelper(m+1,	r);
		long long z = merge(l, r, m);

		return x + y + z;
	}

	return 0;
}

long long Inversions::merge(int l, int r, int m)
{
	long long numInversions = 0;

	int sizeLeft = m - l + 1;
	int sizeRight= r - m;

	std::vector<int> leftNums;
	std::vector<int> rightNums;

	for (int i=0; i<sizeLeft;	++i) leftNums	.push_back(nums[l + i]);
	for (int i=0; i<sizeRight;	++i) rightNums	.push_back(nums[m  + 1 + i]);

	int k = l;

	int i=0; int j = 0;

	while (i < sizeLeft && j < sizeRight)
	{
		if (leftNums[i] <= rightNums[j])
		{
			nums[k] = leftNums[i];
			i++;
		}
		else
		{
			nums[k] = rightNums[j];

			numInversions += sizeLeft - i;

			j++;
		}
		k++;
	}

	while (i < sizeLeft)
	{
		nums[k] = leftNums[i];
		i++;
		k++;
	}

	while (j < sizeRight)
	{
		nums[k] = rightNums[j];
		j++;
		k++;
	}

	return numInversions;
}

void Inversions::valuesFromFile(bool test)
{
	if(test)
	{
		nums = { 1, 3, 5, 2, 4, 6 };
	}
	else
	{
		std::ifstream graphFile(fileName);
		std::string line;

		if (graphFile.is_open())
		{
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
}
