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

	class Matrix
	{
	private:
		int lines;//������
		int columns;//�������
		double* date;//����������
		const int id;
		static int countMatrix;
	public:
		Matrix();//����������� �� ���������
		explicit Matrix(unsigned int _lines = 0, unsigned int _columns = 0, double* _date = NULL);// ����������� ���������� � ������������� �������
		Matrix(const Matrix& _matrix);//����������� �����������
		Matrix(Matrix&& _matrix);//����������� �����������
		~Matrix();//����������

		void �reate_Matrix(unsigned int _lines, unsigned int _columns, double* _info);//����� �������� �������

		int get_Lines()const;//����� ��������� ���. �����
		int get_Columns()const;//����� ��������� ���. ��������

		void set_Lines(int _lines);//����� ����� �����
		void set_Columns(int _columns);//����� ����� ��������

		bool Check_Mul(Matrix& _matrix)const;//����� �������� ����������� ��������� ���� ������
		bool Check_Plus(Matrix& _matrix)const;//����� �������� ����������� �������� ���� ������

		double Max_Matrix()const;//����� ������ ������������� �������� �������
		double Min_Matrix()const;//����� ������ ������������ �������� �������

		DopClass operator[](int _index);
		//��������������� ��������� []

		friend std::ostream& operator<<(std::ostream& _os, const Matrix& _mat); //��������������� ��������� <<
		Matrix& operator=(const Matrix& _mat); //��������������� ��������� =
		Matrix& operator=(Matrix&& _mat);//�����
		Matrix& operator+=(const Matrix& _mat); //��������������� ��������� +=
		Matrix& operator-=(const Matrix& _mat); //��������������� ��������� -=
		Matrix& operator*=(const Matrix& _mat); //��������������� ��������� *=
		Matrix& operator*=(const double _num); //��������������� ��������� *= �� ������
	};

	Matrix operator+(const Matrix& _leftMat, const  Matrix& _rightMat);//��������������� ��������� +
	Matrix operator-(const Matrix& _leftMat, const Matrix& _rightMat);//��������������� ��������� -
	Matrix operator*(const Matrix& _leftMat, const Matrix& _rightMat);//��������������� ��������� *
	Matrix operator*(const Matrix& _leftMat, double _scalar);//��������������� ��������� * �� ������
}