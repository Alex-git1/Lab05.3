#include "pch.h"
#include "CppUnitTest.h"
#include <cmath> 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

double p(const double x);

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(p(1), (cos(sin(1)) + 1) / (exp(-1) + 1), 1e-5);
		}
	};
}

double p(const double x)
{
	if (abs(x) >= 1)
		return (cos(sin(x)) + 1) / (exp(-x) + 1);
	else
	{
		double S = 0;
		int j = 0;
		double a = 1;
		S = a;

		do
		{
			j++;
			double R = -x * x / ((3 * j - 2) * (3 * j - 1) * 3 * j);
			a *= R;
			S += a;
		} while (j < 4);

		return S;
	}
}

