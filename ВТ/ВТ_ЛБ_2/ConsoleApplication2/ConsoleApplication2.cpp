#include "stdafx.h"
#include <iostream>
#include <locale.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Rus");
	unsigned int A=0x11223344, B=0x55667788;
	cout << "��������� ��������� ����:" << endl;
	printf("A= %x \n", A);
	printf("B= %x \n", B);
	_asm
	{
		mov AL, byte ptr B; // ������ �������� ����� B � ������� AL  
		xchg byte ptr A, AL; // ������ ������� �������� �������� ����� A � �������� AL 
		xchg byte ptr B, AL;// ������ ������� �������� �������� ����� B � �������� AL  

		mov AH, byte ptr A + 2;// ������ ����� A+2 � ������� AH 
		xchg byte ptr B + 2, AH;// ������ ������� �������� ����� B+2 � �������� AH
		xchg byte ptr A + 2, AH;// ������ ������� �������� ����� A+2 � �������� AH

		mov AH, byte ptr B + 2;// ������ ����� B+2 � ������� AH 
		xchg byte ptr B + 3, AH;// ������ ������� �������� �������� ����� B � �������� AH
		xchg byte ptr B + 2, AH;// ������ ������� �������� ����� B+2 � �������� AH

	};
	cout << "����� ������������:" << endl;
	printf("A= %x \n", A);
	printf("B= %x \n", B);
	return 0;
}

