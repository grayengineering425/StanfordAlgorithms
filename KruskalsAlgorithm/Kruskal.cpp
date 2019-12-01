#include "Kruskal.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace Greedy;

Kruskal::Kruskal(std::shared_ptr<Graph>& graph)
	:	graph		(graph)
	,	graphPath	(L"")
	,	parent		(graph->v, -1)
{
}

Kruskal::Kruskal()
	:	graphPath(L"C:/modules/StanfordAlgorithms/x64/Debug/graph.txt")
{
}

Kruskal::~Kruskal() = default;

int Kruskal::MST(int k)
{
	graphFromFile();

	std::sort(graph->edge.begin(), graph->edge.end(), [this](const std::shared_ptr<Edge>& lhs, const std::shared_ptr<Edge>& rhs)
	{
		return lhs->weight < rhs->weight;
	});

	int i		 = 0;
	int clusters = graph->v;

	while (i < graph->e && clusters > k)
	{
		auto e = graph->edge[i++];

		if (!e) continue;

		if (createsCycle(e)) continue;

		createUnion(e->src, e->dst);
		clusters--;
	}

	return getMaxSpacing();
}

int Kruskal::getMaxSpacing()
{
	int maxSpacing = INT_MAX;

	int i = 0;

	while (i < graph->e)
	{	
		auto edge	= graph->edge[i++];
		int  src	= edge->src;
		int  dst	= edge->dst;
		int  weight	= edge->weight;

		int parentSrc = find(src);
		int parentDst = find(dst);

		if (parentSrc != parentDst && weight < maxSpacing) maxSpacing = weight;
	}

	return maxSpacing;
}


void Kruskal::printGraph()
{
	if (!graph) return;

	for (int i=0; i<graph->edge.size(); ++i)
	{
		auto edge = graph->edge[i];

		if (!edge) continue;

		std::cout << edge->src << " -> " << edge->dst << " : " << edge->weight << std::endl;
	}
}

void Kruskal::graphFromFile()
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
		parent = std::vector<int>(numNodes, -1);

		graph = std::make_shared<Graph>(numNodes, 0);

		while (std::getline(graphFile, line))
		{
			std::istringstream iss(line);
			std::vector<std::string> results(std::istream_iterator<std::string>{iss},
				std::istream_iterator<std::string>());

			if (results.size() != 3) continue;

			int start  = std::atoi(results[0].c_str()) - 1;
			int end    = std::atoi(results[1].c_str()) - 1;
			int weight = std::atoi(results[2].c_str());

			auto edge	 = std::make_shared<Edge>();
			edge->src	 = start;
			edge->dst	 = end;
			edge->weight = weight;

			graph->edge.emplace_back(edge);
			graph->e++;
		}
	}
}

bool Kruskal::createsCycle(const std::shared_ptr<Edge>& edge)
{
	if (!edge) return true;

	int start	= edge->src;
	int end		= edge->dst;

	int parentStart = find(start);
	int parentEnd	= find(end);

	return parentStart == parentEnd;
}

int Kruskal::find(int val)
{
	if (parent[val] == -1) return val;

	return find(parent[val]);
}

void Kruskal::createUnion(int x, int y)
{
	int parentX = find(x);
	int parentY = find(y);

	if (parentX != parentY) parent[parentX] = parentY;
}


//HAMMING DISTANCE CLUSTERING

KruskalHamming::KruskalHamming()
	:	numBits(0)
{
	graphPath = L"C:/modules/StanfordAlgorithms/x64/Debug/graph_hamming.txt";
}

KruskalHamming::~KruskalHamming() = default;

int KruskalHamming::MST(int k)
{
	return graphFromFileHamming();
}

void KruskalHamming::checkMask(int val, int mask, int index, int& clusters)
{
	int sibling = val ^ mask;

	if (hammingTable.find(sibling) != hammingTable.end() && hammingTable[sibling] != index)
	{
		int parentX = find(index);
		int parentY = find(hammingTable[sibling]);

		if (parentX != parentY)
		{
			createUnion(index, hammingTable[sibling]);

			clusters--;
		}
	}
	else hammingTable.erase(sibling);
}

int KruskalHamming::graphFromFileHamming()
{
	std::ifstream graphFile(graphPath);
	std::string line;

	int numNodes = 0;

	if (graphFile.is_open())
	{
		std::getline(graphFile, line);

		std::istringstream meta(line);
		std::vector<std::string> resultsMeta(std::istream_iterator<std::string>{meta},
			std::istream_iterator<std::string>());

		numNodes = std::atoi(resultsMeta[0].c_str());
		numBits  = std::atoi(resultsMeta[1].c_str());

		createBitMasks();

		parent = std::vector<int>(numNodes, -1);

		int index = 0;

		while (std::getline(graphFile, line))
		{
			std::istringstream iss(line);
			std::vector<std::string> results(std::istream_iterator<std::string>{iss},
				std::istream_iterator<std::string>());

			if (results.size() != numBits) continue;

			int val = 0;

			for (int i=0; i < results.size(); ++i)
			{
				int bit = std::atoi(results[i].c_str());
				bit = bit << results.size() - 1 - i;
				val = val | bit;
			}

			if (hammingTable.find(val) != hammingTable.end())
			{
				numNodes--;
				continue;
			}
			else
			{
				for (const auto& mask : oneBitMasks)
				{
					checkMask(val, mask, index, numNodes);
				}

				for (const auto& mask : twoBitMasks)
				{
					checkMask(val, mask, index, numNodes);
				}
			}
			hammingTable[val] = index++;
		}
	}
	return numNodes;
}

void KruskalHamming::createBitMasks()
{
	int mask = 1;

	for (int i=0; i<numBits; ++i)
	{
		oneBitMasks.push_back(mask);
		mask = mask << 1;
	}

	createTwoBitMasks();
}

void KruskalHamming::createTwoBitMasks()
{
	int mask = 0;
	
	for (int i=1; i< numBits;	++i)
	{
		mask = 1;
		mask = mask << i;
		mask = mask | 1;

		for (int j=0; j< numBits - i; ++j)
		{
			twoBitMasks.push_back(mask);
			mask = mask << 1;
		}
	}
}
