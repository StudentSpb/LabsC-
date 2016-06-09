#include "Bin.h"
#include <iostream>




void Bin::Show()
{
	std::cout << "Bin = " << value7 << value6 << value5 << value4 << value3 << value2 << value1 << value0 << std::endl;
} 

void Bin::ShowPos(int pos)
{
	if ((pos < 9) && (pos >= 0))
	{
		switch (pos)
		{
		case 0:
			std::cout << value0 << std::endl;
			break;
		case 1:
			std::cout << value1 << std::endl;
			break;
		case 2:
			std::cout << value2 << std::endl;
			break;
		case 3:
			std::cout << value3 << std::endl;
			break;
		case 4:
			std::cout << value4 << std::endl;
			break;
		case 5:
			std::cout << value5 << std::endl;
			break;
		case 6:
			std::cout << value6 << std::endl;
			break;
		case 7:
			std::cout << value7 << std::endl;
			break;
		}
	}
}

void Bin::Edit(int pos, int value)
{
	if((pos < 9) & (pos >= 0))
	{
		if ((value < 2) && (pos >= 0))
		{
			switch (pos)
			{
			case 0:
				value0 = value;
				break;
			case 1:
				value1 = value;
				break;
			case 2:
				value2 = value;
				break;
			case 3:
				value3 = value;
				break;
			case 4:
				value4 = value;
				break;
			case 5:
				value5 = value;
				break;
			case 6:
				value6 = value;
				break;
			case 7:
				value7 = value;
				break;
			}
		}
	}
}

