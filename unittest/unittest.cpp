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
			int i = 3;
			doclad* arr = new doclad[i];
			arr[0].start.hours = 11;
			arr[0].end.hours = 12;
			arr[0].start.minutes = 30;
			arr[0].end.minutes = 0;
			arr[1].start.hours = 14;
			arr[1].end.hours = 14;
			arr[1].start.minutes = 10;
			arr[1].end.minutes = 20;
			arr[2].start.hours = 11;
			arr[2].end.hours = 11;
			arr[2].start.minutes = 20;
			arr[2].end.minutes = 30;
			Assert::AreEqual(30, process(arr, i));
		}
		TEST_METHOD(TestMethod2)
		{
			int i = 3;
			doclad* arr = new doclad[i];
			arr[0].start.hours = 11;
			arr[0].end.hours = 13;
			arr[0].start.minutes = 30;
			arr[0].end.minutes = 0;
			arr[1].start.hours = 14;
			arr[1].end.hours = 14;
			arr[1].start.minutes = 10;
			arr[1].end.minutes = 20;
			arr[2].start.hours = 11;
			arr[2].end.hours = 11;
			arr[2].start.minutes = 20;
			arr[2].end.minutes = 30;
			Assert::AreEqual(90, process(arr, i));
		}
		TEST_METHOD(TestMethod3)
		{
			int i = 3;
			doclad* arr = new doclad[i];
			arr[0].start.hours = 11;
			arr[0].end.hours = 12;
			arr[0].start.minutes = 30;
			arr[0].end.minutes = 0;
			arr[1].start.hours = 14;
			arr[1].end.hours = 14;
			arr[1].start.minutes = 10;
			arr[1].end.minutes = 20;
			arr[2].start.hours = 11;
			arr[2].end.hours = 15;
			arr[2].start.minutes = 20;
			arr[2].end.minutes = 30;
			Assert::AreEqual(250, process(arr, i));
		}
	};
}
