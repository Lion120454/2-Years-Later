#include <iostream>
#include <cmath>
#include "stdafx.h"
#include "class.h"

using namespace std;

namespace cl
{
	Vectors::Vectors(double valueX, double valueY, double valueZ)
	{
		//this->id=id_count;
		x = valueX;
		y = valueY;
		z = valueZ;
		//cout << "Конструктор№" << id << endl;
	}
	Vectors::Vectors()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Vectors::~Vectors()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	double Vectors::get_X()const
	{
		return this->x;
	}

	double Vectors::get_Y()const
	{
		return this->y;
	}
	double Vectors::get_Z()const
	{
		return this->z;
	}
	void Vectors::Print()
	{
		cout << "Вывод:" << endl;
		cout << "Вектор Х: " << x << endl;
		cout << "Вектор Y: " << y << endl;
		cout << "Вектор Z: " << z << endl;
		cout << "\n" << endl;
	}
	void Vectors::set_X()
	{
		cin >> x;
	}
	void Vectors::set_Y()
	{
		cin >> y;
	}
	void Vectors::set_Z()
	{
		cin >> z;
	}
	double Vectors::Module()const
	{
		cout << "Нахождение модуля:" << endl;
		return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
	}
	void Vectors::Multiplication_by_scalar(double scalar)
	{
		cout << "Умножение на скаляр:" << endl;
		x = x*scalar;
		y = y*scalar;
		z = z*scalar;
	}
	Vectors::Vectors (const Vectors &a)
	{
		this->x = a.get_X();
		this->y = a.get_Y();
		this->z = a.get_Z();
	}
	void Vectors::Norm(double module)
	{
		cout << "Нормирование:" << endl;
		x = x / module;
		y = y / module;
		z = z / module;
	}
	Vectors SumVectors(const Vectors& a, const Vectors& b)
	{
		cout << "Сумма:" << endl;
		double x3, y3, z3;
		x3 = a.get_X() + b.get_X();
		y3 = a.get_Y() + b.get_Y();
		z3 = a.get_Z() + b.get_Z();
		Vectors c(x3, y3, z3);
		return c;
	}
	Vectors MinusVectors(const Vectors& a, const Vectors& b)
	{
		cout << "Разность:" << endl;
		double x3, y3, z3;
		x3 = a.get_X() - b.get_X();
		y3 = a.get_Y() - b.get_Y();
		z3 = a.get_Z() - b.get_Z();
		Vectors c(x3, y3, z3);
		return c;
	}
	Vectors MultiplicationVectors(const Vectors& a, const Vectors& b)
	{
		cout << "Произведение:" << endl;
		double  x3, y3, z3;
		x3 = (a.get_Y() * b.get_Z()) - (a.get_Z()*b.get_Y());
		y3 = (a.get_Z() * b.get_X()) - (a.get_X()*b.get_Z());
		z3 = (a.get_X() * b.get_Y()) - (a.get_Y()*b.get_X());
		Vectors c(x3, y3, z3);
		return c;
	}
	double Scalar_multiplicationVectors(const Vectors& a, const Vectors& b)
	{
		cout << "Скалярное произведение:" << endl;
		double scalar;
		scalar = (a.get_X()*b.get_X()) + (a.get_Y()*b.get_Y()) + (a.get_Z()*b.get_Z());
		return scalar;
	}

	double CosVectors(const Vectors& a, const Vectors& b)
	{
		cout << "Косинус:" << endl;
		double module_a, module_b;
		module_a = (a.get_X()*a.get_X()) + (a.get_Y()*a.get_Y()) + (a.get_Z()*a.get_Z());
		module_b = (b.get_X()*b.get_X()) + (b.get_Y()*b.get_Y()) + (b.get_Z()*b.get_Z());
		return ((a.get_X()*b.get_X()) + (a.get_Y()*b.get_Y()) + (a.get_Z()*b.get_Z())) / (sqrt(module_a)*sqrt(module_b));
	}
	double SinVectors(double cos)//Синус
	{
		cout << "Синус:" << endl;
		return sqrt(1 - (cos*cos));
	}
	double cornerVectors(const Vectors& a, const Vectors& b)//Угол
	{
		return (atan2(SinVectors(CosVectors(a, b)), CosVectors(a, b)) * (360 / (2 * 3.1415926536)));
	}
}