
// ���������� STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

//#include "stdafx.h"
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include <tchar.h>

#include <iostream>

#include "templates.h"
#include "Point.h"

#include <functional>
#include <locale>

using namespace std;

#define stop __asm nop

struct LESS 
{
	bool operator() (const char* l, const char* r)
	{
		if (strcmp(l, r) < 0) 
		{
			return false;
		}
		return true;
	}
};

struct GREAT {
	bool operator() (const char* l, const char* r) 
	{
		if (strcmp(l, r) < 0) 
		{
			return true;
		}
		return false;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	
	//�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
	//�������� �������� �� ��, ��� ���������� ������������� ������ ������ ��� 
	//��������� ��������

	// ���������� � templates.h

	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//�������� ���� ����� �������, �����
	//�) �������� ����� ����� ������� ��������� �������
	//�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ���������� 

	vector<int> vInt(5, 15);

	vInt.push_back(22);
	vInt.push_back(33);
	vInt.push_back(44);
	vInt.push_back(55);
	vInt.push_back(66);

	stack<int, vector<int>> stInt(vInt);

	std::cout << "Stack's  elements: ";
	printInfoSPQ(stInt);
	std::cout << "Vector's elements: ";
	printInfoVLDreverse(vInt);

	stop
		
	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//�������� �������, ������� �������� ��������� �� ������� ���� Point,
	//��� ���� ���� ������� ������� ���������.
	//�������� �������� ������� � ���������� ��������� ����������� front() � back()
	//���������, ��� ��������� ������� ��� ����������� ����� �������?
	
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "queue - �������, ������� �������� ��������� �� ������� ���� Point" << std::endl << std::endl;

	queue<Point*, deque<Point*>> qpPoint;

	qpPoint.push(new Point(3, 3));
	qpPoint.push(new Point(4, 4));
	qpPoint.push(new Point(1, 1));
	
	Point* pp = qpPoint.front();

	delete qpPoint.front();
	qpPoint.front() = new Point(5, 5);
	delete qpPoint.back();
	qpPoint.back() = new Point(7, 7);

	std::cout << "Queue's  elements: " << std::endl;
	printInfoQ(qpPoint);

	while (!qpPoint.empty()) {
		delete qpPoint.front();
		qpPoint.pop();
	}

	stop

	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*
	//�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
	//�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
	//		��� ������������ ��� �������?
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "priority_queue, �������� ������ ��������� ��������� - const char*" << std::endl << std::endl;

	const char* str[] = { "apple", "lemon", "peach", "orange", "chery" };

	priority_queue<const char*, vector<const char*>, LESS> cpPQueue(&str[0], &str[5]);

	std::cout << "Priority_queue's  elements: " << std::endl;
	printInfoSPQ(cpPQueue);
	
	stop
	
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ����������
	//		� ������ Point (� ����� �������)
	//�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������
	//�) ���������� �������� ����� ��������...
	//�) �������� ��� ���������, ������� ����� ��������� ���������� ��������
	//		���� int, �� ���������� � ������ �������
	//�) �������� � ����� ��������� �������� ��������� �� ������ �������
	//	����������, ��������, ��������� �������	(��� ����������, ���� � ������� ������� �����?)
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "set-��������� � ���������� ���� Point" << std::endl << std::endl;

	set<Point> setPoint;

	setPoint.insert(Point(10, 10));
	setPoint.insert(Point(7, 7));
	setPoint.insert(Point(15, 15));
	setPoint.insert(Point(4, 4));

	printInfoVLD(setPoint);

	set<Point>::iterator it = setPoint.begin();

	//*it = Point(22, 22);
	//������ �������� �������� ��������� set

	vector<int> vInt2 { 1,2,3,4,5,6 };

	set<int> setInt1(vInt2.begin(), vInt2.end());
	set<int, std::greater<int>> setInt2(vInt2.rbegin(), vInt2.rend());
	std::cout << "setInt1  elements: " << std::endl;
	printInfoVLD(setInt1);
	std::cout << "setInt2  elements: " << std::endl;
	printInfoVLD(setInt2);

	int ar[8] = { 1,2,3,4,1,2,3,4 };
	
	set<int> setInt3(ar, ar+8);
	std::cout << "setInt3  elements: " << std::endl;
	printInfoVLD(setInt3);

	stop

	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,
	//	��� ���� ������ �������� ���������� ����������
	//�) ��������� ��������� ���������� ����������� operator[] � insert()
	//�) ������������ ����������

	//�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "map \"�������, ��������\" - pair<const char*, int>" << std::endl << std::endl;

	map <const char*, int> mapSal;


	mapSal.insert(pair<const char*, int>("Ivanov", 15000));
	mapSal.insert(pair<const char*, int>("Petrov", 15000));
	mapSal.insert(pair<const char*, int>("Sidorov", 15000));
	mapSal["Ivanov"] = 25000;

	std::cout << "mapSal  elements: " << std::endl;
	printInfoMap(mapSal);

	map<const char*, int>::iterator itmap = mapSal.find("Petrov");
	if (itmap != mapSal.end()) 
	{
		int tmp = itmap->second;
		mapSal.erase(itmap);
		mapSal["Abramov"] = tmp;
	}

	std::cout << "mapSal  elements: " << std::endl;
	printInfoMap(mapSal);

	stop

	//�) ����������� ����� �������� ������ � ���������� ���� string.
	//�������� (� ������������ ��� ��������) map<string, int>, ������� �����
	//��������� ������������� �� �������� ������ �
	//���������� ���������� ������ ������ � �������
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "map<string, int>, ������� �������� ���������� ���������� ������ ������ � �������" << std::endl << std::endl;
	
	vector<std::string> vStr{ "apple", "lemon", "peach", "orange", "chery", "apple", "lemon", "peach", "orange", "chery",  "apple", "lemon", "peach" };

	map<string, int> mapStr;

	size_t s = vStr.size();

	for (int i = 0; i < s; i++) 
	{
		/*map<string, int>::iterator itm = mapStr.find(vStr[i]);
		if (itm == mapStr.end()) {*/
			mapStr[vStr[i]]++;
		/*}
		else {
			itm->second++;
		}*/
	}

	std::cout << "mapStr  elements: " << std::endl;
	printInfoMap(mapStr);

	stop
		
	//�) 
	//����� ������:
	//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
	//�������� map, � ������� ������ ����� ����� ��������������� ������������ 
	//��������������� ������������� ����, ������������ � ���� �����.
	//���������: �� ����� ������� ����� ����� � ��� �� ������
	
	//'A' -  "Abba" "Alfa"
	//'B' -  "Beauty" "Beta"  ...
	//...
	
	// <char, set*>
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "words" << std::endl << std::endl;
	
	const char* words[] = { "Bob", "Abba", "Alfa", "Beta", "Beauty", "Abc", "Circle", "Cat", "Cream" };
	
	map<char, set<const char*, GREAT>> mapWords;
	map<char, set<const char*>>::iterator itmW;
	
	s = sizeof(words) / sizeof(char*);

	for (int i = 0; i < s; i++) 
	{
		mapWords[words[i][0]].insert(words[i]);
	}

	printInfoMap1(mapWords);

	stop
	//�)
	//�������� ��������� ������, ������� ����� ������� ���������� � ������������ �������.
	//��� ������ ������ ������ �������� ������� ��������� (�� ��������). ��� ���� 
	//������� ����� �������������
	//���� ������ ���� ������ ���� ����������� �� ������
	//
	//������ 
	// <int, multiset*.
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "������������ ������" << std::endl << std::endl;
	
	map<int, multiset<const char*, GREAT>> mapStuds;

	mapStuds[101].insert("Ivanov");
	mapStuds[102].insert("Ivanov");
	mapStuds[103].insert("Ivanov");
	mapStuds[101].insert("Petrov");
	mapStuds[102].insert("Semenov");
	mapStuds[103].insert("Ivanov");
	mapStuds[101].insert("Abramov");
	mapStuds[102].insert("Borisov");
	mapStuds[103].insert("Zuev");

	printInfoMap1(mapStuds);

	stop
	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//�) �������� "�����-�������" �������, ��� ������ � ���� �� ����� ����� ���������������
	//		��������� ������� �������� - pair<string,string>, ��������: strange: �����, ��������...
	//�) ��������� ������� ������ � ������� ������ insert ��� ������������������ � ������� 
	//		���������������� ������� ���� (���� ����� �������������� ��� ��������� � ������� ������� make_pair)
	//�) �������� ��� ���������� ������� �� �����
	//�) �������� �� ����� ������ �������� "���������" ��� ��������� �����. ���������: ��� ���������� ���������
	//		���������� ����� ������������ ������ lower_bound() � upper_bound()
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "\"�����-�������\" �������" << std::endl << std::endl;

	multimap<string, string> dict;
	
	dict.insert(pair<string, string>("table", "�����"));
	dict.insert(pair<string, string>("strange", "��������"));
	dict.insert(pair<string, string>("time", "�����"));
	dict.insert(pair<string, string>("strange", "�����"));
	dict.insert(pair<string, string>("time", "���"));
	dict.insert(pair<string, string>("table", "����"));
	dict.insert(pair<string, string>("time", "������"));

	printInfoMap(dict);
	
	auto ldict = dict.lower_bound("strange");
	auto udict = dict.upper_bound("strange");
	
	printInfoMMap(ldict, udict);

	ldict = dict.lower_bound("time");
	udict = dict.upper_bound("time");

	printInfoMMap(ldict, udict);

	stop

	return 0;
}

