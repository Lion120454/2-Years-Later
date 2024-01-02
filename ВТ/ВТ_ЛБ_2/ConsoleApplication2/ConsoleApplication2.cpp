#include "stdafx.h"
#include <iostream>
#include <locale.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Rus");
	unsigned int A=0x11223344, B=0x55667788;
	cout << "Начальная нумерация байт:" << endl;
	printf("A= %x \n", A);
	printf("B= %x \n", B);
	_asm
	{
		mov AL, byte ptr B; // запись младшего байта B в регистр AL  
		xchg byte ptr A, AL; // меняем местами значения младшего байта A и регистра AL 
		xchg byte ptr B, AL;// меняем местами значения младшего байта B и регистра AL  

		mov AH, byte ptr A + 2;// запись байта A+2 в регистр AH 
		xchg byte ptr B + 2, AH;// меняем местами значения байта B+2 и регистра AH
		xchg byte ptr A + 2, AH;// меняем местами значения байта A+2 и регистра AH

		mov AH, byte ptr B + 2;// запись байта B+2 в регистр AH 
		xchg byte ptr B + 3, AH;// меняем местами значения старшего байта B и регистра AH
		xchg byte ptr B + 2, AH;// меняем местами значения байта B+2 и регистра AH

	};
	cout << "После перестановки:" << endl;
	printf("A= %x \n", A);
	printf("B= %x \n", B);
	return 0;
}

