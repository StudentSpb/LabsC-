#pragma once
class MyString
{
private:
    char* m_pStr;	//строка-член класса
public:
	const char* GetString() const;
	void SetString(char*);

	MyString(char* string);
	MyString(const MyString&);
	MyString(MyString &&);
	~MyString();
};

MyString GetMyString(const char*, ...);
