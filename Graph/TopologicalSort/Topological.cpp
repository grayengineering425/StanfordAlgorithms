#include "Topological.h"

#include <iostream>

using namespace Graph;

TopologicalSort::TopologicalSort(std::vector<std::vector<int>>& edges, int n)
	:	adj(n, std::vector<int>())
{
	for (const auto& edge: edges) adj[edge[0]].push_back(edge[1]);
}

void TopologicalSort::sort()
{
	std::vector<bool> visited(adj.size(), false);

	for (int i=0; i<adj.size(); ++i)
	{
		if (!visited[i]) dfs(i, visited);
	}

	while (!sorted.empty())
	{
		int cur = sorted.top();
		sorted.pop();

		std::cout << cur << " ";
	}

	std::cout << std::endl;
}

void TopologicalSort::dfs(int u, std::vector<bool>& visited)
{
	visited[u] = true;

	for (int i=0; i<adj[u].size(); ++i)
	{
		int v = adj[u][i];

		if (!visited[v]) dfs(v, visited);
	}
	sorted.push(u);
}
