#include "Dijsktra.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace Graph;

Dijkstra::Dijkstra(bool test)
	:	fileName(L"C:/modules/StanfordAlgorithms/StanfordAlgorithms/x64/Debug/DIJK.txt")
{
	valuesFromFile(test);
}

void Dijkstra::getShortestPaths(int start)
{
	std::vector<bool> visited (adj.size(), false	 );
	std::vector<int> dist	 (adj.size(), INT_MAX);

	dist[start] = 0;

	for (int i=0; i<adj.size()-1; ++i)
	{
		int shortest = dijkstraUtil(visited, dist);
		visited[shortest] = true;

		for (int i=0; i<adj[shortest].size(); ++i)
		{
			if (adj[shortest][i] && !visited[i] && adj[shortest][i] + dist[shortest] < dist[i]) dist[i] = dist[shortest] + adj[shortest][i];
		}
	}

	for (int i=0; i<dist.size(); ++i)
	{
		if (i == 6 || i == 36 || i == 58 || i == 81 || i == 98 || i == 114 || i == 132 || i == 164 || i == 187 || i == 196) std::cout << dist[i] << (i != 196 ? "," : "");
	}
	std::cout << std::endl;
}

void Dijkstra::valuesFromFile(bool test)
{
	if(test)
	{
		adj = std::vector<std::vector<int>> { { 0, 4,  0, 0,  0, 0,  0, 8,  0	},
											{	4, 0,  8, 0,  0, 0,  0, 11, 0	},
											{	0, 8,  0, 7,  0, 4,  0, 0,  2	},
											{	0, 0,  7, 0,  9, 14, 0, 0,  0	},
											{	0, 0,  0, 9,  0, 10, 0, 0,  0	},
											{	0, 0,  4, 14, 10, 0, 2, 0,  0	},
											{	0, 0,  0, 0,  0,  2, 0, 1,  6	},
											{	8, 11, 0, 0,  0,  0, 1, 0,  7	},
											{	0, 0,  2, 0,  0,  0, 6, 7,  0	} };
	}
	else
	{
		adj = std::vector<std::vector<int>>(200, std::vector<int>(200, 0));

		std::ifstream graphFile(fileName);
		std::string line;

		if (graphFile.is_open())
		{
			while (std::getline(graphFile, line))
			{
				std::istringstream iss(line);
				std::vector<std::string> results(std::istream_iterator<std::string>{iss},
					std::istream_iterator<std::string>());

				int node = std::atoi(results[0].c_str()) - 1;

				for (int i=1; i<results.size(); ++i)
				{
					std::string result = results[i];

					std::string firstNum	= "";
					std::string secondNum	= "";

					int j = 0;
					while (result[j] != ',') firstNum += result[j++];
					j++;

					while (j < result.size()) secondNum += result[j++];

					int dest = std::atoi(firstNum .c_str()) - 1;
					int dist = std::atoi(secondNum.c_str());

					adj[node][dest] = dist;
				}
			}
		}
	}
}

int Dijkstra::dijkstraUtil(std::vector<bool>& visited, std::vector<int>& dist)
{
	int min		= INT_MAX;
	int minNode = -1;

	for (int i=0; i<dist.size(); ++i)
	{
		if (!visited[i] && dist[i] < min)
		{
			min		= dist[i];
			minNode = i;
		}
	}
	return minNode;
}
