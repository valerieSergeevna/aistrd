#include "List.cpp"
#include "conio.h"
//#include <iostream>
#include <exception>

void main()
{
	setlocale(LC_ALL, "russian");
	try
	{
		List <int> list;
		list.push_back(4);
		list.push_back(1);
		list.push_back(5);
		list.push_back(7);
		list.push_front(2);
		list.push_front(8);

		//list.pop_back();
		//list.isEmpty();
		list.insert(256, 4);
		std::cout << "первый список: ";
		std::cout << list;
		//list.print_to_console(&list);

		/*List<int> list2;
		list2.push_back(40);
		list2.push_back(10);
		list2.push_back(50);
		list2.push_back(70);

		std::cout << "\nвторой список: ";
		list.print_to_console(&list2);

		std::cout << "\nконечный список: ";
		list.push_front_list(list2);

		list.print_to_console(&list);*/
	}
	catch (const std::out_of_range &e)
	{
		std::cout << e.what();
	}


	_getch();
}