//Исключения

//Шаблоны: 
	//		шаблоны функций,
	//		шаблоны классов,


#include <tchar.h>
#include "Template.h"
#include "myString.h"
#include "Mystack.h"
#include "MyStack2.h"
#include <stdexcept>
#include "MyQueue.h"


#define stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	


////////////////////////////////////////////////////////////////////////////
	//Тема. Шаблоны функций.
	//Создайте шаблон функции перестановки местами двух
	//значений - Swap(). Проверьте работоспособность созданного
	//шаблона с помощью приведенного ниже фрагмента кода.
	//Подсказка 1: объявление шаблона корректнее поместить в .h-файл.



	int iX = 1, iY = -1;
	Swap(iX, iY);
	std::cout << iX << " " << iY << std::endl;

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);
	std::cout << dX << " " << dY << std::endl;

	//Подсказка 2: подумайте, что нужно реализовать, для того,
	//			чтобы следующий вызов работал с объектами MyString
	//			не только корректно, но и эффективно
	
	MyString str1("One"), str2("Two");
	Swap(str1, str2);
	std::cout << str1 << " " << str2<< std::endl;
  	stop
	

		/////////////////////////////////////////////////////////////////////

			//Тема. Шаблоны классов.
			//Задание 1.
			//Создайте шаблон класса MyStack для хранения элементов любого типа T.
			//Подсказка: 1.элементы нужно где-то хранить - простым и удобным средством
			//			для хранения последовательно расположенных в памяти элементов
			//			является массив, 
			//			2.для задания максимального размера стека может быть использован
			//			параметр-константа шаблона
			//			3.обязательными операциями со стеком являются "push" и "pop". Для
			//			того, чтобы гарантировать корректное выполнение этих операций 
			//			хорошо было бы генерировать исключение в аварийной ситуации
			//			4. дополнительно реализуйте operator[] таким образом, чтобы пользователь
			//			мог читать/изменять значения только тех элементов, которые он формировал


			//С помощью шаблона MyStack создайте стек из 5 элементов int - iStack и
			//стек из 10 элементов MyString - strStack и поэкспериментируйте с функциями
			//push() и pop(), operator[]

		/*
	MyStack<int> iStack;
	MyStack<MyString> strStack;
	
	iStack.push(2);
	iStack.push(8);
	iStack.push(5);

	for (int i = 0; i <iStack.GetCount(); i ++)
	{
		std::cout << iStack[i] << "   ";
	}
	for (int i = 0; i <iStack.GetCount(); i++)
	{
		iStack[i] = i +10;
		std::cout << iStack[i] << "   ";
	}
	stop

		MyString strst("First");
	MyString strst1("Second");
	MyString strst2("Third");
	strStack.push(strst);
	strStack.push(strst1);
	strStack.push(strst2);
	*/


	//Задание 2. Реализуйте шаблон стека - MyStack2 таким образом, чтобы 
	//для хранения элементов использовался ОДНОСВЯЗНЫЙ список.
	//Реализуйте возможность распечатать элементы стека в том порядке, в котором их заносил (push())
	//пользователь

	MyStack2<int> stack;
	stack.push(3);
	stack.push(9);
	stack.push(1);
	stack.push(8);
	stack.push(15);
	stack.print();


	MyStack2<int> stack2;
	stack2.push(22);
	stack2.push(11);
	stack2 = stack;
	stack2.print();

	MyStack2<int> stack3;
	stack3.push(1);
	stack3.push(2);
	stack3.push(3);
	stack3.push(4);
	stack3.push(5);
	stack3.push(6);
	stack3.push(7);
	stack3.push(8);
	
	stack3 = stack;
	stack3.print();


	MyStack2<int> stack4(stack);
	stack4.print();

	stop




		//Задание 3. Реализуйте шаблон очереди - MyQueue таким образом, чтобы 
		//для хранения элементов использовался динамический массив.
		//При использовании массива следует учесть специфику очереди, то есть
		//когда заполнен "хвост", в "голове" скорее всего уже имеются свободные элементы
		//=> должен быть организован кольцевой буфер


		MyQueue<int> queue;
		queue.push(323);
		queue.push(213);
		queue.push(723);
		queue.push(5);

		queue.print();

		queue.pop();
		stop

	return 0;
}

