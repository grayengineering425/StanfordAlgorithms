#include "PrimsAlgorithm/Prim.h"
#include "Scheduling/Scheduling.h"
#include "KruskalsAlgorithm/Kruskal.h"
#include "DynamicProgramming/MaxIndependentSet/MaxSet.h"
#include "DynamicProgramming/Knapsack/Knapsack.h"
#include "HuffmanCodes/Huffman.h"
#include "Graph/TopologicalSort/Topological.h"
#include "Graph/SCC/SCC.h"

#include <iostream>

using namespace Greedy;
using namespace Dynamic;
using namespace Graph;

int main()
{
	SCC s(false);
	s.run();

	return 0;
}