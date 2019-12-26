#include "PrimsAlgorithm/Prim.h"
#include "Scheduling/Scheduling.h"
#include "KruskalsAlgorithm/Kruskal.h"
#include "DynamicProgramming/MaxIndependentSet/MaxSet.h"
#include "DynamicProgramming/Knapsack/Knapsack.h"
#include "HuffmanCodes/Huffman.h"
#include "Graph/TopologicalSort/Topological.h"
#include "Graph/SCC/SCC.h"
#include "Graph/Dijsktra/Dijsktra.h"

#include <iostream>

using namespace Greedy;
using namespace Dynamic;
using namespace Graph;

int main()
{
	Dijkstra d(false);
	d.getShortestPaths(0);

	return 0;
}