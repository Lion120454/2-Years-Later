#include <iostream>
#include "stdafx.h"
using namespace std;


int main()
{
	_int8 B = 10;//byte
	_int16 A = 20;//word
	_int32 C = 1000, D, E;//dword
	//D = C- A/B=998
	_asm
	{
		mov AL, B; //AL=B
		cwde; //EAX=AL
		mov D, EAX; //Сохраняем в D

		mov AX, A; //AX=A
		cwde; //EAX=AX
		mov EDX, 0; //Записываем остаток
		div D; //EAX=EAX:D
		mov D, EAX; //Сохраняем в D

		sub C, EAX; //C=C-EAX
		mov EAX, C; //EAX=C
		mov D, EAX; //Сохраняем в D
	};
	//E = B*B-A+C=1080
	printf("16 D= %x \n", D);
	printf("10 D= %d \n", D);
	printf("---------\n", D);
	_asm
	{
		mov AL, B; // AL=B
		imul B; //AL=AL*B
		cwde; //EAX=AL
		mov E, EAX;//Сохраняем в E

		mov AX, A;// AX=A
		cwde; //EAX=AX
		sub E, EAX; //E=E-EAX
		mov EAX, E; //EAX=E
		add EAX, C; //EAX=EAX+C 
		mov E, EAX; //Сохраняем  в E
	}
	printf("16 E= %x \n", E);
	printf("10 E= %d \n", E);
	return 0;
}
