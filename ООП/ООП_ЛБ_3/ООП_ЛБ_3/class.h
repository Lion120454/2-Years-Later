#include <iostream>
#include <cmath>

namespace cl
{
	//��������������� ��������� []
	class DopClass
	{
	public:
		double operator[](int _index);//����� ��� �����
		double* line;//������ �����
		int maxColumns;//�������� ��������
	};

	class Vector
	{
	private:
		double* dateVector;//���������� �������
		const int VectorID;//ID �������
		static int countVector;// ���������� ��������
	public:
		Vector();//����������� ������� �� ���������
		Vector(double* _date);//����������� ������� �� �������
		Vector(const Vector& _vector);//����������� ����������� �������
		~Vector();//���������� �������
		double* GetDateVector(Vector& _vector)const;

		bool Check_Plus_Vector(Vector& _vector)const;
		bool Check_Mul_Vector(Vector& _vector)const;

		double Max_Vector()const;//����� ������ ������������� �������� �������
		double Min_Vector()const;//����� ������ ������������ �������� �������

		DopClass operator[](int _index);
		friend std::ostream& operator<<(std::ostream& _os, const Vector& _vector); //��������������� ��������� << ��� �������

		Vector& operator=(Vector&& _vector);//����� ������� ��������

		Vector& operator+=(const Vector& _vector); //��������������� ��������� += ��� ��������
		//Vector& operator+=(const Matrix& _vector);//��������������� ��������� += ��� �������� � �������

		Vector& operator-=(const Vector& _vector); //��������������� ��������� -= ��� ��������
		//Vector& operator-=(const Matrix& _matrix);//��������������� ��������� +=

		Vector& operator*=(const Vector& _vector); //��������������� ��������� *= ��� ��������
		//Vector& operator*=(const Matrix& _vector); //��������������� ��������� *= ��� ��������

		Vector& operator*=(double _number); //��������������� ��������� *= �� ������ ��� ��������
	};

	class Matrix
	{
	private:
		double* dateMatrix;//���������� �������
		const int MatrixID;//ID �������
		static int countMatrix;// ���������� ������
	public:
		Matrix();//����������� ������� �� ���������
		Matrix(double* _date);//����������� ������� �� �������
		Matrix(const Matrix& _matrix);//����������� ����������� �������
		~Matrix();//���������� �������
		double* GetDateMatrix(Matrix& _matrix)const;

		bool Check_Plus_Matrix(Matrix& _matrix)const;//����� �������� ����������� �������� ���� ������
		bool Check_Mul_Matrix(Matrix& _matrix)const;//����� �������� ����������� ��������� ���� ������

		bool Check_Plus_MatrixAndVector(double* _matrix, double* _vector)const;//����� �������� ����������� �������� ������� � �������
		bool Check_Mul_MatrixAndVector(double* _matrix, double* _vector)const;//����� �������� ����������� ��������� ������� � �������

		double Max_Matrix()const;//����� ������ ������������� �������� �������
		double Min_Matrix()const;//����� ������ ������������ �������� �������

		DopClass operator[](int _index);//��������������� ��������� []
		friend std::ostream& operator<<(std::ostream& _os, const Matrix& _mat); //��������������� ��������� << ��� �������
		
		Matrix& operator=(Matrix&& _matrix);//����� ������� ������
		Matrix& operator=(Vector&& _vector);//����� ������� ������� � �������

		Matrix& operator+=(const Matrix& _matrix); //��������������� ��������� += ��� ������
		Matrix& operator+=(const Vector& _vector);//��������������� ��������� += ��� ������ � �������

		Matrix& operator-=(const Matrix& _matrix); //��������������� ��������� -= ��� ������
		Matrix& operator-=(const Vector& _matrix); //��������������� ��������� -= ��� ������

		Matrix& operator*=(const Matrix& _matrix); //��������������� ��������� *= ��� ������
		Matrix& operator*=(const Vector& _matrix); //��������������� ��������� *= ��� ������

		Matrix& operator*=(double _number); //��������������� ��������� *= �� ������ ��� ������
	};
		Matrix operator+(const Matrix& _leftMat, const Matrix& _rightMat);//��������������� ��������� +
		Vector operator+(const Vector& _leftVec, const Vector& _rightVec);//��������������� ��������� +
		Matrix operator+(const Matrix& _leftMat, const Vector& _rightVec);//��������������� ��������� +
		Matrix operator+(const Vector& _leftVec, const Matrix& _rightMat);//��������������� ��������� +

		Matrix operator-(const Matrix& _leftMat, const Matrix& _rightMat);//��������������� ��������� -
		Vector operator-(const Vector& _leftVec, const Vector& _rightVec);//��������������� ��������� -
		Matrix operator-(const Matrix& _leftMat, const Vector& _rightVec);//��������������� ��������� -
		Matrix operator-(const Vector& _leftVec, const Matrix& _rightMat);//��������������� ��������� -

		Matrix operator*(const Matrix& _leftMat, const Matrix& _rightMat);//��������������� ��������� *
		Vector operator*(const Vector& _leftVec, const Vector& _rightVec);//��������������� ��������� *
		Matrix operator*(const Matrix& _leftMat, const Vector& _rightVec);//��������������� ��������� *
		Matrix operator*(const Vector& _leftVec, const Matrix& _rightMat);//��������������� ��������� *

		Matrix operator*(const Matrix& _leftMat, double _scalar);//��������������� ��������� * �� ������
		Vector operator*(const Vector& _leftVec, double _scalar);//��������������� ��������� *
}