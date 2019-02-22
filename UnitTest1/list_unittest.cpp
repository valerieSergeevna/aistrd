#include "stdafx.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../Проект3/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod_size)
		{
			List list2;
			list2.push_back(40);
			list2.push_back(10);
			list2.push_back(50);
			size_t size = 3;
			Assert::IsTrue(list2.get_size() == size);
		}

		TEST_METHOD(TestMethod_size_Empty)
		{
			List list2;
			Assert::IsTrue(list2.get_size() == 0);
		}

		TEST_METHOD(TestMethod_push_back)
		{
			List list2;
			list2.push_front(40);
			list2.push_front(10);
			list2.push_back(50);
			size_t data = 50;
			Assert::IsTrue(list2.get_back() == data);
		}

		TEST_METHOD(TestMethod_push_back_empty)
		{
			List list2;
			list2.push_back(50);
			size_t data = 50;
			Assert::IsTrue(list2.get_back() == data);
		}

		TEST_METHOD(TestMethod_pop_back)
		{
			List list2;
			list2.push_front(40);
			list2.push_front(10);
			list2.push_back(50);
			list2.pop_back();
			size_t data = 40;
			Assert::IsTrue(list2.get_back() == data);
		}


		TEST_METHOD(TestMethod_pop_back_one)
		{
			List list2;
			list2.push_front(40);
			list2.pop_back();
			Assert::IsTrue(list2.isEmpty());
		}

		TEST_METHOD(TestMethod_push_front)
		{
			List list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			size_t data = 10;
			Assert::IsTrue(list2.get_front() == data);
		}

		TEST_METHOD(TestMethod_push_front_empty)
		{
			List list2;
			list2.push_front(10);
			size_t data = 10;
			Assert::IsTrue(list2.get_front() == data);
		}

		TEST_METHOD(TestMethod_pop_front)
		{
			List list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.pop_front();
			size_t data = 50;
			Assert::IsTrue(list2.get_front() == data);
		}

		TEST_METHOD(TestMethod_at)
		{
			List list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			size_t data = 50;
			Assert::IsTrue(list2.at(1) == data);
		}

		TEST_METHOD(TestMethod_at_front)
		{
			List list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			size_t data = 10;
			Assert::IsTrue(list2.at(0) == data);
		}

		TEST_METHOD(TestMethod_isEmpty)
		{
			List list2;
			Assert::IsTrue(list2.isEmpty());
		}

		TEST_METHOD(TestMethod_isEmpty_one)
		{
			List list2;
			list2.push_front(10);
			Assert::IsFalse(list2.isEmpty());
		}

		TEST_METHOD(TestMethod_set)
		{
			List list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.set(1, 9);
			size_t data = 9;
			Assert::IsTrue(list2.at(1) == data);
		}

		TEST_METHOD(TestMethod_clear)
		{
			List list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.clear();
			Assert::IsTrue(list2.isEmpty());
		}

		TEST_METHOD(TestMethod_clear_one)
		{
			List list2;
			list2.push_front(10);
			list2.clear();
			Assert::IsTrue(list2.isEmpty());
		}


		TEST_METHOD(TestMethod_clear_Empty)
		{
			List list2;

			try
			{
				list2.clear();
			}
			catch (const std::out_of_range& error)
			{

				Assert::AreEqual("List is empty", error.what());
			}

		}
		//тест на первый нужно
		//если удалить из исходного, то измененийне должно быть в новом
		TEST_METHOD(TestMethod_Del)
		{
			int data = 40;

			List list2;
			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.Delete(1);

			Assert::AreEqual(list2.at(1), data);
		}

		TEST_METHOD(TestMethod_Del_front)
		{
			int data = 50;

			List list2;
			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.Delete(0);

			Assert::AreEqual(list2.at(0), data);
		}

		TEST_METHOD(TestMethod_Del_back)
		{
			int data = 50;

			List list2;
			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.Delete(2);
			Assert::IsTrue(list2.get_back() == data);
		}

		TEST_METHOD(TestMethod_Del_One)
		{
			List list2;

			list2.push_back(50);
			list2.Delete(0);
			Assert::IsTrue(list2.isEmpty());
		}

		TEST_METHOD(TestMethod_Del_Empty)
		{
			List list2;

			try
			{
				list2.Delete(1);
			}
			catch (const std::out_of_range& error)
			{

				Assert::AreEqual("List is empty", error.what());
			}

		}


		TEST_METHOD(TestMethod_Insert)
		{
			List list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.insert(1, 1);
			size_t data = 1;
			Assert::IsTrue(list2.at(1) == data);
		}

		TEST_METHOD(TestMethod_Insert_0)
		{
			List list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.insert(1, 0);
			size_t data = 1;
			Assert::IsTrue(list2.at(0) == data);
		}

		TEST_METHOD(TestMethod_Insert_to_Empty)
		{
			List list2;
			try
			{
				list2.insert(1, 0);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Index is greater than list size", error.what());
			}
		}


		TEST_METHOD(TestMethod_Insert_end)
		{
			List list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.insert(1, 2);

			int data = 1;

			Assert::AreEqual(list2.at(2), data);
		}


		TEST_METHOD(TestMethod_push_front_list)
		{
			int check_array[6] = { 40, 10, 50, 4, 1, 5 };

			List list;
			list.push_back(4);
			list.push_back(1);
			list.push_back(5);

			List list2;
			list2.push_back(40);
			list2.push_back(10);
			list2.push_back(50);
			list2.get_back();

			list.push_front_list(list2);

			for (size_t i = 0; i < list.get_size(); i++)
				Assert::AreEqual(list.at(i), check_array[i]);
		}

		TEST_METHOD(TestMethod_push_front_list_with_Del_elem_from_list2)
		{
			int check_array[6] = { 40, 10, 50, 4, 1, 5 };

			List list;
			list.push_back(4);
			list.push_back(1);
			list.push_back(5);

			List list2;
			list2.push_back(40);
			list2.push_back(10);
			list2.push_back(50);

			list.push_front_list(list2);

			list2.Delete(2);

			for (size_t i = 0; i < list.get_size(); i++)
				Assert::AreEqual(list.at(i), check_array[i]);
		}
	};
}