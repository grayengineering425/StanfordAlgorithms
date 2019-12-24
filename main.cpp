#include "PrimsAlgorithm/Prim.h"
#include "Scheduling/Scheduling.h"
#include "Graph/Tarjan/Tarjan.h"

#include <iostream>

using namespace Greedy;
using namespace Graph;

int main()
{
	std::vector<std::vector<int>> edges = { {0,1},{1,2},{2,0},{1,3} };
	int n = 4;

	Tarjan t(edges, n);
	t.stronglyConnected();

	//-3612829
}