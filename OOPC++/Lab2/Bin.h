#pragma once

class Bin
{
	bool value0 : 1;
	bool value1 : 1;
	bool value2 : 1;
	bool value3 : 1;
	bool value4 : 1;
	bool value5 : 1;
	bool value6 : 1;
	bool value7 : 1;

	void Show();
	void ShowPos(int position);
	void Edit(int position, int value);
	friend union MyByte;
};


