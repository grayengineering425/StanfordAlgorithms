#include "SCC.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <stack>
#include <queue>

using namespace Graph;

SCC::SCC(bool test)
	:	fileName(L"C:/modules/StanfordAlgorithms/StanfordAlgorithms/x64/Debug/SCC.txt")
{
	valuesFromFile(test);
}

void SCC::run()
{
	std::priority_queue<int, std::vector<int>, std::less<int>> q;

	std::stack<int>		order;
	std::vector<bool>	visited(adjFront.size(), false);
	std::map<int, bool> ordered;

	for (int i=0; i<adjFront.size(); ++i)
	{
		if (!visited[i]) dfsFront(i, visited, order, ordered);
	}

	visited = std::vector<bool>(adjBack.size(), false);

	while (!order.empty())
	{
		auto u = order.top();
		order.pop();

		if (!visited[u])
		{
			q.push(dfsBack(u, visited));
		}
	}

	while (!q.empty())
	{
		auto count = q.top();
		q.pop();

		std::cout << count << std::endl;
	}
}

void SCC::dfsFront(int u, std::vector<bool>& visited, std::stack<int>& order, std::map<int, bool>& ordered)
{
	std::stack<int> dfs;

	dfs.push(u);

	while (!dfs.empty())
	{
		int cur = dfs.top();

		if (visited[cur])
		{
			dfs.pop();

			if (!ordered[cur]) order.push(cur);

			ordered[cur] = true;

			continue;
		}

		visited[cur] = true;

		dfs.push(cur);

		for (int i=0; i< adjBack[cur].size(); ++i)
		{
			int v = adjBack[cur][i];

			if (!visited[v]) dfs.push(v);
		}
	}
}

int SCC::dfsBack(int u, std::vector<bool>& visited)
{
	int count = 0;

	std::stack<int> dfs;

	dfs.push(u);

	while (!dfs.empty())
	{
		int cur = dfs.top();
		dfs.pop();

		if (!visited[cur]) count++;
		
		visited[cur] = true;

		for (int i=0; i< adjFront[cur].size(); ++i)
		{
			int v = adjFront[cur][i];

			if (!visited[v]) dfs.push(v);
		}
	}
	return count;
}

void SCC::valuesFromFile(bool test)
{
	if (test)
	{
		adjFront = std::vector<std::vector<int>>(5, std::vector<int>());
		adjBack  = std::vector<std::vector<int>>(5, std::vector<int>());

		std::vector<std::vector<int>> edges = {{1,0}, {0,2}, {2,1}, {0,3}, {3,4} };
	
		for (const auto& edge: edges){ adjFront[edge[0]].push_back(edge[1]); adjBack[edge[1]].push_back(edge[0]); }
	}

	else
	{
		adjFront = std::vector<std::vector<int>>(875714, std::vector<int>());
		adjBack  = std::vector<std::vector<int>>(875714, std::vector<int>());

		std::ifstream graphFile(fileName);
		std::string line;

		if (graphFile.is_open())
		{
			while (std::getline(graphFile, line))
			{
				std::istringstream iss(line);
				std::vector<std::string> results(std::istream_iterator<std::string>{iss},
					std::istream_iterator<std::string>());

				if (results.size() != 2) continue;

				int u = std::atoi(results[0].c_str()) - 1;
				int v = std::atoi(results[1].c_str()) - 1;

				adjFront[u].push_back(v);
				adjBack [v].push_back(u);
			}
		}
	}
}
