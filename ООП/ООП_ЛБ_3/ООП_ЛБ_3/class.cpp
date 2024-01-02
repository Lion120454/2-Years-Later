#include <iostream>
#include <cmath>
#include <iomanip>
#include "cstdlib"
#include "class.h"

using namespace std;

namespace cl
{
	int Matrix::countMatrix = 0;
	Matrix::Matrix() :MatrixID{ countMatrix++ }//����������� ������� �� ���������
	{
		cout << "++����������� 1++" << endl;
		dateMatrix = NULL;
		cout << "++             ++" << endl;
	}
	Vector::Vector() :VectorID{ countVector++ }//����������� ������� �� ���������
	{
		cout << "++����������� 1++" << endl;
		dateVector = NULL;
		cout << "++             ++" << endl;
	}

	Matrix::Matrix(double* _date) :MatrixID{ countMatrix++ }//����������� ������� �� �������
	{
		cout << "++����������� 2++" << endl;
		dateMatrix = new double[_msize(_date) / sizeof(double)];
		for (int i = 0; i < (_msize(_date) / sizeof(double)); i++)
		{
			dateMatrix[i] = _date[i];
		}
		cout << "++             ++" << endl;
	}
	Vector::Vector(double* _date) :VectorID{ countVector++ }//����������� ������� �� �������
	{
		cout << "++����������� 2++" << endl;
		dateVector = new double[_msize(_date) / sizeof(double)];
		for (int i = 0; i < (_msize(_date) / sizeof(double)); i++)
		{
			dateVector[i] = _date[i];
		}
		cout << "++             ++" << endl;
	}

	Matrix::Matrix(const Matrix& _matrix) :MatrixID{countMatrix++}//����������� ����������� �������
	{
		cout << "++����������� 3++" << endl;

		dateMatrix = new double[_msize(_matrix.dateMatrix) / sizeof(double)];
		for (int i = 0; i < _msize(_matrix.dateMatrix) / sizeof(double); i++)
		{
			dateMatrix[i] = _matrix.dateMatrix[i];
			cout << "   " << dateMatrix[i];
		}
		cout << "++             ++" << endl;
	}
	Vector::Vector(const Vector& _vector) :VectorID{ countVector++ }//����������� ����������� �������
	{
		cout << "++����������� 3++" << endl;

		dateVector = new double[_msize(_vector.dateVector) / sizeof(double)];
		for (int i = 0; i < _msize(_vector.dateVector) / sizeof(double); i++)
		{
			dateVector[i] = _vector.dateVector[i];
			cout << "   " << dateVector[i];
		}
		cout << "++             ++" << endl;
	}

	Matrix::~Matrix()//���������� �������
	{
		cout << "++����������++" << endl;
		delete[] dateMatrix;
		cout << "++          ++" << endl;
	}
	Vector::~Vector()//���������� �������
	{
		cout << "++����������++" << endl;
		delete[] dateVector;
		cout << "++          ++" << endl;
	}

	double* Vector::GetDateVector(Vector& _vector)const
	{
		return _vector.dateVector;
	}
	double* Matrix::GetDateMatrix(Matrix& _matrix)const
	{
		return _matrix.dateMatrix;
	}

	bool Matrix::Check_Plus_Matrix(Matrix& _matrix)const//����� �������� ����������� �������� ���� ������
	{
		return (_msize(dateMatrix) / sizeof(double) == _msize(_matrix.dateMatrix) / sizeof(double));
	}
	bool Matrix::Check_Mul_Matrix(Matrix& _matrix)const //����� �������� ����������� ��������� ���� ������
	{
		return (_msize(dateMatrix) / sizeof(double) == _msize(_matrix.dateMatrix) / sizeof(double));
	}
	bool Vector::Check_Plus_Vector(Vector& _vector)const//����� �������� ����������� �������� ���� ��������
	{
		return (_msize(dateVector) / sizeof(double) == _msize(_vector.dateVector) / sizeof(double));
	}
	bool Vector::Check_Mul_Vector(Vector& _vector)const //����� �������� ����������� ��������� ���� ������
	{
		return (_msize(dateVector) / sizeof(double) == _msize(_vector.dateVector) / sizeof(double));
	}

	bool Matrix::Check_Plus_MatrixAndVector(double* _matrix, double* _vector)const//����� �������� ����������� �������� ���� ������
	{
		return (_msize(_matrix) / sizeof(double) == _msize(_vector) / sizeof(double));
	}
	bool Matrix::Check_Mul_MatrixAndVector(double* _matrix, double* _vector)const//����� �������� ����������� �������� ���� ������
	{
		return (_msize(_matrix) / sizeof(double) == _msize(_vector) / sizeof(double));
	}

	double Matrix::Max_Matrix()const//����� ������ ������������� �������� �������
	{
		double max = 0;
		for (int i = 0; i < (_msize(dateMatrix) / sizeof(double)); i++)
		{
			if (max < dateMatrix[i])
			{
				max = dateMatrix[i];
			}
		}
		return max;
	}
	double Matrix::Min_Matrix()const//����� ������ ������������ �������� �������
	{
		double min = Max_Matrix();
		for (int i = 0; i < (_msize(dateMatrix) / sizeof(double)); i++)
		{
			if (min > dateMatrix[i])
			{
				min = dateMatrix[i];
			}
		}
		return min;
	}
	double Vector::Max_Vector()const//����� ������ ������������� �������� �������
	{
		double max = 0;
		for (int i = 0; i < (_msize(dateVector) / sizeof(double)); i++)
		{
			if (max < dateVector[i])
			{
				max = dateVector[i];
			}
		}
		return max;
	}
	double Vector::Min_Vector()const//����� ������ ������������ �������� �������
	{
		double min = Max_Vector();
		for (int i = 0; i < (_msize(dateVector) / sizeof(double)); i++)
		{
			if (min > dateVector[i])
			{
				min = dateVector[i];
			}
		}
		return min;
	}

	//��������������� ���������[]
	double DopClass::operator[](int _index)
	{
		return line[_index];
	}
	DopClass Matrix::operator[](int _index)
	{
		DopClass mat;
		mat.line = &dateMatrix[_index];
		return mat;
	}
	DopClass Vector::operator[](int _index)
	{
		DopClass mat;
		mat.line = &dateVector[_index];
		return mat;
	}
	//��������������� ���������[]
	ostream& operator<<(ostream& os, const Matrix& _matrix)//��������������� ��������� << ��� �������
	{
		for (int i = 0; i < _msize(_matrix.dateMatrix) / sizeof(double); i++)
		{			
			os << " " << _matrix.dateMatrix[i];
		}
		os << endl;
		return os;
	}
	ostream& operator<<(ostream& os, const Vector& _vector)//��������������� ��������� << ��� �������
	{
		for (int i = 0; i < _msize(_vector.dateVector) / sizeof(double); i++)
		{
			os << " " << _vector.dateVector[i];
		}
		os << endl;
		return os;
	}
	Matrix& Matrix::operator=(Matrix&& _matrix)//����� ������� ������
	{
		swap(dateMatrix,_matrix.dateMatrix);
		return *this;
	}
	Vector& Vector::operator=(Vector&& _vector)//����� ������� ��������
	{
		swap(dateVector,_vector.dateVector);
		return *this;
	}
	Matrix& Matrix::operator=(Vector&& _vector)//����� ������� ������� � �������
	{
		double* bufer = _vector.GetDateVector(_vector);
		swap(dateMatrix, bufer);
		return *this;
	}

	Matrix& Matrix::operator+=(const Matrix& _matrix)//��������������� ��������� +=
	{
		Matrix check( _matrix.dateMatrix);
		if (Check_Plus_Matrix(check))
		{
			for (int i = 0; i < _msize(_matrix.dateMatrix) / sizeof(double); i++)
			{
				dateMatrix[i] += _matrix.dateMatrix[i];
			}
		}
		else
		{
			throw "Error";
		}
		return *this;
	}
	Vector& Vector::operator+=(const Vector& _vector)//��������������� ��������� +=
	{
		Vector check(_vector.dateVector);
		if (Check_Plus_Vector(check))
		{
			for (int i = 0; i < _msize(_vector.dateVector) / sizeof(double); i++)
			{
				dateVector[i] += _vector.dateVector[i];
			}
		}
		else
		{
			throw "Error";
		}
		return *this;
	}
	Matrix& Matrix::operator+=(const Vector& _vector)//��������������� ��������� +=
	{
		Vector check=(_vector);
		double* bufer = check.GetDateVector(check);
		if (Check_Plus_MatrixAndVector(dateMatrix, bufer))
		{
			for (int i = 0; i < _msize(bufer) / sizeof(double); i++)
			{
				dateMatrix[i] += bufer[i];
			}
		}
		else
		{
			throw "Error";
		}
		return *this;
	}
	/*Vector& Vector::operator+=(const Matrix& _matrix)//��������������� ��������� +=
	{
		Matrix check = (_matrix);
		double* bufer = check.GetDateMatrix(check);
		if (_matrix.Check_Plus_MatrixAndVector(bufer, dateVector))
		{
			for (int i = 0; i < _msize(bufer) / sizeof(double); i++)
			{
				dateVector[i] += bufer[i];
			}
		}
		else
		{
			throw "Error";
		}
		return *this;
	}*/

	Matrix& Matrix::operator-=(const Matrix& _matrix)//��������������� ��������� -=
	{
		Matrix check(_matrix.dateMatrix);
		if (Check_Plus_Matrix(check))
		{
			for (int i = 0; i < _msize(_matrix.dateMatrix) / sizeof(double); i++)
			{
				dateMatrix[i] -= _matrix.dateMatrix[i];
			}
		}
		else
		{
			throw "Error";
		}
		return *this;
	}
	Vector& Vector::operator-=(const Vector& _vector)//��������������� ��������� -=
	{
		Vector check(_vector.dateVector);
		if (Check_Plus_Vector(check))
		{
			for (int i = 0; i < _msize(_vector.dateVector) / sizeof(double); i++)
			{
				dateVector[i] -= _vector.dateVector[i];
			}
		}
		else
		{
			throw "Error";
		}
		return *this;
	}
	Matrix& Matrix::operator-=(const Vector& _vector)//��������������� ��������� +=
	{
		Vector check = (_vector);
		double* bufer = check.GetDateVector(check);
		if (Check_Plus_MatrixAndVector(dateMatrix, bufer))
		{
			for (int i = 0; i < _msize(bufer) / sizeof(double); i++)
			{
				dateMatrix[i] -= bufer[i];
			}
		}
		else
		{
			throw "Error";
		}
		return *this;
	}
	/*Vector& Vector::operator-=(const Matrix& _matrix)//��������������� ��������� +=
	{
		Matrix check = (_matrix);
		double* bufer = check.GetDateMatrix(check);
		if (_matrix.Check_Plus_MatrixAndVector(bufer, dateVector))
		{
			for (int i = 0; i < _msize(bufer) / sizeof(double); i++)
			{
				dateVector[i] -= bufer[i];
			}
		}
		else
		{
			throw "Error";
		}
		return *this;
	}*/

	Matrix& Matrix::operator*=(const Matrix& _matrix)//��������������� ��������� *=
	{
		Matrix check(_matrix.dateMatrix);
		if (Check_Mul_Matrix(check))
		{
			double* newDate = new double[_msize(_matrix.dateMatrix) / sizeof(double)];
			for (int i = 0; i < _msize(_matrix.dateMatrix) / sizeof(double); i++)
			{
				newDate[i] = 0;
				newDate[i] += (dateMatrix[i] * _matrix.dateMatrix[i]);
			}
			delete[] dateMatrix;
			swap(dateMatrix,newDate);
			delete[] newDate;
		}
		else 
		{
			throw "Error";
		}
		return *this;
	}
	Vector& Vector::operator*=(const Vector& _vector)//��������������� ��������� *=
	{
		Vector check(_vector.dateVector);
		if (Check_Mul_Vector(check))
		{
			for (int i = 0; i < _msize(_vector.dateVector) / sizeof(double); i++)
			{
				dateVector[i] *= _vector.dateVector[i];
			}
		}
		else
		{
			throw "Error";
		}
		return *this;
	}
	Matrix& Matrix::operator*=(const Vector& _vector)//��������������� ��������� *=
	{
		Vector check = (_vector);
		double* bufer = check.GetDateVector(check);
		if (Check_Mul_MatrixAndVector(dateMatrix, bufer))
		{
			for (int i = 0; i < _msize(bufer) / sizeof(double); i++)
			{
				dateMatrix[i] *= bufer[i];
			}
		}
		else
		{
			throw "Error";
		}
		return *this;
	}
	/*Vector& Vector::operator*=(const Matrix& _matrix)//��������������� ��������� *=
	{
		Matrix check = (_matrix);
		double* bufer = check.GetDateMatrix(check);
		if (_matrix.Check_Mul_MatrixAndVector(bufer,dateVector))
		{
			for (int i = 0; i < _msize(bufer) / sizeof(double); i++)
			{
				dateVector[i] *= bufer[i];
			}
		}
		else
		{
			throw "Error";
		}
		return *this;
	}*/

	Matrix& Matrix::operator*=(double _scalar)//��������������� ��������� *=
	{
		for (int i = 0; i < _msize(dateMatrix) / sizeof(double); i++)
		{
			dateMatrix[i] *= _scalar;
		}
		return *this;
	}
	Vector& Vector::operator*=(double _scalar)//��������������� ��������� *=
	{
		for (int i = 0; i < _msize(dateVector) / sizeof(double); i++)
		{
			dateVector[i] *= _scalar;
		}
		return *this;
	}






	Matrix operator+(const Matrix& _leftMat, const Matrix& _rightMat)//��������������� ��������� +
	{
		Matrix New(_leftMat);
		New += _rightMat;
		return New;
	}
	Vector operator+(const Vector& _leftVec, const Vector& _rightVec)//��������������� ��������� +
	{
		Vector New(_leftVec);
		New += _rightVec;
		return New;
	}
	Matrix operator+(const Matrix& _leftMat, const Vector& _rightVec)//��������������� ��������� +
	{
		Matrix New(_leftMat);
		New += _rightVec;
		return New;
	}
	Matrix operator+(const Vector& _leftVec,const Matrix& _rightMat)//��������������� ��������� +
	{
		Matrix New(_rightMat);
		New += _leftVec;
		return New;
	}

	Matrix operator-(const Matrix& _leftMat, const Matrix& _rightMat)//��������������� ��������� -
	{
		Matrix New(_leftMat);
		New -= _rightMat;
		return New;
	}
	Vector operator-(const Vector& _leftVec, const Vector& _rightVec)//��������������� ��������� -
	{
		Vector New(_leftVec);
		New -= _rightVec;
		return New;
	}
	Matrix operator-(const Matrix& _leftMat, const Vector& _rightVec)//��������������� ��������� -
	{
		Matrix New(_leftMat);
		New -= _rightVec;
		return New;
	}
	Matrix operator-(const Vector& _leftVec, const Matrix& _rightMat)//��������������� ��������� -
	{
		Matrix New(_rightMat);
		New -= _leftVec;
		return New;
	}

	Matrix operator*(const Matrix& _leftMat, const Matrix& _rightMat)//��������������� ��������� *
	{
		Matrix New(_leftMat);
		New *= _rightMat;
		return New;
	}
	Vector operator*(const Vector& _leftVec, const Vector& _rightVec)//��������������� ��������� -
	{
		Vector New(_leftVec);
		New *= _rightVec;
		return New;
	}
	Matrix operator*(const Matrix& _leftMat, const Vector& _rightVec)//��������������� ��������� -
	{
		Matrix New(_leftMat);
		New *= _rightVec;
		return New;
	}
	Matrix operator*(const Vector& _leftVec, const Matrix& _rightMat)//��������������� ��������� -
	{
		Matrix New(_rightMat);
		New *= _leftVec;
		return New;
	}

	Matrix operator*(const Matrix& _leftMat, double _scalar)//��������������� ��������� * �� ������
	{
		Matrix New(_leftMat);
		New *= _scalar;
		return New;
	}
	Vector operator*(const Vector& _leftVec, double _scalar)//��������������� ��������� * �� ������
	{
		Vector New(_leftVec);
		New *= _scalar;
		return New;
	}
}