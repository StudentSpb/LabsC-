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
	Circle cir2(1,2);
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

	std::cout << myList << std::endl;
	myList.SortSqre(mSquare);
	std:: cout<< myList << std::endl;

	myList.Remove(cir4);
	std::cout << myList << std::endl;

	List myList2;
	myList2.AddToTail(rect3);
	myList2.AddToTail(cir3);
	myList2.AddToHead(rect4);
	myList = myList2;

	std::cout << myList2 << std::endl;
	
	std::ofstream fout;
	fout.open("MyList.txt");
	fout << myList2;
	fout.close();

	List newList;
	std::ifstream fcin;
	fcin.open("MyList.txt");
	fcin >> newList;
	fout.close();
	std::cout << newList << std::endl;
	stop

		return 0;
}//endmain

