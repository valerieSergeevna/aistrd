#include "RBTree.h"
#include <conio.h>
#include <iostream>
#include <string>

void main()
{
	RBTree<int> List;
	List.insert(2,1);  //     2
	List.insert(4,2);  //   1   4
	List.insert(3,3);  // 0    3  9
	List.insert(1,4);
	List.insert(9,4);
	List.insert(0,7);
	List.insert(2,8);
	List.get_value();
	//return;
}