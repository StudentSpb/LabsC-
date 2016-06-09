#include "myRect.h"
#include "myString.h"
#include "Bochka.h"
#include <iostream>
#include <algorithm>


#define stop __asm nop

class Bochka;

void main()
{
	using namespace std;

	//������� 1.���������� ������. �������� ���������� ������.
	//����� ������� ������. 
	//�������� �������� Class View - (����� �� ������� ����� ������� �
	//������ - ������� Rect � MyString)
	//�������� �������� �� ����������� ����� �� ���� ������ ������ - ���
	//���������� ������������ ������� � ������� ����� ������.

	//����� ����������� ���������� ��� �������� ���������� ������?
	{
		Rect rect; //�� ���������
		stop
	}

	//1a. �������� � ���������� ����������� � ����������� ���
	//������������� ���������� ������. �������� ��������� ������ Rect
	//� ������� ������������ � �����������. ���� ���������� ������
	//������ � ���������� ���������, ��������� - ���� ��� ��
	//�������? ��������� ���������� ������.
	//�������� ������� � ������ ������ �� �����, ����������:
	//� ����� ������ ���������� ����� ������������(������?)?

		//���� ������ ��������� �����, �� ���������� ������� ����������� � �����������
		//���� ����� ��������� � �����������, �� ���������� ����������� � �����������
		Rect rect(5, 10, 10, 15);
		stop



			//1�. ��� ��������������� ������� ����������� ������������ ��� ����������
			//������������� ������������� ���������� ������, ��������, �����



			//1�. ���������, ��� ������� ��������� � ������, ����� ������������ �����
			//���������� ��������� �������:

			//Rect rrr(4,3,2,1);

			stop
			//1�. ��������, ���������� � �������� ����� ������ InflateRect(), 
			//������� ����������� ������� �������������� �� �������� ����������
			//(��������� ������� �� ������ - ������ ������� �� ���� ��������).
			//���������: �������� � ���������� ������ ����� �� ������ "�������",
			//�� � � ������� Wizard-a Class View. ��� �����: �������� ��������
			//ClassView ���� �������, �������� �������� ����� Rect � �������
			//������ ������ ���� - � ����������� ����������� ���� ��������
			//Add/Add Member Function... � ������� ����������� ���������� ������
			//"����� ��������" Wizard-� ��� �������� � ���������� �����.

			rect.InflateRect(5, 5, 3, 2);
	

	
	stop


	//������� 2.���������� ������������� � ������� ������.
	//����������� �����������.

	//2�.�������� � ���������� ����������� ����������� � ������ Rect.
	//�������� ������� �� �����, ����������, �����
	//����������� ���������� ��� �������� r1,r2,r3 � r4?
	//���� ����� ���������� ��������� ��������?
		Rect r1;			// ������ ����������� �� ���������
		Rect r2(1,2,3,4);	// ������ ����������� � �����������
		Rect r3 = r1;		// ������ ����������� �����������
		Rect r4(r2);		// ������ ����������� �����������
		stop


  //2�. �������� � ���������� � ������ Rect ����� InflateRect(),
	//������� ��������� ��� ���������, �� ��������� ������ 1, � 
	//���������� ������� �������������� �� �� �������� ����������.
	//��� ����� �������� ���������� ������� InflateRect()?
		r1.InflateRect(1,1);	// ������ ��� ������� r1
		r2.InflateRect(2,2);	// ������ ��� ������� r2
	//����� �� ������� InflateRect() ���������� � ������ �� ���� �������?
		r3.InflateRect(2,2,2,2);	//������ ����� � 4�� �����������
		r3.InflateRect(3,3);		//������ ����� � 2�� �����������	
		r3.InflateRect(5);			//������ ����� � 2�� �����������
		r3.InflateRect();			//������ ����� � 2�� �����������
	stop


	
	//������� 3.������������� �������. ������������. 
	{
	Rect r;
	//���������������� ��������� ������. ��������� ������
	//�����������

//	int tmp = r.m_left; // ���� ��������� � � ���� ������ ��������� 



	//������� � ����� Rect ����� void SetAll(...),
	//������� ����������� ���������� ������ ������������
	//��������. �������� ��������� �����, ��������� ������������. 

	r3.SetAll(5, 5, 2, 5);


	//������� � ����� Rect ������ ����� GetAll(...),
	//������� "�������" �������� private-���������� ������.
	//�������� ��������� �����, ��������� ������������. 
	int left, right, top, bottom;
	r3.GetAll(left, right, top, bottom);

	stop
	}


	//������� 4.�������� ���������� ������ � �������� ���������
	//�������. ����������� ������� ������ �� ��������. ��������
	//�������� � ������������ ����������� ��� �������� ��������
	//�� �����, ����������: � ����� ������ ���������� ���������
	//� ������������ �����������. 
	//�������� ���������� ������� 
	// Rect BoundingRect(Rect, Rect);
	//������� ��������� ��� ������� ������ Rect �� �������� �
	//���������� ������ ������ Rect, ������� �������� ���������������,
	//� ������� ������� �������� ��������������. ��� ����������
	//�������� ���������� � ����������� ������� ������?

	//���������*: ������ ���� �� ������ ��� ����, ��� �������������
	//����� ��������� "�����������������", �� ���� m_left>m_right ���/�
	//m_top>m_bottom

	{

		Rect r1(1,2,3,4), r2(5,6,7,8),r3;
		r3= BoundingRect(r1, r2);
	stop
	
	//������� 4�. �������� �������� �� ������.
	//�������� ���������� ������� BoundingRect2, ������� ��������� �� ��
	//������, �������� ��������� �� ������
	//���������� �� ������������ ��� �������� ����������?
	

	r3 = BoundingRect2(r1, r2);
	stop
	}




	//������� 5. ��������� �� �����. �������� � ����������
	//����� ���������� ������. ��������� �������� � 
	//������������ (�������������) � �����������. ����������: ����� ���
	//������� �� �������� ���������� �����������, � ����� - ����������?
	{
		Rect r1;
		Rect*	pR = new Rect(1,2,1,2);	
		{
			Rect r2(r1); //���������� ����������� �����������
			Rect arRect[2];
			for(int i=0; i<3; i++)
			{
				static Rect r3 (i,i,i,i) ;
				Rect r4(*pR);
				Rect r5(i,i,i,i);
			} //��� ���������� ����� ����� ���������� ���������� ��� r4 � r5
		}//�� ���������� ����� ����� ������ ���������� r2
		delete pR;	
		stop
	} //��������� ���������� r1


	//������� 6.����������� + ���������� = ��������������
	// ���������. ����� MyString
	// ����������� ������������ (�������������) � ����������� ����������
	//���������� ������������� � ����������� �������
	//C ������� ��������� ���������� ����� ����������
	//������ � ������������ ������ ��� ������-����� ������
	{
		MyString	str("It's my string!");
		//�������� ����� GetString(), ������� ��������� ������ � ���������� ������.
		//� ������� cout � ������ GetString() ������������ ������ ������� str
		//���������: ���������, ��� ������� ��������� ����������� ����� GetString().

		//...
		const char* string = str.GetString();
		std::cout << string;
	}
	stop


	//6a. ���������������� ��������� ��������. ��������� - �����
	//������������ ��� �������. ���������� ��������� ��������� (���?)
	{
		MyString str1("The first string!");
		MyString str2 = str1;


		//6�. ���������� ����� SetNewString, ������� ����� �������� ������
		// �� �����

		str1.SetString("New String!");
		std::cout << " "<< str1.GetString();
	}
		stop

		//6�. �������� ���������� �������, ������� ����� ��������� �����
		//���������� ���������� �� ������, � ���������� ������ MyString,
		//� ������� ������ ����� ������������� ����������
		MyString newStr = GetMyString("1234", "qwer", "asdf", "zxcv",0);
		cout << " " << newStr.GetString();
	stop


	//������� 7.������ �������� ������.
	{
	//�������� � ������������������ ������ ar �� ��������
	// ���� MyString. ��������:
	//��� ������ �����������? N=3
	//MyString arstr[N] = {...
	
	const int N = 3;
	MyString arstr[N] = {MyString("1234"), MyString("qwer"), MyString("zxcv")};


	//�������� - ������ �����-������ ������
	for (int i = 0; i < N; i++)
	{
		cout << "\n" << arstr[i].GetString();
	}


	//��������� ������ �������, �� ������� ������ ���������������:
	//N=5???
	const int M = 5;
	MyString arstr1[M] = {arstr[0],arstr[1], arstr[2], MyString(""), MyString("")};
	

	//�������� � ������������������ ������ ��������	���� Rect.
	Rect rect1[N] = { Rect(1,2,3,4), Rect(5,6,7,8), Rect(1,3,5,6)};

	}
	stop


	//������� 8.������ ���������� �� ������� ������.
	{
	//�������� � ������������������ ������ arPtr �� ���� 
	//���������� �� ������� ���� MyString.
	const int N = 3;

	MyString*  arPtr[N] = {new MyString("1234"), new MyString("qwer"), new MyString("zxcv") };
	
	//������ �����-������ ������
	for (int i = 0; i < N; i++)
	{
		cout << "\n" <<arPtr[i]->GetString();
	}
	for (int i = 0; i < N; i++)
	{
		delete arPtr[i];
	}
	stop
	}
	

	//������� 9.  ������ � ������� ������� ��������� ������:
	//���� ��� ����� ���������� ������. � ����� ����� � ��������� ������
	//������� ���������� ����� (96%), � ������ � ����.
	//������� �������� 1� ���������� ���������� ���������� �� ����� �����
	//� ������ ��������� ��������: �� ������ ��������
	//���������� �� ������ ����� -> ������ �� ������
	//���������� �� ������ ����� -> ������ � ������.
	//��������� ���������� ����� ��������, �� ������� ������������ ������ �
	//������ ����� ������ ������ 50%.

	Bochka _spirt(100, 0.96, spirt);
	Bochka _water(100, 0, watet);

	float conc = _spirt.GetConc();
	int i = 0;
		while(conc > 0.5)
		{
			_spirt.Pereliv(_water); //��� spirt.Pereliv(water, �����_������);
			_water.Pereliv(_spirt); // ����������
			conc = _spirt.GetConc();
			i++;
		}
		cout << "\n" <<i;
		stop;
}//	end_main

