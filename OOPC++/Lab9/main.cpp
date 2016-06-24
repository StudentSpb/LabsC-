
// Контейнеры STL: 
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
	
	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
	//получения значений

	// РЕАЛИЗОВАН В templates.h

	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 

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

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
	
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "queue - очередь, которая содержит указатели на объекты типа Point" << std::endl << std::endl;

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
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "priority_queue, содержит адреса строковых литералов - const char*" << std::endl << std::endl;

	const char* str[] = { "apple", "lemon", "peach", "orange", "chery" };

	priority_queue<const char*, vector<const char*>, LESS> cpPQueue(&str[0], &str[5]);

	std::cout << "Priority_queue's  elements: " << std::endl;
	printInfoSPQ(cpPQueue);
	
	stop
	
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "set-множество с элементами типа Point" << std::endl << std::endl;

	set<Point> setPoint;

	setPoint.insert(Point(10, 10));
	setPoint.insert(Point(7, 7));
	setPoint.insert(Point(15, 15));
	setPoint.insert(Point(4, 4));

	printInfoVLD(setPoint);

	set<Point>::iterator it = setPoint.begin();

	//*it = Point(22, 22);
	//нельзя изменять значения элементов set

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
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "map \"фамилия, зарплата\" - pair<const char*, int>" << std::endl << std::endl;

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

	//д) Сформируйте любым способом вектор с элементами типа string.
	//Создайте (и распечатайте для проверки) map<string, int>, который будет
	//содержать упорядоченные по алфавиту строки и
	//количество повторений каждой строки в векторе
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "map<string, int>, который содержит количество повторений каждой строки в векторе" << std::endl << std::endl;
	
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
		
	//е) 
	//задан массив:
	//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
	//создайте map, в котором каждой букве будет соответствовать совокупность 
	//лексиграфически упорядоченных слов, начинающихся с этой буквы.
	//Подсказка: не стоит хранить дубли одной и той же строки
	
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
	//ж)
	//создайте структуру данных, которая будет хранить информацию о студенческих группах.
	//Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
	//фамилии могут дублироваться
	//Сами группы тоже должны быть упорядочены по номеру
	//
	//номера 
	// <int, multiset*.
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "студенческие группы" << std::endl << std::endl;
	
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
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "\"англо-русский\" словарь" << std::endl << std::endl;

	multimap<string, string> dict;
	
	dict.insert(pair<string, string>("table", "доска"));
	dict.insert(pair<string, string>("strange", "странный"));
	dict.insert(pair<string, string>("time", "время"));
	dict.insert(pair<string, string>("strange", "чужой"));
	dict.insert(pair<string, string>("time", "раз"));
	dict.insert(pair<string, string>("table", "стол"));
	dict.insert(pair<string, string>("time", "период"));

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

