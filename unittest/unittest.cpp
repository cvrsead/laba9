#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittest
{
	TEST_CLASS(unittest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::Fail();
		}
	};
}
