#include <iostream>
#include <cmath> 

namespace cl
{
	class Vectors
	{
		private:
			double x;
			double y;
			double z;
		public:
			Vectors(double valueX, double valueY, double valueZ);//Конструктор
			Vectors();//Нулевой конструктор
			~Vectors();//Диструктор

			double get_X()const;//Возвращает x
			double get_Y()const;//Возвращает y
			double get_Z()const;//Возвращает z
			void Print();//Вывод на экран
			void set_X();//Запись в x
			void set_Y();//Запись в y
			void set_Z();//Запись в z
			double Module()const;//Модуль
			void Multiplication_by_scalar(double scalar);//Умножение на скаляр
			Vectors(const Vectors &q);//Копирование
			void Norm(double module);//Нормировка вектора
	};
			Vectors SumVectors(const Vectors& a, const Vectors& b);//Сумма
			Vectors MinusVectors(const Vectors& a, const Vectors& b);//Разность
			Vectors MultiplicationVectors(const Vectors& a, const Vectors& b);//Произведение
			double Scalar_multiplicationVectors(const Vectors& a, const Vectors& b);//Скалярное произведение
			double CosVectors(const Vectors& a, const Vectors& b);//Косинус
			double SinVectors(double cos);//Синус
			double CornerVectors(const Vectors& a, const Vectors& b);//Угол
};