#include <tchar.h>

#include "Circle.h"
#include "Rect.h"
#include "List.h"
#include <iostream>
#include <fstream>
#define	  stop __asm nop


int _tmain(int argc, _TCHAR* argv[])
{
	Circle cir(3, 4, 3, Blue);
	Circle cir2;
	Circle cir3(2, 7, 5, Green);
	Circle cir4(3, 8, 9);
	Circle cir5(3, 5, 6, White);

	Rect rect(1, 2, 3, 4, Blue);
	Rect rect2(3, 2, 2, 1, Blue);
	Rect rect3(6, 2, 5, 1, Red);
	Rect rect4(7, 6, 3, 4, Green);

	List myList;
	myList.AddToHead(cir);
	myList.AddToHead(rect);
	myList.AddToTail(cir2);
	myList.AddToHead(rect2);
	myList.AddToTail(rect3);
	myList.AddToTail(cir3);
	myList.AddToHead(rect4);
	myList.AddToHead(cir4);
	myList.AddToHead(cir5);

	std::cout << myList;
	std::cout << std::endl;
	myList.SortSqre();
	std:: cout<< myList;
	stop

		return 0;
}//endmain

