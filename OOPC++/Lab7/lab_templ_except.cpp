//����������

//�������: 
	//		������� �������,
	//		������� �������,


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
	//����. ������� �������.
	//�������� ������ ������� ������������ ������� ����
	//�������� - Swap(). ��������� ����������������� ����������
	//������� � ������� ������������ ���� ��������� ����.
	//��������� 1: ���������� ������� ���������� ��������� � .h-����.



	int iX = 1, iY = -1;
	Swap(iX, iY);
	std::cout << iX << " " << iY << std::endl;

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);
	std::cout << dX << " " << dY << std::endl;

	//��������� 2: ���������, ��� ����� �����������, ��� ����,
	//			����� ��������� ����� ������� � ��������� MyString
	//			�� ������ ���������, �� � ����������
	
	MyString str1("One"), str2("Two");
	Swap(str1, str2);
	std::cout << str1 << " " << str2<< std::endl;
  	stop
	

		/////////////////////////////////////////////////////////////////////

			//����. ������� �������.
			//������� 1.
			//�������� ������ ������ MyStack ��� �������� ��������� ������ ���� T.
			//���������: 1.�������� ����� ���-�� ������� - ������� � ������� ���������
			//			��� �������� ��������������� ������������� � ������ ���������
			//			�������� ������, 
			//			2.��� ������� ������������� ������� ����� ����� ���� �����������
			//			��������-��������� �������
			//			3.������������� ���������� �� ������ �������� "push" � "pop". ���
			//			����, ����� ������������� ���������� ���������� ���� �������� 
			//			������ ���� �� ������������ ���������� � ��������� ��������
			//			4. ������������� ���������� operator[] ����� �������, ����� ������������
			//			��� ������/�������� �������� ������ ��� ���������, ������� �� ����������


			//� ������� ������� MyStack �������� ���� �� 5 ��������� int - iStack �
			//���� �� 10 ��������� MyString - strStack � ������������������� � ���������
			//push() � pop(), operator[]

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


	//������� 2. ���������� ������ ����� - MyStack2 ����� �������, ����� 
	//��� �������� ��������� ������������� ����������� ������.
	//���������� ����������� ����������� �������� ����� � ��� �������, � ������� �� ������� (push())
	//������������

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




		//������� 3. ���������� ������ ������� - MyQueue ����� �������, ����� 
		//��� �������� ��������� ������������� ������������ ������.
		//��� ������������� ������� ������� ������ ��������� �������, �� ����
		//����� �������� "�����", � "������" ������ ����� ��� ������� ��������� ��������
		//=> ������ ���� ����������� ��������� �����


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

