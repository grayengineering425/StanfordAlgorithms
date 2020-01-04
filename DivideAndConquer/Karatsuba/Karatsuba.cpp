#include "Karatsuba.h"

#include <algorithm>

using namespace DivandConq;

Karatsuba::Karatsuba(bool test)
{
	num1 = test ? KaratsubaString(L"12") : KaratsubaString(L"3141592653589793238462643383279502884197169399375105820974944592");
	num2 = test ? KaratsubaString(L"12") : KaratsubaString(L"2718281828459045235360287471352662497757247093699959574966967627");
}

KaratsubaString Karatsuba::multiply()
{
	return multiplyHelper(num1, num2);
}

KaratsubaString Karatsuba::multiplyHelper(KaratsubaString& val1, KaratsubaString& val2)
{
	if (val1.val.size() < 2 || val2.val.size() < 2) return val1 * val2;

	int fullSize = std::max(val1.val.size(), val2.val.size());
	int halfSize = fullSize / 2;

	auto a	= val1;
	auto b  = val1;
	a.val	= a .val.substr(0, halfSize);
	b.val	= b.val.substr(halfSize, val1.val.size());

	auto c  = val2;
	auto d  = val2;
	c .val	= c .val.substr(0, halfSize);
	d.val	= d.val.substr(halfSize, val2.val.size());

	KaratsubaString ac = multiplyHelper(a, c);
	KaratsubaString bd = multiplyHelper(b, d);

	KaratsubaString ab = a + b;
	KaratsubaString cd = c + d;

	KaratsubaString adPlusBc = multiplyHelper(ab, cd) - ac - bd;

	for (int i=0; i<fullSize; ++i) ac		.val += L"0";
	for (int i=0; i<halfSize; ++i) adPlusBc	.val += L"0";

	return ac + adPlusBc + bd;
}
