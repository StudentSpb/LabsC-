#include "Hex.h"
#include <iostream>

void Hex::Show()
{
	std::cout<< "Hex = " << std::hex << static_cast<int> (value1) << static_cast<int>(value0) << std::dec <<std::endl;
}

void Hex::ShowPos(int pos)
{
	if ((pos < 2) && (pos >= 0))
	{
		switch (pos)
		{
		case 0:
			std::cout << std::hex << static_cast<int> (value0) << " " << std::dec;

			break;
		case 1:
			std::cout << std::hex << static_cast<int> (value1) << " " << std::dec;
			break;
		}
	}
}

void Hex::Edit(int pos, int value)
{
	if ((pos < 2) && (pos >= 0))
	{
		if (value>=0 && value<16)
		{
			switch (pos)
			{
			case 0:
				value0 = value;
				break;
			case 1:
				value1 = value;
				break;
			}
		}
	}
}