#include "pch.h"
#include "CppUnitTest.h"
#include "../main/proccesing.h"
#include "../main/structs.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittest
{
	TEST_CLASS(unittest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			struct doclad a;
			struct doclad b;
			struct doclad c;
			a.end.hours = 13;
			a.start.hours = 12;
			a.end.minutes = 0;
			a.start.minutes = 40;
			b.end.hours = 16;
			b.start.hours = 16;
			b.end.minutes = 40;
			b.start.minutes = 10;
			c.end.hours = 15;
			c.start.hours = 15;
			c.end.minutes = 40;
			c.start.minutes = 30;
			Assert::AreEqual(30, process(a,b,c));
		}
		TEST_METHOD(TestMethod2)
		{
			struct doclad a;
			struct doclad b;
			struct doclad c;
			a.end.hours = 14;
			a.start.hours = 12;
			a.end.minutes = 0;
			a.start.minutes = 40;
			b.end.hours = 16;
			b.start.hours = 16;
			b.end.minutes = 38;
			b.start.minutes = 14;
			c.end.hours = 15;
			c.start.hours = 15;
			c.end.minutes = 40;
			c.start.minutes = 27;
			Assert::AreEqual(80, process(a, b, c));
		}
		TEST_METHOD(TestMethod3)
		{
			struct doclad a;
			struct doclad b;
			struct doclad c;
			a.end.hours = 14;
			a.start.hours = 12;
			a.end.minutes = 0;
			a.start.minutes = 40;
			b.end.hours = 16;
			b.start.hours = 16;
			b.end.minutes = 38;
			b.start.minutes = 14;
			c.end.hours = 19;
			c.start.hours = 15;
			c.end.minutes = 40;
			c.start.minutes = 27;
			Assert::AreEqual(253, process(a, b, c));
		}
	};
}
