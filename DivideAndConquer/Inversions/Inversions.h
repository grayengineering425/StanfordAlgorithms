#pragma once
#include <vector>

namespace DivandConq
{

class Inversions
{
public:
	Inversions(bool test = false);

	long long getNumInversions();

private:
	void valuesFromFile(bool test);

	long long numInversionsHelper	(int l, int r);
	long long merge					(int l, int r, int m);

private:
	std::vector<int> nums;

	std::wstring fileName;
};

}