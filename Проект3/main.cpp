#include "List.cpp"
#include "conio.h"
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
		list.insert(256, 4);
		std::cout << " список: ";
		std::cout << list;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << e.what();
	}


	_getch();
}