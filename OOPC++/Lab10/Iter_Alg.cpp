// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <tchar.h>

#include <iterator>
#include <string>
#include "Point.h"
#include "Rect.h"
#include "templates.h"

using namespace std;	
#define	  stop __asm nop

class pred 
{
	int m_n;
	int m_m;
public:
	pred(int n, int m) { m_n = n; m_m = m; }
	bool operator()	(const Point& p) 
	{
		return (p.m_x > m_n && p.m_y < m_m);
	}
};

bool pred1(Rect& rL, Rect& rR) 
{
	bool b = rL.remoteness() < rR.remoteness();
	std::cout << std::endl;
	return b;
}

char func1(char c) 
{
	c += 32;
	return c;
}

std::string& functransf(std::string& str)
{
	transform(str.begin(), str.end(), str.begin(), func1);
	return str;
}

int _tmain(int argc, _TCHAR* argv[])
{
	
///////////////////////////////////////////////////////////////////

	//Задание 1. Итераторы

	//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
	//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
	//являются копиями элементов set, но упорядочены по убыванию

	set<Point> sPoint{ Point(15,15), Point(4,4), Point(3,3), Point(5,5), Point(1,1) };
	vector<Point> vPoint(sPoint.rbegin(), sPoint.rend());

	stop

	//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
	//vector и set из предыдущего задания на экран.

	ostream_iterator<Point> itPoint (cout, "\n");
	
	std::cout << "sPoint elements: " << std::endl;
	copy(sPoint.begin(), sPoint.end(), itPoint);
	std::cout << "--------------------------------" << std::endl;
	std::cout << "vPoint elements: " << std::endl;
	copy(vPoint.begin(), vPoint.end(), itPoint);
	stop

	//Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter()
	//front_inserter()
	//inserter()
	//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером.

	std::cout << "--------------------------------------------------------------------------" << std::endl;

	//back_inserter(sPoint) = Point(25, 25);
	back_inserter(vPoint) = Point(30, 30);

	//front_inserter(sPoint) = Point(55, 55);
	//front_inserter(vPoint) = Point(60, 60);

	inserter(sPoint, sPoint.begin()) = Point(2, 2);
	inserter(vPoint, vPoint.begin() + 2) = Point(99, 99);
	
	stop

///////////////////////////////////////////////////////////////////

	//Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон
	std::cout << "--------------------------------------------------------------------------" << std::endl;

	//for_each(sPoint.begin(), sPoint.end(), printContGlob);
	
	std::cout << "sPoint elements: " << std::endl;
	for_each(sPoint.begin(), sPoint.end(), printCont<Point>);
	std::cout << "vPoint elements: " << std::endl;
	for_each(vPoint.rbegin(), vPoint.rend(), printCont<Point>);

	stop

	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
	//как шаблон) и выведите результат с помощью предыдущего предиката
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	
	//for_each(sPoint.begin(), sPoint.end(), changeContElm<Point>);
	//std::cout << "sPoint elements after change: " << std::endl;
	//for_each(sPoint.begin(), sPoint.end(), printCont<Point>);

	for_each(vPoint.rbegin(), vPoint.rend(), changeContElm<Point>);
	std::cout << "vPoint elements after change: " << std::endl;
	for_each(vPoint.rbegin(), vPoint.rend(), printCont<Point>);

	stop

	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.

	vector<Point>::iterator it1 = find(vPoint.begin(), vPoint.end(), Point(3, 3));
	*it1 = Point(111, 111);
	stop

	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?
	// Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!

	sort(vPoint.begin(), vPoint.end());

	stop

	//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
	//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
	//[-n, +m].

	it1 = find_if(vPoint.begin(), vPoint.end(), pred(100, 115));
	
	stop

	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.

	vector<Rect> vRect;
		
	vRect.push_back(Rect(2, 2, 7, 7, Shape::YELLOW));
	vRect.push_back(Rect(3, 3, 5, 5, Shape::GREEN));
	vRect.push_back(Rect(15, 7, 12, 6, Shape::BLACK));
	vRect.push_back(Rect(1, 1, 2, 2, Shape::BLUE));

	sort(vRect.begin(), vRect.end(), pred1);
	
	stop

	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()

		std::string str1("AHGSFKHDFKJGHDFKJ");
		functransf(str1);
		stop

		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр

		list<std::string> lStr{ "APPLE", "LEMON", "PEACH", "ORANGE", "CHERY" };

		set<std::string> sStr;
	
		set<std::string>::iterator it3 = sStr.begin();
		transform(lStr.begin(), lStr.end(), inserter(sStr, it3), functransf);

		stop
	}
	{// map
		
		//Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе
			
		vector<std::string> vStr{ "apple", "lemon", "peach", "orange", "chery", "apple", "lemon", "peach", "orange", "chery",  "apple", "lemon", "peach" };
		map<string, int> mStrInt;
		
		size_t s = vStr.size();

		for (int i = 0; i < s; i++) 
		{
			mStrInt[vStr[i]]++;
		}

		printInfoMap(mStrInt);		
	}
	stop

	return 0;
}

