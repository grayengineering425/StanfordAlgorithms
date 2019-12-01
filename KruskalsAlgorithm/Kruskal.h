#pragma once

#include <memory>
#include <filesystem>
#include <unordered_map>
#include <set>

namespace Greedy
{

struct Edge
{
	Edge()
		:	src		(-1)
		,	dst		(-1)
		,	weight	(-1)
	{
	}

	int src;
	int dst;
	int weight;
};

struct Graph
{
	Graph(int v, int e)
		:	v	(v)
		,	e	(e)
	{
		for (int i=0; i<e; i++) edge.emplace_back(std::make_shared<Edge>());
	}

	int v;
	int e;

	std::vector<std::shared_ptr<Edge>> edge;
};

class Kruskal
{
public:
	explicit Kruskal(std::shared_ptr<Graph>& graph);

	Kruskal();
	virtual ~Kruskal();

	virtual int MST(int k);

	void printGraph();

protected:
	virtual void graphFromFile();

	//Union-Set
	bool	createsCycle(const std::shared_ptr<Edge>& edge);
	int		find		(int val);
	void	createUnion	(int x, int y);

	int		getMaxSpacing();

protected:
	std::shared_ptr<Graph>	graph;
	std::vector<int>		parent;

	std::wstring graphPath;
};

class KruskalHamming : public Kruskal
{
public:
	KruskalHamming();
	virtual ~KruskalHamming();

	int MST(int k) override;

private:
	int graphFromFileHamming();

	void createBitMasks		();
	void createTwoBitMasks	();

	void checkMask(int val, int mask, int index, int& clusters);

private:
	std::vector<std::vector<int>>	nodes;
	std::unordered_map<int, int>	hammingTable;

	std::vector<int> oneBitMasks;
	std::vector<int> twoBitMasks;

	int numBits;
};

}