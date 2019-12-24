#include "Huffman.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace Greedy;

Huffman::Huffman(bool test)
	:	fileName(L"C:/modules/StanfordAlgorithms/x64/Debug/huffman.txt")
{
	valuesFromFile(test);
}

void Huffman::createCoding()
{
	if (frequencies.empty()) return;

	while (!frequencies.empty())
	{
		auto cur1 = frequencies.top();
		frequencies.pop();

		if (frequencies.empty())
		{
			root = cur1;
			return;
		}
		
		auto cur2 = frequencies.top();
		frequencies.pop();

		int sum = cur1->val + cur2->val;

		HuffmanNode* merge = new HuffmanNode(sum);
		merge->left		= cur1;
		merge->right	= cur2;

		frequencies.push(merge);
	}
}

int Huffman::lengthEncoding(bool max)
{
	HuffmanNode* cur = root;

	return max ? maxLengthEncoding(cur) : minLengthEncoding(cur);
}

int Huffman::maxLengthEncoding(HuffmanNode* cur)
{
	if (!cur || !cur->left && !cur->right) return 0;

	int countLeft  = 0;
	int countRight = 0;

	if (cur->left ) countLeft  = 1 + maxLengthEncoding(cur->left );
	if (cur->right) countRight = 1 + maxLengthEncoding(cur->right);

	return std::max(countLeft, countRight);
}

int Huffman::minLengthEncoding(HuffmanNode* cur)
{
	if (!cur || !cur->left && !cur->right) return 0;

	int countLeft  = 0;
	int countRight = 0;

	if (cur->left ) countLeft  = 1 + minLengthEncoding(cur->left );
	if (cur->right) countRight = 1 + minLengthEncoding(cur->right);

	return std::min(countLeft, countRight);
}

void Huffman::valuesFromFile(bool test)
{
	if (test)
	{
		HuffmanNode* a = new HuffmanNode(3);
		HuffmanNode* b = new HuffmanNode(5);
		HuffmanNode* c = new HuffmanNode(6);
		HuffmanNode* d = new HuffmanNode(4);
		HuffmanNode* e = new HuffmanNode(2);

		frequencies.push(a);
		frequencies.push(b);
		frequencies.push(c);
		frequencies.push(d);
		frequencies.push(e);
	}

	else
	{
		std::ifstream graphFile(fileName);
		std::string line;

		if (graphFile.is_open())
		{
			std::getline(graphFile, line);

			std::istringstream meta(line);
			std::vector<std::string> resultsMeta(std::istream_iterator<std::string>{meta},
				std::istream_iterator<std::string>());

			numSymbols = std::atoi(resultsMeta[0].c_str());

			while (std::getline(graphFile, line))
			{
				std::istringstream iss(line);
				std::vector<std::string> results(std::istream_iterator<std::string>{iss},
					std::istream_iterator<std::string>());

				if (results.size() != 1) continue;

				HuffmanNode* node = new HuffmanNode(std::atoi(results[0].c_str()));
				frequencies.push(node);
			}
		}
	}
}
