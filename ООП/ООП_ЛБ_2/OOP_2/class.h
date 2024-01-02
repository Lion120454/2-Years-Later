#include <iostream>
#include <cmath>

namespace cl
{
	//Переопределение оператора []
	class DopClass
	{
	public:
		double operator[](int _index);//метод для строк
		double* line;//Массив строк
		int maxColumns;//Максимум столбцов
	};

	class Matrix
	{
	private:
		int lines;//Строки
		int columns;//Столбцы
		double* date;//Информация
		const int id;
		static int countMatrix;
	public:
		Matrix();//Конструктор по умолчанию
		explicit Matrix(unsigned int _lines = 0, unsigned int _columns = 0, double* _date = NULL);// Конструктор квадратной и прямоугольной матрицы
		Matrix(const Matrix& _matrix);//Конструктор копирования
		Matrix(Matrix&& _matrix);//Конструктор перемещения
		~Matrix();//Деструктор

		void Сreate_Matrix(unsigned int _lines, unsigned int _columns, double* _info);//Метод создания матрицы

		int get_Lines()const;//Метод получения кол. строк
		int get_Columns()const;//Метод получения кол. столбцов

		void set_Lines(int _lines);//Метод ввода строк
		void set_Columns(int _columns);//Метод ввода столбцов

		bool Check_Mul(Matrix& _matrix)const;//Метод проверки возможности умножения двух матриц
		bool Check_Plus(Matrix& _matrix)const;//Метод проверки возможности сложения двух матриц

		double Max_Matrix()const;//Метод поиска максимального элемента матрицы
		double Min_Matrix()const;//Метод поиска минимального элемента матрицы

		DopClass operator[](int _index);
		//Переопределение оператора []

		friend std::ostream& operator<<(std::ostream& _os, const Matrix& _mat); //Переопределение оператора <<
		Matrix& operator=(const Matrix& _mat); //Переопределение оператора =
		Matrix& operator=(Matrix&& _mat);//Обмен
		Matrix& operator+=(const Matrix& _mat); //Переопределение оператора +=
		Matrix& operator-=(const Matrix& _mat); //Переопределение оператора -=
		Matrix& operator*=(const Matrix& _mat); //Переопределение оператора *=
		Matrix& operator*=(const double _num); //Переопределение оператора *= на скаляр
	};

	Matrix operator+(const Matrix& _leftMat, const  Matrix& _rightMat);//Переопределение оператора +
	Matrix operator-(const Matrix& _leftMat, const Matrix& _rightMat);//Переопределение оператора -
	Matrix operator*(const Matrix& _leftMat, const Matrix& _rightMat);//Переопределение оператора *
	Matrix operator*(const Matrix& _leftMat, double _scalar);//Переопределение оператора * на скаляр
}