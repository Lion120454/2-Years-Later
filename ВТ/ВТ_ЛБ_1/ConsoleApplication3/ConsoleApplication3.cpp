#include "stdafx.h"
#include <iostream>
using namespace std;

void bit8(char a)
{
	int flag = 0;
	for (int i = 0; i < 8; i++)
	{
		if ((a >> (7 - i)) & 1)
		{
			cout << '1';
			flag = 1;
		}
		else
		{
			cout << '0';
		}
	}
	cout << "\n------------\n";
}
void bit16(short a)
{
	int flag = 0;
	for (int i = 0; i < 16; i++)
	{
		if ((a >> (15 - i)) & 1)
		{
			cout << '1';
			flag = 1;
		}
		else
		{
			cout << '0';
		}
		if ((i + 1) % 8 == 0)
		{
			cout << ' ';
		}
	}
	cout << "\n---------------------\n";
}
void bit32(int a)
{
	int flag = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((a >> (31 - i)) & 1)
		{
			cout << '1';
			flag = 1;
		}
		else
		{
			cout << '0';
		}
		if ((i + 1) % 8 == 0)
		{
			cout << ' ';
		}
	}
	cout << "\n------------------------------\n";
}
void bit32_f(int a, float b)
{
	int flag = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((a >> (31 - i)) & 1)
		{
			cout << '1';
			flag = 1;
		}
		else
		{
			cout << '0';
		}
		if ((i + 1) % 8 == 0)
		{
			cout << ' ';
		}
	}
	cout << '.';
	float x = b;
	for (int i = 0; i < 10; i++)
	{
		x = x * 2;
		if ((int)x == 1)
		{
			cout << "1";
			x--;
		}
		else
		{
			cout << "0";
		}
	}
	cout << "\n------------------------------\n";
}
void bit64_d(int a, double b)
{
	int flag = 0;
	for (int i = 0; i < 64; i++)
	{
		if ((a >> (63 - i)) & 1)
		{
			cout << '1';
			flag = 1;
		}
		else
		{
			cout << "0";
		}
		if ((i + 1) % 8 == 0)
		{
			cout << ' ';
		}
	}
	cout << '.';
	double x = b;
	for (int i = 0; i < 10; i++)
	{
		x = x * 2;
		if ((int)x == 1)
		{
			cout << "1";
			x--;
		}
		else
		{
			cout << "0";
		}
	}
	cout << "\n------------------------------\n";
}

int main()
{
	//Целые числа
	//8-bit
	char char_num = '-5';//53
	cout << "5= ";
	bit8(char_num);
	unsigned char uns_char_num = '7';//55
	cout << "7= ";
	bit8(uns_char_num);
	//16-bit
	short short_num = 32555;
	cout << "32555= ";
	bit16(short_num);
	unsigned uns_short_num = 15;
	cout << "15= ";
	bit16(uns_short_num);
	//32-bit
	int int_num = 5;
	cout << "5= ";
	bit32(int_num);
	unsigned int uns_int_num = 7;
	cout << "7= ";
	bit32(uns_int_num);

	//Вещественые числа
	//32-bit
	int c1, c2;
	float float_num = 5.468, d1;
	c1 = (int)float_num;
	d1 = float_num - c1;
	cout << "5.468= ";
	bit32_f(c1, d1);
	//64-bit
	double double_num = 258.98, d2;
	c2 = (int)double_num;
	d2 = double_num - c2;
	cout << "258.98= ";
	bit64_d(c2, d2);
	return 0;
}