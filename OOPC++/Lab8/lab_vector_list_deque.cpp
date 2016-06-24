//Стандартная библиотека шаблонов - STL 
	//Контейнеры стандартной библиотеки - vector
	//Итераторы

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "myString.h"
#include "Point.h"
#include "Templates.h"

#pragma warning(disable: 4786)


using namespace std;	

#define	  stop __asm nop



int main()
{	
	// Контейнер стандартной библиотеки vector 

//////////////////////////////////////////////////////////////////////
	//Создание векторов. 

	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой. 

	vector<int> vInt;
	
	size_t s = vInt.size();
	
	//Раскомментируйте следующий фрагмент, подумайте - все ли корректно
	//Если есть некорректности, - исправьте
	
	vInt.resize(5);
	cout << vInt.front() << endl;
	vInt.front() = 1;
	cout << vInt.front() << endl;


	//С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
	//На каждой итерации цикла следите за размером вектора с помощью методов
	//size(), capacity(), max_size() и выводите значения элементов. 
	//
	//Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
	//напишите шаблон функции, которая для вектора, содержащего элементы любого типа
	//выводит его "реквизиты" и значения элементов на консоль.
	cout << "*****" << endl;
	s = vInt.size();
	for (int i = 0; i < 10; i++) 
	{
		vInt.push_back(1);
		printVector(vInt);
	}
	stop
		
	//вектор вещественных - vDouble1 с заданным Вами начальным размером  и
	//проверьте результат с помощью созданного Вами шаблона. Как будут
	//проинициализированы элементы вектора?

	vector<double> vDouble1(12);
	printVector(vDouble1);
	stop

	//вектор объектов типа MyString с начальным размером - 5 элементов
	//и инициализацией каждого элемента строкой "A"
	//C помощью функции at() а также с помощью оператора
	//индексирования []  измените значения каких-либо элементов.
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. 

	vector<MyString> vMStr(5, MyString("A"));
	printVector(vMStr);

	vMStr.at(4) = MyString("ABC");
	vMStr[3] = MyString("TIME");
	try 
	{
		vMStr.at(5) = MyString("CCC");
	} catch (exception e) 
	{
		cout << e.what() << endl;
	}
	stop

	//вектор вещественных - vDouble3, который является копией элементов
	// [0,5) массива вещественных чисел dMas. Предворительно массив dMas 
	//нужно создать и проинициализировать!

	double dMas[] = { 1.1, 2.2, 3.3, 4.4, 5.5,  6.6 };
	stop
	vector<double> vDouble3 (dMas[0], dMas[5]);
	//copy(vDouble3.begin(), vDouble3.end(), dMas);
	for (int i = 0; i < sizeof(dMas)/sizeof(double);i++) 
	{
		vDouble3.push_back(dMas[i]);
	}
	stop
	
	//вектор вещественных - vDouble4, который является копией элементов
	// [2,5) вектора vDouble3. 
	
	vector<double> vDouble4 (vDouble3.begin() + 2, vDouble3.end());
	for (int i = 2; i < sizeof(dMas) / sizeof(double);i++) 
	{
		vDouble4.push_back(vDouble3[i]);
	}
	stop

	//вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
	//будет вызван для каждого элемента?
	//b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).

	vector<Point> vPoint1(3);

	vector<Point> vPoint2(5, Point(1, 1));
	stop

	//вектор указателей на Point - vpPoint с начальным размером 5
	//Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
	{
		vector<Point*> vpPoint (5);
		for (int i = 0; i < vpPoint.size(); i++) 
		{
			vpPoint[i] = new Point(i + 2, i + 2);
		}
				//Подсказка: для вывода на печать значений скорее всего Вам понадобится
			//а) специализация Вашей шаблонной функции
			//б) или перегрузка operator<< для Point*
		printVector(vpPoint);
		for (int i = 0; i < vpPoint.size(); i++) 
		{
			delete vpPoint[i];
		}
	}//Какие дополнительные действия нужно предпринять для такого вектора?
	

	///////////////////////////////////////////////////////////////////////
	//Резервирование памяти.
	//Подумайте, всегда ли верны приведенные ниже проверки?
	
		{
			size_t n = 7;
			vector<int> v(n);
			v.resize(n/2);
			if (v.capacity() == n) std::cout << "True\n"; //true? да
		}
				
		{
			int n = 7;
			size_t m = 9;
			vector<int> v(n);
			v.reserve(m);
			if(v.capacity() == m) std::cout << "True\n"; //true? да
		}
				
		{
			vector<int> v(3,5);
			v.resize(4,10); //значения? размер увеличился до 4 и 4-му присвоено 10.
			v.resize(5); //значения? размер увеличился до 5 и 5-му присвоено 0 
			stop
		}
		

	//Создайте два "пустых" вектора с элементами
	//любого типа. 
	//В первом векторе зарезервируйте память под 5 элементов, а потом заполните
	//его значениями с помощью push_back.
	//Второй вектор просто заполните значениями посредством push_back.
	//
	//Сравните размер, емкость векторов и значения элементов

	{
		vector<int> vect;		
		vector<double> vDouble;

		vect.reserve(5);
		vect.push_back(11);
		vect.push_back(22);
		vect.push_back(33);
		vect.push_back(44);
		vect.push_back(55);
		printVector(vect);// vect: capacity - 5, size - 5

		vect.push_back(66);
		printVector(vect);// vect: capacity - 7, size - 6

		vDouble.push_back(555);
		vDouble.push_back(777);
		vDouble.push_back(777);
		vDouble.push_back(777);
		vDouble.push_back(777);
		printVector(vDouble);		// vDouble: capacity - 6, size - 5


		stop
	}
		
	//Создание "двухмерного вектора" - вектора векторов
	//Задан одномерный массив int ar[] = {11,2,4,3,5};
	//Создайте вектор векторов следующим образом:
	//вектор vv[0] - содержит 11 элементов со значением 11
	//vv[1] - содержит 2,2
	//vv[2] - содержит 4,4,4,4
	//...
	//Распечатайте содержимое такого двухмерного вектора по строкам
	{
		int ar[] = { 11,2,4,3,5 };

		vector<vector<int>> vv;

		for (int i = 0; i < sizeof(ar) / sizeof(int); i++) 
		{
			vv.emplace_back(ar[i], ar[i]);
		}
		cout << "Print vector of vectors:" << endl;
		for (int i = 0; i < vv.size(); i++) 
		{
			printVector(vv[i]);
		}
		stop
	}
	 stop
	

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//Вставка элемента последовательности insert().
	//В вектор vChar2 вставьте в начало вектора символ только при
	//условии, что в векторе такого еще нет.
	{
		vector<char> vChar2;
		char c = 't';
		int count = 0;
		vector<char>::iterator first = vChar2.begin();
		for (int i = 0; i < vChar2.size(); i++) 
		{
			if (vChar2[i] == c)
			{
				count++;
			}
		}
		if (!count)
		{
			vChar2.insert(first, c);
		}

		char c1 = 'm';
		count = 0;
		first = vChar2.begin();
		for (int i = 0; i < vChar2.size(); i++) 
		{
			if (vChar2[i] == c1)
			{
				count++;
			}
		}
		if (!count)
		{
			vChar2.insert(first, c1);
		}

		char c2 = 't';
		count = 0;
		first = vChar2.begin();
		for (int i = 0; i < vChar2.size(); i++) 
		{
			if (vChar2[i] == c2)
			{
				count++;
			}
		}
		if (!count)
		{
			vChar2.insert(first, c2);
		}

		//Вставьте перед каждым элементом вектора vChar2 букву 'W'
		first = vChar2.begin();
		size_t n = vChar2.size();
		for (int i = 0; i < n; i++) 
		{
			//++it;
			first = vChar2.insert(first, 'W');
			++first;
			++first;
		}
		stop
	}
	//Сотрите только повторяющиеся последовательности символов.
	//Например: было - "qwerrrrty", стало - "qwety"
	{
		vector<char> vChar3 = { 'q','q', 'q','w','e','r','r','r','r','t', 'y', 'y', 'y' };
		vector<char>::iterator it = vChar3.begin();
		char tmp;
		for (int i = 0; i < vChar3.size() - 1; i++) 
		{
			if (vChar3[i] == vChar3[i + 1]) 
			{
				tmp = *it;
				it = vChar3.erase(it);
				--i;
				if (it + 1 == vChar3.end()) 
				{
					it = vChar3.erase(it);
				}
			}
			else if (vChar3[i] == tmp) 
			{
				it = vChar3.erase(it);
				--i;
			}
			else
			{
				++it;
			}
		}
		stop

	///////////////////////////////////////////////////////////////////

	//Удаление элемента последовательности erase()
	//Напишите функцию удаления из любого вектора всех дублей 

		vector<char> vChar4 = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!' };

		char tmp1;

		it = vChar4.begin();
		vector<char>::iterator it1 = vChar4.begin();
		while (it != vChar4.end()) 
		{
			tmp1 = *it;
			it1 = it + 1;
			while (it1 != vChar4.end()) 
			{
				if (*it1 == tmp1) 
				{
					it1 = vChar4.erase(it1);
				}
				else
				{
					++it1;
				}
			}
			++it;
		}
		stop

			//Уберите лишние пробелы в vector<char>

			vector<char> vChar5 = { 'H', ' ', 'e', ' ', 'l', ' ', 'l', ' ', 'o', ' ', '!' };

		it = vChar5.begin();

		while (it != vChar5.end()) 
		{
			if (*it == ' ') 
			{
				it = vChar5.erase(it);
			}
			else
			{
				++it;
			}
		}

		///////////////////////////////////////////////////////////////////
			//Создайте новый вектор таким образом, чтобы его элементы стали
			//копиями элементов любого из созданных ранее векторов, но расположены
			//были бы в обратном порядке

		vector<char> vChar6(vChar5.rbegin(), vChar5.rend());
		stop
	}
///////////////////////////////////////////////////////////////////

	//Задание 1. Списки. Операции, характерные для списков.
	//Создайте пустой список из элементов Point - ptList1 и наполните
	//его значениями с помощью методов push_back(),
	//push_front, insert()
	list<Point> ptList1;
	list<Point>::iterator itlist = ptList1.begin();
	ptList1.push_back(Point(1, 1));
	ptList1.push_front(Point(2, 2));
	ptList1.push_back(Point(3, 3));
	ptList1.push_front(Point(4, 4));
	ptList1.insert(itlist, Point(5,5));

	//Напишите шаблон функции, которая будет выводить элементы
	//ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
	//vector и list. Подсказка - хотелось бы увидеть тип контейнера.

	printInfo(ptList1);
	printInfo(vPoint2);


	//Сделайте любой из списков "реверсивным" - reverse()

	ptList1.reverse();
	stop

	//Создайте список ptList2 из элементов Point таким образом, чтобы он стал 
	//копией вектора элементов типа Point, но значения элементов списка располагались
	//бы в обратном порядке (используйте при конструировании реверсивные итераторы)

	list<Point> ptList2(ptList1.rbegin(), ptList1.rend());
	stop

	//Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
	//по возрастанию.
	//Подумайте: что должно быть перегружено в классе Point для того, чтобы
	//работала сортировка

	ptList1.sort();
	ptList2.sort();
	stop

	//Объедините отсортированные списки - merge(). Посмотрите: что
	//при этом происходит с каждым списком.

	ptList1.merge(ptList2);	// элементы из "правого" списка переносятся в "левый" и сортируются
	stop

	//Исключение элемента из списка - remove()
	//Исключите из списка элемент с определенным значением.
	//Подумайте: что должно быть перегружено в классе Point?

	ptList1.remove(Point (2,2));
	stop

		//Исключение элемента из списка, удовлетворяющего заданному условию:
		//любая из координат отрицательна - remove_if(). 

		ptList1.push_back(Point(-3, 7));
		ptList1.push_front(Point(4, -5));
		ptList1.remove_if(neg);
		stop

		//Исключение из списка подряд расположенных дублей - unique(). 

		ptList1.unique();
	stop

///////////////////////////////////////////////////////////////////
	//Задание 2.Очередь с двумя концами - контейнер deque

	//Создайте пустой deque с элементами типа Point. С помощью
	//assign заполните deque копиями элементов вектора. С помощью
	//разработанного Вами в предыдущем задании универсального шаблона
	//выведите значения элементов на печать

		deque<Point> ptDeque;

		ptDeque.assign(vPoint2.begin(), vPoint2.end());


	//Создайте deque с элементами типа MyString. Заполните его значениями
	//с помощью push_back(), push_front(), insert()
	//С помощью erase удалите из deque все элементы, в которых строчки
	//начинаются с 'A' или 'a'

		deque<MyString> mstrDeque;
	
		mstrDeque.push_back(MyString("a_has"));
		mstrDeque.push_front(MyString("Time"));
		mstrDeque.push_back(MyString("come"));
		mstrDeque.push_front(MyString("A_Hello"));
	
		deque<MyString>::iterator itDeque = mstrDeque.begin() + 1;
		mstrDeque.insert(itDeque, MyString("world"));

		printInfo(mstrDeque);

		itDeque = mstrDeque.begin();
		while (itDeque != mstrDeque.end()) 
		{
			/*
			if (*itDeque == 'a' || *itDeque == 'A') 
			{
				itDeque = mstrDeque.erase(itDeque);
			}
			else { ++itDeque; }
		*/
		}

	return 0;
}