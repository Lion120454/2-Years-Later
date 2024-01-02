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

	class Vector
	{
	private:
		double* dateVector;//Информация вектора
		const int VectorID;//ID Вектора
		static int countVector;// Количество Векторов
	public:
		Vector();//Конструктор Матрицы по умолчанию
		Vector(double* _date);//Конструктор Матрици по массиву
		Vector(const Vector& _vector);//Конструктор копирования Матрицы
		~Vector();//Деструктор Матрицы
		double* GetDateVector(Vector& _vector)const;

		bool Check_Plus_Vector(Vector& _vector)const;
		bool Check_Mul_Vector(Vector& _vector)const;

		double Max_Vector()const;//Метод поиска максимального элемента Вектора
		double Min_Vector()const;//Метод поиска минимального элемента Вектора

		DopClass operator[](int _index);
		friend std::ostream& operator<<(std::ostream& _os, const Vector& _vector); //Переопределение оператора << для Вектора

		Vector& operator=(Vector&& _vector);//Обмен данными Векторов

		Vector& operator+=(const Vector& _vector); //Переопределение оператора += для Векторов
		//Vector& operator+=(const Matrix& _vector);//Переопределение оператора += для Векторов и Матрицы

		Vector& operator-=(const Vector& _vector); //Переопределение оператора -= для Векторов
		//Vector& operator-=(const Matrix& _matrix);//Переопределение оператора +=

		Vector& operator*=(const Vector& _vector); //Переопределение оператора *= для Векторов
		//Vector& operator*=(const Matrix& _vector); //Переопределение оператора *= для Векторов

		Vector& operator*=(double _number); //Переопределение оператора *= на скаляр для Векторов
	};

	class Matrix
	{
	private:
		double* dateMatrix;//Информация матрицы
		const int MatrixID;//ID Матрицы
		static int countMatrix;// Количество Матриц
	public:
		Matrix();//Конструктор Матрицы по умолчанию
		Matrix(double* _date);//Конструктор Матрици по массиву
		Matrix(const Matrix& _matrix);//Конструктор копирования Матрицы
		~Matrix();//Деструктор Матрицы
		double* GetDateMatrix(Matrix& _matrix)const;

		bool Check_Plus_Matrix(Matrix& _matrix)const;//Метод проверки возможности сложения двух Матриц
		bool Check_Mul_Matrix(Matrix& _matrix)const;//Метод проверки возможности умножения двух Матриц

		bool Check_Plus_MatrixAndVector(double* _matrix, double* _vector)const;//Метод проверки возможности сложения Матрицы и Вектора
		bool Check_Mul_MatrixAndVector(double* _matrix, double* _vector)const;//Метод проверки возможности умножения Матрицы и Вектора

		double Max_Matrix()const;//Метод поиска максимального элемента матрицы
		double Min_Matrix()const;//Метод поиска минимального элемента матрицы

		DopClass operator[](int _index);//Переопределение оператора []
		friend std::ostream& operator<<(std::ostream& _os, const Matrix& _mat); //Переопределение оператора << для Матрицы
		
		Matrix& operator=(Matrix&& _matrix);//Обмен данными Матриц
		Matrix& operator=(Vector&& _vector);//Обмен данными Вектора в Матрицу

		Matrix& operator+=(const Matrix& _matrix); //Переопределение оператора += для Матриц
		Matrix& operator+=(const Vector& _vector);//Переопределение оператора += для Матриц и Вектора

		Matrix& operator-=(const Matrix& _matrix); //Переопределение оператора -= для Матриц
		Matrix& operator-=(const Vector& _matrix); //Переопределение оператора -= для Матриц

		Matrix& operator*=(const Matrix& _matrix); //Переопределение оператора *= для Матриц
		Matrix& operator*=(const Vector& _matrix); //Переопределение оператора *= для Матриц

		Matrix& operator*=(double _number); //Переопределение оператора *= на скаляр для Матриц
	};
		Matrix operator+(const Matrix& _leftMat, const Matrix& _rightMat);//Переопределение оператора +
		Vector operator+(const Vector& _leftVec, const Vector& _rightVec);//Переопределение оператора +
		Matrix operator+(const Matrix& _leftMat, const Vector& _rightVec);//Переопределение оператора +
		Matrix operator+(const Vector& _leftVec, const Matrix& _rightMat);//Переопределение оператора +

		Matrix operator-(const Matrix& _leftMat, const Matrix& _rightMat);//Переопределение оператора -
		Vector operator-(const Vector& _leftVec, const Vector& _rightVec);//Переопределение оператора -
		Matrix operator-(const Matrix& _leftMat, const Vector& _rightVec);//Переопределение оператора -
		Matrix operator-(const Vector& _leftVec, const Matrix& _rightMat);//Переопределение оператора -

		Matrix operator*(const Matrix& _leftMat, const Matrix& _rightMat);//Переопределение оператора *
		Vector operator*(const Vector& _leftVec, const Vector& _rightVec);//Переопределение оператора *
		Matrix operator*(const Matrix& _leftMat, const Vector& _rightVec);//Переопределение оператора *
		Matrix operator*(const Vector& _leftVec, const Matrix& _rightMat);//Переопределение оператора *

		Matrix operator*(const Matrix& _leftMat, double _scalar);//Переопределение оператора * на скаляр
		Vector operator*(const Vector& _leftVec, double _scalar);//Переопределение оператора *
}