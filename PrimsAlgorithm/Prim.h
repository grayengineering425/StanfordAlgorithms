#pragma once

#include <vector>
#include <filesystem>

namespace Greedy
{
class Prim
{
public:
	explicit Prim(std::vector<std::vector<int>>& edges);
	Prim();
	~Prim();

	int MST();

private:
	void	updateKeys(int key, std::vector<int>& keys, std::vector<bool>& visited);
	int		getMinKey (std::vector<int>& keys, std::vector<bool>& visited);

	void	graphFromFile();

private:
	std::vector<std::vector<int>> adjacencyList;

	std::wstring graphPath;
};

}