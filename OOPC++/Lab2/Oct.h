#pragma once

class Oct
{

	unsigned char value0 : 3;
	unsigned char value1 : 3;
	unsigned char value2 : 2;
	
	void Show();
	void ShowPos(int position);
	void Edit(int position, int value);
	friend union MyByte;

private:

};


