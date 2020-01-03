#pragma once
#include <string>
#include <vector>

namespace DivandConq
{
struct KaratsubaString
{
	KaratsubaString() = default;

	KaratsubaString(const std::wstring& val)
		:	val(val)
	{
	}

	KaratsubaString operator*(KaratsubaString& rhs)
	{
		std::wstring level;
		std::wstring levelVal	= L"";
		std::wstring result		= L"";

		int carry	= 0;

		for (int i=rhs	.val.size()-1; i>=0; --i)
		for (int j=this->val.size()-1; j>=0; --j)
		{
			int curR = rhs	.val[i] - '0';
			int curL = this->val[j] - '0';

			int curVal = curR * curL + carry;

			carry = curVal / 10;

			std::wstring curValS = std::to_wstring(j == 0 ? curVal : curVal % 10);

			levelVal.insert(0, curValS);

			if (j == 0)
			{
				levelVal	+= level;
				level		+= '0';
				carry		 = 0;

				if (result.empty()) result = levelVal;
				else
				{
					int carryAdd = 0;

					std::wstring addition = L"";

					int rightLevelIndex		= levelVal	.size() - 1;
					int rightResultIndex	= result	.size() - 1;

					while (rightLevelIndex >= 0 || rightResultIndex >= 0)
					{
						int levelRight	= rightLevelIndex  < levelVal	.size() ? levelVal	[rightLevelIndex	] - '0' : 0;
						int resultRight = rightResultIndex < result		.size() ? result	[rightResultIndex	] - '0' : 0;

						int sum = levelRight + resultRight + carryAdd;

						carryAdd = sum / 10;

						std::wstring curAddition = std::to_wstring(rightLevelIndex == 0 ? sum : sum % 10);

						addition.insert(0, curAddition);

						rightLevelIndex	--;
						rightResultIndex--;
					}
					result = addition;
				}
				levelVal = L"";
			}
		}

		return KaratsubaString(result);
	}

	KaratsubaString operator+(KaratsubaString& rhs)
	{
		int carryAdd = 0;
		
		std::wstring addition = L"";
		
		int rightLevelIndex		= this-> val.size() - 1;
		int rightResultIndex	= rhs	.val.size() - 1;
		
		while (rightLevelIndex >= 0 || rightResultIndex >= 0)
		{
			int levelRight	= rightLevelIndex  < this->	 val.size()	?	this->	 val[rightLevelIndex	] - '0' : 0;
			int resultRight = rightResultIndex < rhs	.val.size() ?	rhs		.val[rightResultIndex	] - '0' : 0;
		
			int sum = levelRight + resultRight + carryAdd;
		
			carryAdd = sum / 10;
		
			std::wstring curAddition = std::to_wstring(rightLevelIndex == 0 ? sum : sum % 10);
		
			addition.insert(0, curAddition);
		
			rightLevelIndex	--;
			rightResultIndex--;
		}
		
		return KaratsubaString(addition);
	}

	KaratsubaString operator-(KaratsubaString& rhs)
	{
		std::wstring subtraction = L"";
		
		int rightLevelIndex		= this-> val.size() - 1;
		int rightResultIndex	= rhs	.val.size() - 1;
		
		while (rightLevelIndex >= 0 || rightResultIndex >= 0)
		{
			int levelRight	=										this->	 val[rightLevelIndex	] - '0';
			int resultRight = rightResultIndex < rhs.val.size() ?	rhs		.val[rightResultIndex	] - '0' : 0;
		
			int sub = levelRight - resultRight;
		
			if (sub < 0)
			{
				int i = rightLevelIndex-1;
				while(i >= 0 && this->val[i] < 1) i--;

				this->val[i]--;

				sub += 10;
			}
		
			std::wstring curSubtraction = std::to_wstring(sub);
		
			if (curSubtraction != L"0") subtraction.insert(0, curSubtraction);
		
			rightLevelIndex	--;
			rightResultIndex--;
		}
		
		return KaratsubaString(subtraction);
	}

	std::wstring val;
};

class Karatsuba
{
public:
	Karatsuba(bool test=false);

	KaratsubaString multiply();

private:
	KaratsubaString multiplyHelper(KaratsubaString& val1, KaratsubaString& val2);

private:
	KaratsubaString num1;
	KaratsubaString num2;
};

}