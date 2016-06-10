#include <tchar.h>

#include "Point.h"
#include "Circle.h"
#include "List.h"
#include <iostream>
#include <fstream>
#define	  stop __asm nop


int _tmain(int argc, _TCHAR* argv[])
{
	Circle cir(3,4, 3);
	Circle cir2;
	Circle cir3(2,7, 5);
	Circle cir4(3,8, 9);
	Circle cir5(3, 8, 9);

	List myList;
	myList.AddToHead(cir);
	myList.AddToTail(cir3);
	myList.AddToHead(cir2);
	myList.AddToTail(cir5);
	myList.AddToTail(cir4);

	std::cout << myList;
	myList.SortSqre();
	std::cout << myList;
	int cnt = myList.RevomeAllFound(cir5);
	std::ofstream fout;
	fout.open("MyList.txt");
	fout << myList;
	fout.close();

	List mpList2;
	Circle ci(3, 4, 77);
	Circle ci2;
	Circle ci3(2, 7, 88);
	Circle ci4(3, 8, 99);
	Circle ci5(3, 8, 99);
	mpList2.AddToHead(ci);
	mpList2.AddToTail(ci3);
	mpList2.AddToHead(ci2);
	mpList2.AddToTail(ci5);
	mpList2.AddToTail(ci4);
	myList = mpList2;
	std::cout << myList;

	List newList;
	std::ifstream fcin;
	fcin.open("MyList.txt");
	fcin >> newList;
	fout.close();
	std::cout << newList;
	stop

		return 0;
}//endmain

