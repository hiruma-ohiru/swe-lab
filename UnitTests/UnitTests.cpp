#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\tokiy\source\repos\swe-lab\swe-lab\swe-lab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(y_func_get3and2_3returned)
		{
			int n = 3;
			int x = 2;
			double expected = 3;

			double actual = y_func(x, n);

			Assert::AreEqual(expected, actual);
		}
	public:
		TEST_METHOD(y_func_get4andmin6_min5returned)
		{
			int n = 4;
			int x = -6;
			double expected = -5;

			double actual = y_func(x, n);

			Assert::AreEqual(expected, actual);
		}
	};
}
