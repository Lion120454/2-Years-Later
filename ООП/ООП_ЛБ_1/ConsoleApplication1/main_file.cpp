#include "stdafx.h"
#include "locale.h"
#include "iostream"
#include "cmath"
#include "class.h"
using namespace std;
using namespace cl;

int main()
{
	setlocale(LC_ALL, "ru");
	Vectors V1(0, 0, 0), V2(2, 3, 7), V3(7, 5, 9);
	//Ввод переменых в первый вектор и его вывод
	cout << "Введите X" << endl;
	V1.set_X();
	cout << "Введите Y" << endl;
	V1.set_Y();
	cout << "Введите Z" << endl;
	V1.set_Z();
	V1.Print();
	//Нахождение модуля первого вектора
	double module;
	module=V1.Module();
	cout << "Модуль V1= " << module << endl;
	//Умножение первого вектора на скаляр
	double scalar;
	cout << "Введите скаляр" << endl;
	cin >> scalar;
	V1.Multiplication_by_scalar(scalar);
	V1.Print();
	//Копирование второго вектора в первый
	cout << "Копирование V1" << endl;
	V1.get_X();
	V1.get_Y();
	V1.get_Z();
	V1.Print();
	//Нахождение нормали первого вектора
	V1.Norm(V1.Module());
	V1.Print();
	//Сумма второго и третьего вектора
	V1 = SumVectors(V2, V3);
	V1.Print();
	//Разность первого и второго вектора
	V3 = MinusVectors(V1, V2);
	V3.Print();
	//Произведение третьего и первого вектора
	V2 = MultiplicationVectors(V3, V1);
	V2.Print();
	//Скалярное произведение первого и второго вектора
	double scalar_m;
	scalar_m = Scalar_multiplicationVectors(V1, V3);
	cout <<"Скалярное произведение= "<<scalar_m<< endl;
	//Косинус и Синус угла между вторым и третим вектором
	double cosinus, sinus;
	cosinus = CosVectors(V2, V3);
	cout << "Косинус= " << cosinus << endl;
	sinus = SinVectors(cosinus);
	cout << "Синус= " << sinus << endl;
	//Величины угла в градусах между векторами
	double c = CornerVectors(V1, V2);
	cout << "Угол между V1 и V3= " << c << endl;
	return 0;
}