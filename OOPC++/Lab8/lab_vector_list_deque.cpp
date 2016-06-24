//����������� ���������� �������� - STL 
	//���������� ����������� ���������� - vector
	//���������

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
	// ��������� ����������� ���������� vector 

//////////////////////////////////////////////////////////////////////
	//�������� ��������. 

	//�������� ��������� �������:
	//---------------------------
	//������ ������ ����� ����� - vInt � ��������� � ������� ������� size(),
	//��� ��� ������ �������. 

	vector<int> vInt;
	
	size_t s = vInt.size();
	
	//���������������� ��������� ��������, ��������� - ��� �� ���������
	//���� ���� ��������������, - ���������
	
	vInt.resize(5);
	cout << vInt.front() << endl;
	vInt.front() = 1;
	cout << vInt.front() << endl;


	//� ������� ������� push_back() � ����� ��������� ������ ������-���� ����������.
	//�� ������ �������� ����� ������� �� �������� ������� � ������� �������
	//size(), capacity(), max_size() � �������� �������� ���������. 
	//
	//���������: ��� ��� ����� �������� ����������� ��� � � ��������� ��������,
	//�������� ������ �������, ������� ��� �������, ����������� �������� ������ ����
	//������� ��� "���������" � �������� ��������� �� �������.
	cout << "*****" << endl;
	s = vInt.size();
	for (int i = 0; i < 10; i++) 
	{
		vInt.push_back(1);
		printVector(vInt);
	}
	stop
		
	//������ ������������ - vDouble1 � �������� ���� ��������� ��������  �
	//��������� ��������� � ������� ���������� ���� �������. ��� �����
	//������������������� �������� �������?

	vector<double> vDouble1(12);
	printVector(vDouble1);
	stop

	//������ �������� ���� MyString � ��������� �������� - 5 ���������
	//� �������������� ������� �������� ������� "A"
	//C ������� ������� at() � ����� � ������� ���������
	//�������������� []  �������� �������� �����-���� ���������.
	//���������� "�����" �� ������� ������� � ������� at() �
	//� ������� []. 

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

	//������ ������������ - vDouble3, ������� �������� ������ ���������
	// [0,5) ������� ������������ ����� dMas. �������������� ������ dMas 
	//����� ������� � �������������������!

	double dMas[] = { 1.1, 2.2, 3.3, 4.4, 5.5,  6.6 };
	stop
	vector<double> vDouble3 (dMas[0], dMas[5]);
	//copy(vDouble3.begin(), vDouble3.end(), dMas);
	for (int i = 0; i < sizeof(dMas)/sizeof(double);i++) 
	{
		vDouble3.push_back(dMas[i]);
	}
	stop
	
	//������ ������������ - vDouble4, ������� �������� ������ ���������
	// [2,5) ������� vDouble3. 
	
	vector<double> vDouble4 (vDouble3.begin() + 2, vDouble3.end());
	for (int i = 2; i < sizeof(dMas) / sizeof(double);i++) 
	{
		vDouble4.push_back(vDouble3[i]);
	}
	stop

	//������ ��������� ���� Point - vPoint1 �) � ��������� �������� 3. ����� �����������
	//����� ������ ��� ������� ��������?
	//b) vPoint2 � ��������� �������� 5 � ������������������ ������ ������� ������������ (1,1).

	vector<Point> vPoint1(3);

	vector<Point> vPoint2(5, Point(1, 1));
	stop

	//������ ���������� �� Point - vpPoint � ��������� �������� 5
	//���������: ��� ��������� ��������� ��� ��������� "���������" �� ������� Point
	{
		vector<Point*> vpPoint (5);
		for (int i = 0; i < vpPoint.size(); i++) 
		{
			vpPoint[i] = new Point(i + 2, i + 2);
		}
				//���������: ��� ������ �� ������ �������� ������ ����� ��� �����������
			//�) ������������� ����� ��������� �������
			//�) ��� ���������� operator<< ��� Point*
		printVector(vpPoint);
		for (int i = 0; i < vpPoint.size(); i++) 
		{
			delete vpPoint[i];
		}
	}//����� �������������� �������� ����� ����������� ��� ������ �������?
	

	///////////////////////////////////////////////////////////////////////
	//�������������� ������.
	//���������, ������ �� ����� ����������� ���� ��������?
	
		{
			size_t n = 7;
			vector<int> v(n);
			v.resize(n/2);
			if (v.capacity() == n) std::cout << "True\n"; //true? ��
		}
				
		{
			int n = 7;
			size_t m = 9;
			vector<int> v(n);
			v.reserve(m);
			if(v.capacity() == m) std::cout << "True\n"; //true? ��
		}
				
		{
			vector<int> v(3,5);
			v.resize(4,10); //��������? ������ ���������� �� 4 � 4-�� ��������� 10.
			v.resize(5); //��������? ������ ���������� �� 5 � 5-�� ��������� 0 
			stop
		}
		

	//�������� ��� "������" ������� � ����������
	//������ ����. 
	//� ������ ������� �������������� ������ ��� 5 ���������, � ����� ���������
	//��� ���������� � ������� push_back.
	//������ ������ ������ ��������� ���������� ����������� push_back.
	//
	//�������� ������, ������� �������� � �������� ���������

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
		
	//�������� "����������� �������" - ������� ��������
	//����� ���������� ������ int ar[] = {11,2,4,3,5};
	//�������� ������ �������� ��������� �������:
	//������ vv[0] - �������� 11 ��������� �� ��������� 11
	//vv[1] - �������� 2,2
	//vv[2] - �������� 4,4,4,4
	//...
	//������������ ���������� ������ ����������� ������� �� �������
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
	
	//������� �������� ������������������ insert().
	//� ������ vChar2 �������� � ������ ������� ������ ������ ���
	//�������, ��� � ������� ������ ��� ���.
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

		//�������� ����� ������ ��������� ������� vChar2 ����� 'W'
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
	//������� ������ ������������� ������������������ ��������.
	//��������: ���� - "qwerrrrty", ����� - "qwety"
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

	//�������� �������� ������������������ erase()
	//�������� ������� �������� �� ������ ������� ���� ������ 

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

			//������� ������ ������� � vector<char>

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
			//�������� ����� ������ ����� �������, ����� ��� �������� �����
			//������� ��������� ������ �� ��������� ����� ��������, �� �����������
			//���� �� � �������� �������

		vector<char> vChar6(vChar5.rbegin(), vChar5.rend());
		stop
	}
///////////////////////////////////////////////////////////////////

	//������� 1. ������. ��������, ����������� ��� �������.
	//�������� ������ ������ �� ��������� Point - ptList1 � ���������
	//��� ���������� � ������� ������� push_back(),
	//push_front, insert()
	list<Point> ptList1;
	list<Point>::iterator itlist = ptList1.begin();
	ptList1.push_back(Point(1, 1));
	ptList1.push_front(Point(2, 2));
	ptList1.push_back(Point(3, 3));
	ptList1.push_front(Point(4, 4));
	ptList1.insert(itlist, Point(5,5));

	//�������� ������ �������, ������� ����� �������� ��������
	//������ ���������� �� ������. ��������� ������ ������� �� �����������
	//vector � list. ��������� - �������� �� ������� ��� ����������.

	printInfo(ptList1);
	printInfo(vPoint2);


	//�������� ����� �� ������� "�����������" - reverse()

	ptList1.reverse();
	stop

	//�������� ������ ptList2 �� ��������� Point ����� �������, ����� �� ���� 
	//������ ������� ��������� ���� Point, �� �������� ��������� ������ �������������
	//�� � �������� ������� (����������� ��� ��������������� ����������� ���������)

	list<Point> ptList2(ptList1.rbegin(), ptList1.rend());
	stop

	//������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
	//�� �����������.
	//���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
	//�������� ����������

	ptList1.sort();
	ptList2.sort();
	stop

	//���������� ��������������� ������ - merge(). ����������: ���
	//��� ���� ���������� � ������ �������.

	ptList1.merge(ptList2);	// �������� �� "�������" ������ ����������� � "�����" � �����������
	stop

	//���������� �������� �� ������ - remove()
	//��������� �� ������ ������� � ������������ ���������.
	//���������: ��� ������ ���� ����������� � ������ Point?

	ptList1.remove(Point (2,2));
	stop

		//���������� �������� �� ������, ���������������� ��������� �������:
		//����� �� ��������� ������������ - remove_if(). 

		ptList1.push_back(Point(-3, 7));
		ptList1.push_front(Point(4, -5));
		ptList1.remove_if(neg);
		stop

		//���������� �� ������ ������ ������������� ������ - unique(). 

		ptList1.unique();
	stop

///////////////////////////////////////////////////////////////////
	//������� 2.������� � ����� ������� - ��������� deque

	//�������� ������ deque � ���������� ���� Point. � �������
	//assign ��������� deque ������� ��������� �������. � �������
	//�������������� ���� � ���������� ������� �������������� �������
	//�������� �������� ��������� �� ������

		deque<Point> ptDeque;

		ptDeque.assign(vPoint2.begin(), vPoint2.end());


	//�������� deque � ���������� ���� MyString. ��������� ��� ����������
	//� ������� push_back(), push_front(), insert()
	//� ������� erase ������� �� deque ��� ��������, � ������� �������
	//���������� � 'A' ��� 'a'

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