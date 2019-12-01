#pragma once

#include <vector>

namespace Dynamic
{

class MaxSet
{
public:
	MaxSet();
	~MaxSet();

	std::vector<int> getMaxSet();

private:
	void listFromFile();
	std::vector<int> reconstructSet(std::vector<int>& dp);

private:
	std::vector<int> nums;

	std::wstring fileName;
};

}