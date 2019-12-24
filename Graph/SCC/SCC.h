#pragma once
#include <vector>
#include <stack>
#include <map>

namespace Graph
{

class SCC
{
public:
	SCC(bool test=false);

	void run();

private:
	void dfsFront(int u, std::vector<bool>& visited, std::stack<int>& order, std::map<int, bool>& ordered);
	int  dfsBack (int u, std::vector<bool>& visited);

	void valuesFromFile(bool test);

private:
	std::vector<std::vector<int>> adjFront;
	std::vector<std::vector<int>> adjBack;

	std::wstring fileName;
};

}