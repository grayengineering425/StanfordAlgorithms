#pragma once
#include <vector>

namespace Graph
{

class Tarjan
{
public:
	Tarjan(std::vector<std::vector<int>>& edges, int n);

	void stronglyConnected();

private:
	void dfs(std::vector<int>& dist, std::vector<int>& low, int& time, int node, int start);

private:
	std::vector<std::vector<int>> adj;
};

}