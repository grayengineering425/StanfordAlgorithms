#include "PrimsAlgorithm/Prim.h"
#include "Scheduling/Scheduling.h"
#include "KruskalsAlgorithm/Kruskal.h"
#include "DynamicProgramming/MaxIndependentSet/MaxSet.h"
#include "DynamicProgramming/Knapsack/Knapsack.h"
#include "HuffmanCodes/Huffman.h"

#include <iostream>

using namespace Greedy;

using namespace Dynamic;

int main()
{
	Huffman h;
	h.createCoding();
	std::cout << h.lengthEncoding(true ) << std::endl;
	std::cout << h.lengthEncoding(false) << std::endl;

	return 0;
}