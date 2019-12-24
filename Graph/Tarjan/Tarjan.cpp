#include "Tarjan.h"

#include <algorithm>
#include <iostream>

using namespace Graph;

Tarjan::Tarjan(std::vector<std::vector<int>>& edges, int n)
	:	adj(n, std::vector<int>())
{
	for (const auto& edge : edges) { adj[edge[0]].push_back(edge[1]); adj[edge[1]].push_back(edge[0]); }
}

void Tarjan::stronglyConnected()
{
	int time = 0;

	std::vector<int> dist(adj.size(), -1);
	std::vector<int> low (adj.size(), INT_MAX);

	for (int i = 0; i < adj.size(); ++i)
	{
		if (dist[i] == -1) dfs(dist, low, time, i, i);
	}

	//check for strongly connected components after we finish getting info
}

void Tarjan::dfs(std::vector<int>& dist, std::vector<int>& low, int& time, int node, int start)
{
	dist[node] = low[node] = ++time;

	for (int i = 0; i < adj[node].size(); ++i)
	{
		int child = adj[node][i];

		if (dist[child] == -1)
		{
			dfs(dist, low, time, child, start);

			low[node] = std::min(low[node], low[child]);

			if (low[child] >= dist[node])
				std::cout << node << "->" << child << std::endl;
		}

		else
			low[node] = std::min(low[node], dist[child]);
	}
}
