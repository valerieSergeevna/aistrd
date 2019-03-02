#include "stdafx.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../Проект3/List.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod_size)
		{
			List<int> list2;
			list2.push_back(40);
			list2.push_back(10);
			list2.push_back(50);
			size_t size = 3;
			Assert::IsTrue(list2.get_size() == size);
		}

		TEST_METHOD(TestMethod_size_Empty)
		{
			List<int> list2;
			Assert::IsTrue(list2.get_size() == 0);
		}

		TEST_METHOD(TestMethod_push_back)
		{
			List<int> list2;
			list2.push_front(40);
			list2.push_front(10);
			list2.push_back(50);
			size_t data = 50;
			Assert::IsTrue(list2.get_back() == data);
		}

		TEST_METHOD(TestMethod_push_back_empty)
		{
			List<int> list2;
			list2.push_back(50);
			size_t data = 50;
			Assert::IsTrue(list2.get_back() == data);
		}

		TEST_METHOD(TestMethod_pop_back)
		{
			List <int>list2;
			list2.push_front(40);
			list2.push_front(10);
			list2.push_back(50);
			list2.pop_back();
			size_t data = 40;
			Assert::IsTrue(list2.get_back() == data);
		}


		TEST_METHOD(TestMethod_pop_back_one)
		{
			List<int> list2;
			list2.push_front(40);
			list2.pop_back();
			Assert::IsTrue(list2.isEmpty());
		}

		TEST_METHOD(TestMethod_push_front)
		{
			List<int> list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			size_t data = 10;
			Assert::IsTrue(list2.get_front() == data);
		}

		TEST_METHOD(TestMethod_push_front_empty)
		{
			List<int> list2;
			list2.push_front(10);
			size_t data = 10;
			Assert::IsTrue(list2.get_front() == data);
		}

		TEST_METHOD(TestMethod_pop_front)
		{
			List<int> list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.pop_front();
			size_t data = 50;
			Assert::IsTrue(list2.get_front() == data);
		}

		TEST_METHOD(TestMethod_at)
		{
			List <int>list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			size_t data = 50;
			Assert::IsTrue(list2.at(1) == data);
		}

		TEST_METHOD(TestMethod_at_front)
		{
			List <int>list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			size_t data = 10;
			Assert::IsTrue(list2.at(0) == data);
		}

		TEST_METHOD(TestMethod_isEmpty)
		{
			List<int> list2;
			Assert::IsTrue(list2.isEmpty());
		}

		TEST_METHOD(TestMethod_isEmpty_one)
		{
			List<int> list2;
			list2.push_front(10);
			Assert::IsFalse(list2.isEmpty());
		}

		TEST_METHOD(TestMethod_set)
		{
			List<int> list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.set(1, 9);
			size_t data = 9;
			Assert::IsTrue(list2.at(1) == data);
		}

		TEST_METHOD(TestMethod_clear)
		{
			List<int> list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.clear();
			Assert::IsTrue(list2.isEmpty());
		}

		TEST_METHOD(TestMethod_clear_one)
		{
			List<int> list2;
			list2.push_front(10);
			list2.clear();
			Assert::IsTrue(list2.isEmpty());
		}


		TEST_METHOD(TestMethod_clear_Empty)
		{
			List<int> list2;

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
			int data = 50;

			List<int> list2;
			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.Delete(1);

			Assert::AreEqual(list2.at(1), data);
		}

		TEST_METHOD(TestMethod_Del_front)
		{
			int data = 50;

			List<int> list2;
			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.Delete(0);

			Assert::AreEqual(list2.at(0), data);
		}

		TEST_METHOD(TestMethod_Del_back)
		{
			int data = 50;

			List<int> list2;
			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.Delete(2);
			Assert::IsTrue(list2.get_back() == data);
		}

		TEST_METHOD(TestMethod_Del_One)
		{
			List<int> list2;

			list2.push_back(50);
			list2.Delete(0);
			Assert::IsTrue(list2.isEmpty());
		}

		TEST_METHOD(TestMethod_Del_Empty)
		{
			List<int> list2;

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
			List<int> list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.insert(1, 1);
			size_t data = 1;
			Assert::IsTrue(list2.at(1) == data);
		}

		TEST_METHOD(TestMethod_Insert_0)
		{
			List<int> list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.insert(1, 0);
			size_t data = 1;
			Assert::IsTrue(list2.at(0) == data);
		}

		TEST_METHOD(TestMethod_Insert_to_Empty)
		{
			List<int> list2;
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
			List<int> list2;

			list2.push_back(50);
			list2.push_back(40);
			list2.push_front(10);
			list2.insert(1, 2);

			int data = 1;

			Assert::AreEqual(list2.at(2), data);
		}


		
		//string


		TEST_METHOD(TestMethod_size_string)
		{
			List<string> list2;
			list2.push_back("pop");
			list2.push_back("nos");
			list2.push_back("son");
			size_t size = 3;
			Assert::IsTrue(list2.get_size() == size);
		}

		TEST_METHOD(TestMethod_size_Empty_string)
		{
			List<string> list2;
			Assert::IsTrue(list2.get_size() == 0);
		}

		TEST_METHOD(TestMethod_push_back_string)
		{
			List<string> list2;
			list2.push_front("pop");
			list2.push_front("nos");
			list2.push_back("son");
			string data = "son";
			Assert::IsTrue(list2.get_back() == data);
		}

		TEST_METHOD(TestMethod_push_back_empty_string)
		{
			List<string> list2;
			list2.push_back("son");
			string data = "son";
			Assert::IsTrue(list2.get_back() == data);
		}

		TEST_METHOD(TestMethod_pop_back_string)
		{
			List <string>list2;
			list2.push_front("pop");
			list2.push_front("nos");
			list2.push_back("son");
			list2.pop_back();
			string data = "pop";
			Assert::IsTrue(list2.get_back() == data);
		}


		TEST_METHOD(TestMethod_pop_back_one_string)
		{
			List<string> list2;
			list2.push_front("pop");
			list2.pop_back();
			Assert::IsTrue(list2.isEmpty());
		}

		TEST_METHOD(TestMethod_push_front_string)
		{
			List<string> list2;

			list2.push_back("son");
			list2.push_back("pop");
			list2.push_front("nos");
			string data = "nos";
			Assert::IsTrue(list2.get_front() == data);
		}

		TEST_METHOD(TestMethod_push_front_empty_string)
		{
			List<string> list2;
			list2.push_front("nos");
			string data = "nos";
			Assert::IsTrue(list2.get_front() == data);
		}

		TEST_METHOD(TestMethod_pop_front_string)
		{
			List<string> list2;

			list2.push_back("son");
			list2.push_back("pop");
			list2.push_front("nos");
			list2.pop_front();
			string data = "son";
			Assert::IsTrue(list2.get_front() == data);
		}

		TEST_METHOD(TestMethod_at_string)
		{
			List <string>list2;

			list2.push_back("son");
			list2.push_back("pop");
			list2.push_front("nos");
			string data = "son";
			Assert::IsTrue(list2.at(1) == data);
		}

		TEST_METHOD(TestMethod_at_front_string)
		{
			List <string>list2;

			list2.push_back("son");
			list2.push_back("pop");
			list2.push_front("nos");
			string data = "nos";
			Assert::IsTrue(list2.at(0) == data);
		}

		TEST_METHOD(TestMethod_isEmpty_string)
		{
			List<string> list2;
			Assert::IsTrue(list2.isEmpty());
		}

		TEST_METHOD(TestMethod_isEmpty_one_string)
		{
			List<string> list2;
			list2.push_front("nos");
			Assert::IsFalse(list2.isEmpty());
		}

		TEST_METHOD(TestMethod_set_string)
		{
			List<string> list2;

			list2.push_back("son");
			list2.push_back("pop");
			list2.push_front("nos");
			list2.set(1, "con");
			string data = "con";
			Assert::IsTrue(list2.at(1) == data);
		}

		TEST_METHOD(TestMethod_clear_string)
		{
			List<string> list2;

			list2.push_back("son");
			list2.push_back("pop");
			list2.push_front("nos");
			list2.clear();
			Assert::IsTrue(list2.isEmpty());
		}

		TEST_METHOD(TestMethod_clear_one_string)
		{
			List<string> list2;
			list2.push_front("nos");
			list2.clear();
			Assert::IsTrue(list2.isEmpty());
		}


		TEST_METHOD(TestMethod_clear_Empty_string)
		{
			List<string> list2;

			try
			{
				list2.clear();
			}
			catch (const std::out_of_range& error)
			{

				Assert::AreEqual("List is empty", error.what());
			}

		}
		
		TEST_METHOD(TestMethod_Del_string)
		{
			string data = "son";

			List<string> list2;
			list2.push_back("son");
			list2.push_back("pop");
			list2.push_front("nos");
			list2.Delete(1);

			Assert::AreEqual(list2.at(1), data);
		}

		TEST_METHOD(TestMethod_Del_front_string)
		{
			string data = "son";

			List<string> list2;
			list2.push_back("son");
			list2.push_back("pop");
			list2.push_front("nos");
			list2.Delete(0);

			Assert::AreEqual(list2.at(0), data);
		}

		TEST_METHOD(TestMethod_Del_back_string)
		{
			string data = "son";

			List<string> list2;
			list2.push_back("son");
			list2.push_back("pop");
			list2.push_front("nos");
			list2.Delete(2);
			Assert::IsTrue(list2.get_back() == data);
		}

		TEST_METHOD(TestMethod_Del_One_string)
		{
			List<string> list2;

			list2.push_back("son");
			list2.Delete(0);
			Assert::IsTrue(list2.isEmpty());
		}

		TEST_METHOD(TestMethod_Del_Empty_string)
		{
			List<string> list2;

			try
			{
				list2.Delete(1);
			}
			catch (const std::out_of_range& error)
			{

				Assert::AreEqual("List is empty", error.what());
			}

		}


		TEST_METHOD(TestMethod_Insert_string)
		{
			List<string> list2;

			list2.push_back("son");
			list2.push_back("pop");
			list2.push_front("nos");
			list2.insert("cat", 1);
			string data = "cat";
			Assert::IsTrue(list2.at(1) == data);
		}

		TEST_METHOD(TestMethod_Insert_0_string)
		{
			List<string> list2;

			list2.push_back("son");
			list2.push_back("pop");
			list2.push_front("nos");
			list2.insert("cat", 0);
			string data = "cat";
			Assert::IsTrue(list2.at(0) == data);
		}

		TEST_METHOD(TestMethod_Insert_to_Empty_string)
		{
			List<string> list2;
			try
			{
				list2.insert("cat", 0);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Index is greater than list size", error.what());
			}
		}


		TEST_METHOD(TestMethod_Insert_end_string)
		{
			List<string> list2;

			list2.push_back("son");
			list2.push_back("pop");
			list2.push_front("nos");
			list2.insert("cat", 2);

			string data = "cat";

			Assert::AreEqual(list2.at(2), data);
		}

		//double
		TEST_METHOD(TestMethod_push_front_double)
		{
			List<double> list2;

			list2.push_back(50);
			list2.push_back(0.40);
			list2.push_front(10.908);
			double data = 10.908;
			Assert::IsTrue(list2.get_front() == data);
		}

		TEST_METHOD(TestMethod_push_front_empty_double)
		{
			List<double> list2;
			list2.push_front(0.101);
			double data = 0.101;
			Assert::IsTrue(list2.get_front() == data);
		}

		TEST_METHOD(TestMethod_pop_front_double)
		{
			List<double> list2;

			list2.push_back(0.50);
			list2.push_back(0.140);
			list2.push_front(12.10);
			list2.pop_front();
			double data = 0.50;
			Assert::IsTrue(list2.get_front() == data);
		}

		TEST_METHOD(TestMethod_at_double)
		{
			List <double>list2;

			list2.push_back(0.050);
			list2.push_back(0.40);
			list2.push_front(10);
			double data = 0.050;
			Assert::IsTrue(list2.at(1) == data);
		}

		
	};
}