#include "Oct.h"
#include <iostream>

void Oct::Show()
{
	std::cout << "Oct = " << static_cast<int> (value2) << static_cast<int> (value1) << static_cast<int> (value0) << std::endl;
}

void Oct::ShowPos(int pos)
{
	if ((pos < 3) && (pos >= 0))
	{
		switch (pos)
		{
		case 0:
			std::cout << static_cast<int> (value0) << " ";
			break;
		case 1:
			std::cout << static_cast<int> (value1) << " ";
			break;
		case 2:
			std::cout << static_cast<int> (value2) << " ";
			break;
		}
	}
}

void Oct::Edit(int pos, int value)
{
	if ((pos < 3) && (pos >= 0))
	{
		if (value >= 0 && value < 8)
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
				if (value >= 0 && value < 4)
				value2 = value;
				break;
			}
		}
	}
}
