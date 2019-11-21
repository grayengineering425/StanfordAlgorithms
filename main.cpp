#include "PrimsAlgorithm/Prim.h"
#include "Scheduling/Scheduling.h"

#include <iostream>

using namespace Greedy;

int main()
{
	Scheduling s(true);

	std::cout << s.getCompletionTime() << "\n";

	return 0;

	//-3612829
}