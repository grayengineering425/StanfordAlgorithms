#include "PrimsAlgorithm/Prim.h"
#include "Scheduling/Scheduling.h"
#include "KruskalsAlgorithm/Kruskal.h"
#include "DynamicProgramming/MaxIndependentSet/MaxSet.h"
#include "DynamicProgramming/Knapsack/Knapsack.h"
#include "HuffmanCodes/Huffman.h"
#include "Graph/TopologicalSort/Topological.h"

#include <iostream>

using namespace Greedy;
using namespace Dynamic;
using namespace Graph;

int main()
{
	std::vector<std::vector<int>> edges = { { 5, 2 }, { 5, 0 }, { 4, 0 }, { 4, 1 }, { 2, 3 }, { 3, 1 } };
	int n = 6;

	TopologicalSort t(edges, n);
	t.sort();

	return 0;
}