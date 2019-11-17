#include "Prim.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace Greedy;

Prim::Prim(std::vector<std::vector<int>>& list)
	:	adjacencyList	(list)
	,	graphPath		(L"")
{
}

Prim::Prim()
	:	graphPath(L"C:/modules/StanfordAlgorithms/Debug/graph.txt")
{
	graphFromFile();
}

Prim::~Prim() = default;

int Prim::MST()
{
	int cost = 0;

	std::vector<bool> visited(adjacencyList.size(), false	);
	std::vector<int>  keys	 (adjacencyList.size(), INT_MAX	);

	keys[0] = 0;


	for (int i = 0; i < (int)adjacencyList.size(); ++i)
	{
		int minCross = getMinKey(keys, visited);

		cost += keys[minCross];

		updateKeys(minCross, keys, visited);

		visited[minCross] = true;
	}

	return cost;
}

void Prim::updateKeys(int key, std::vector<int>& keys, std::vector<bool>& visited)
{
	for (int i=0; (int)i<adjacencyList[key].size(); ++i)
	{
		int edge = adjacencyList[key][i];
		
		if (!edge || visited[i]) continue;

		if (edge < keys[i]) keys[i] = edge;
	}
}

int Prim::getMinKey(std::vector<int>& keys, std::vector<bool>& visited)
{
	int min		 = INT_MAX;
	int minIndex = -1;
	
	for (int i = 0; i < (int)keys.size(); ++i)
	{
		if (keys[i] < min && !visited[i]) { min = keys[i]; minIndex = i; }
	}

	return minIndex;
}

void Prim::graphFromFile()
{
	std::ifstream graphFile(graphPath);
	std::string line;

	if (graphFile.is_open())
	{
		std::getline(graphFile, line);

		std::istringstream meta(line);
		std::vector<std::string> resultsMeta(std::istream_iterator<std::string>{meta},
			std::istream_iterator<std::string>());

		int numNodes = std::atoi(resultsMeta[0].c_str());

		adjacencyList = std::vector<std::vector<int>>(numNodes, std::vector<int>(numNodes, 0));

		while (std::getline(graphFile, line))
		{
			std::istringstream iss(line);
			std::vector<std::string> results(std::istream_iterator<std::string>{iss},
				std::istream_iterator<std::string>());

			if (results.size() != 3) continue;

			int start  = std::atoi(results[0].c_str()) - 1;
			int end    = std::atoi(results[1].c_str()) - 1;
			int weight = std::atoi(results[2].c_str());

			adjacencyList[start][end  ] = weight;
			adjacencyList[end  ][start] = weight;
		}
	}
}
