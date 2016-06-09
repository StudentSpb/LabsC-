#include <tchar.h>

#include <iostream>
#include <fstream>
#include "myString.h"
#define	  stop __asm nop


int _tmain(int argc, _TCHAR* argv[])
{

	MyString str1("123");
	MyString str2("123");
	MyString str3 = str2;

	MyString st1("456");
	MyString st2("789");
	{
		MyString st3("999");
	}

	str2.PrintToAlph();
	stop

		return 0;
}//endmain

