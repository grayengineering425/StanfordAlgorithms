#pragma once
#include <queue>

namespace Greedy
{

struct HuffmanNode
{
	HuffmanNode(int val)
		:	val		(val)
		,	left	(nullptr)
		,	right	(nullptr)
	{
	}

	int			 val;
	HuffmanNode* left;
	HuffmanNode* right;
};

struct HuffmanNodeCompare
{
	bool operator ()(const HuffmanNode* lhs, const HuffmanNode* rhs)
	{
		return lhs->val > rhs->val;
	}
};

class Huffman
{
public:
	explicit Huffman(bool test=false);

	void	createCoding();
	int		lengthEncoding(bool max);

private:
	void	valuesFromFile		(bool test);
	int		maxLengthEncoding	(HuffmanNode* cur);
	int		minLengthEncoding	(HuffmanNode* cur);

private:
	std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, HuffmanNodeCompare> frequencies;

	std::wstring fileName;

	int numSymbols;

	HuffmanNode* root;
};

}