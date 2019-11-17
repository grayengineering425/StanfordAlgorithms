#include "PrimsAlgorithm/Prim.h"
#include "Scheduling/Scheduling.h"

#include <iostream>

using namespace Greedy;

int main()
{
	Scheduling s(false);

	std::cout << s.getCompletionTime() << "\n";

	return 0;

	//-3612829
}