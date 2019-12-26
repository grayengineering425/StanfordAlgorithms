#pragma once
#include <vector>

namespace Graph
{

class Dijkstra
{
public:
	Dijkstra(bool test=false);

	void getShortestPaths(int start);

private:
	void valuesFromFile	(bool test);
	int  dijkstraUtil	(std::vector<bool>& visited, std::vector<int>& dist);

private:
	std::vector<std::vector<int>> adj;

	std::wstring fileName;
};

}