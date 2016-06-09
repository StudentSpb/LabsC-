#pragma once
class Hex
{
	unsigned char value0 : 4;
	unsigned char value1 : 4;

	void Show();
	void ShowPos(int position);
	void Edit(int position, int value);
	friend union MyByte;

private:

};

