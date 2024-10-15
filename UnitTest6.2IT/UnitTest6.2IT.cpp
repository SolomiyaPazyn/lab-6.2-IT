#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 6.2 IT.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62IT
{
	TEST_CLASS(UnitTest62IT)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
				int b[] = { -5, -3, 0, 3, 5 };
				const int size = 5;
				double expected = 0.0; 

				Assert::AreEqual(AverageMinMax(b, size), expected);
		}
	};
}
