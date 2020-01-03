#include "PrimsAlgorithm/Prim.h"
#include "Scheduling/Scheduling.h"
#include "KruskalsAlgorithm/Kruskal.h"
#include "DynamicProgramming/MaxIndependentSet/MaxSet.h"
#include "DynamicProgramming/Knapsack/Knapsack.h"
#include "HuffmanCodes/Huffman.h"
#include "Graph/TopologicalSort/Topological.h"
#include "Graph/SCC/SCC.h"
#include "Graph/Dijsktra/Dijsktra.h"
#include "DivideAndConquer/Karatsuba/Karatsuba.h"
#include "DivideAndConquer/Inversions/Inversions.h"

#include <iostream>

using namespace Greedy;
using namespace Dynamic;
using namespace Graph;
using namespace DivandConq;

int main()
{
	Inversions i(false);
	std::cout << i.getNumInversions();
	return 0;
}