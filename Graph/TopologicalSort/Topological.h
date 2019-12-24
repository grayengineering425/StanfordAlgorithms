#pragma once
#include <vector>
#include <stack>

namespace Graph
{

class TopologicalSort
{
public:
	TopologicalSort(std::vector<std::vector<int>>& edges, int n);

	void sort();

private:
	void dfs(int u, std::vector<bool>& visited);

private:
	std::vector<std::vector<int>>	adj;
	std::stack<int>					sorted;
};

}