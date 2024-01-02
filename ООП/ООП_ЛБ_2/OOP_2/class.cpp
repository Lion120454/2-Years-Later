#include <iostream>
#include <cmath>
#include <iomanip>
#include "class.h"

using namespace std;

namespace cl
{
	int Matrix::countMatrix = 0;
	Matrix::Matrix() :id{ countMatrix++ }//�� ���������
	{
		cout << "++����������� 1++" << endl;
		�reate_Matrix(2, 2, NULL);
		cout << "++             ++" << endl;
	}
	Matrix::Matrix(unsigned int _lines, unsigned int _columns, double* _info) :id{ countMatrix++ }//������������� ���������� ��� ������������� �������
	{
		cout << "++����������� 2++" << endl;
		�reate_Matrix(_lines, _columns, _info);
		cout << "++             ++" << endl;
	}

	Matrix::Matrix(const Matrix& _matrix) :id{ countMatrix++ }//�����������
	{
		cout << "++����������� 3++" << endl;
		lines = _matrix.lines;
		columns = _matrix.columns;

		date = new double[lines * columns];
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				date[i * columns + j] = _matrix.date[i * columns + j];
				cout << "   " << date[i * columns + j];
			}
			cout << endl;
		}
		cout << "++             ++" << endl;
	}
	Matrix::Matrix(Matrix&& _matrix) :id{ countMatrix++ }//����������� �����������
	{
		cout << "++����������� 3++" << endl;
		lines = _matrix.lines;
		columns = _matrix.columns;
		date = _matrix.date;

		_matrix.date = nullptr;
		_matrix.lines = 0;
		_matrix.columns = 0;
		cout << "++             ++" << endl;
		cout << *this;
	}
	Matrix::~Matrix()//����������
	{
		cout << "++����������++" << endl;
		lines = 0;
		columns = 0;
		delete[] date;
		cout << "++          ++" << endl;
	}
	void Matrix::�reate_Matrix(unsigned int _columns, unsigned int _lines, double* _info)//����� �������� �������
	{
		lines = _lines;
		columns = _columns;
		date = new double[lines * columns];
		if (_info == NULL)//��� �������� ������� �� ���������
		{
			for (int i = 0; i < lines; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					date[i * columns + j] = j + 1;
				}
				cout << endl;
			}
			cout << endl;
		}
		else//��� �������� ������� � �����������
		{
			for (int i = 0; i < lines; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					date[i * columns + j] = _info[i * j + j];
				}
				cout << endl;
			}
		}
	}

	int Matrix::get_Lines()const//����� ��������� ���. �����
	{
		return this->lines;
	}
	int Matrix::get_Columns()const//����� ��������� ���. ��������
	{
		return this->columns;
	}

	void Matrix::set_Lines(int _lines)//����� ����� �����
	{
		lines = _lines;
	}
	void Matrix::set_Columns(int _columns)//����� ����� ��������
	{
		columns = _columns;
	}

	bool Matrix::Check_Mul(Matrix& _matrix)const //����� �������� ����������� ��������� ���� ������
	{
		return (columns == _matrix.get_Lines());
	}

	bool Matrix::Check_Plus(Matrix& _matrix)const//����� �������� ����������� �������� ���� ������
	{
		return (columns == _matrix.get_Columns()) && (lines == _matrix.get_Lines());
	}
	double Matrix::Max_Matrix()const//����� ������ ������������� ��������
	{
		double max = 0;
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (max < date[i * columns + j])
				{
					max = date[i * columns + j];
				}
			}
		}
		return max;
	}
	double Matrix::Min_Matrix()const//����� ������ ������������ ��������
	{
		double min = Max_Matrix();
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (min > date[i * columns + j])
				{
					min = date[i * columns + j];
				}
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
		mat.line = &date[_index*columns];
		mat.maxColumns = columns;
		return mat;
	}
	//��������������� ���������[]

	ostream& operator<<(ostream& os, const Matrix& _mat)//��������������� ��������� <<
	{
		for (int i = 0; i < _mat.lines; i++)
		{
			os << endl;
			for (int j = 0; j < _mat.columns; j++)
			{
				os << " " << _mat.date[i * _mat.columns + j];
			}
		}
		os << endl;
		return os;
	}

	Matrix& Matrix::operator=(const Matrix& _mat)//��������������� ��������� =
	{
		delete[] date;
		�reate_Matrix(_mat.lines, _mat.columns, _mat.date);
		return *this;
	}

	Matrix& Matrix::operator=(Matrix&& _mat)
	{
		swap(lines, _mat.lines);
		swap(columns, _mat.columns);
		swap(date,_mat.date);
		
		return *this;
	}

	Matrix& Matrix::operator+=(const Matrix& _mat)//��������������� ��������� +=
	{
		Matrix check(_mat.lines, _mat.columns, _mat.date);
		if (Check_Plus(check))
		{
			for (int i = 0; i < lines; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					date[i * columns + j] += _mat.date[i*columns+j];
				}
			}
		}
		else
		{
			throw "Error";
		}
		return *this;
	}

	Matrix& Matrix::operator-=(const Matrix& _mat)//��������������� ��������� -=
	{
		Matrix check(_mat.lines, _mat.columns, _mat.date);
		if (Check_Plus(check))
		{
			for (int i = 0; i < lines; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					date[i * columns + j] -= _mat.date[i * columns + j];
				}
			}
		}
		else
		{
			throw "Error";
		}
		return *this;
	}

	Matrix& Matrix::operator*=(const Matrix& _mat)//��������������� ��������� *=
	{
		Matrix check(_mat.lines, _mat.columns, _mat.date);
		if (Check_Mul(check))
		{
			double* newDate = new double[lines * columns];
			for (int i = 0; i < lines; i++)
			{
				for (int j = 0; j < _mat.get_Columns(); j++)
				{
					newDate[i * columns + j] = 0;
					for (int k = 0; k < columns; k++)
					{
						newDate[i * columns + j] += (date[i * columns + k] * _mat.date[k*columns+j]);
					}
				}
			}
			delete[] date;
			swap(date,newDate);
			delete[] newDate;
		}
		else 
		{
			throw "Error";
		}
		return *this;
	}

	Matrix& Matrix::operator*=(double _scalar)//��������������� ��������� *=
	{
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				date[i * columns + j] *= _scalar;
			}
		}
		return *this;
	}

	Matrix operator+(const Matrix& _leftMat, const Matrix& _rightMat)//��������������� ��������� +
	{
		Matrix New(_leftMat);
		New += _rightMat;
		return New;
	}

	Matrix operator-(const Matrix& _leftMat, const Matrix& _rightMat)//��������������� ��������� -
	{
		Matrix New(_leftMat);
		New -= _rightMat;
		return New;
	}

	Matrix operator*(const Matrix& _leftMat, const Matrix& _rightMat)//��������������� ��������� *
	{
		Matrix New(_leftMat);
		New *= _rightMat;
		return New;
	}

	Matrix operator*(const Matrix& _leftMat, double _scalar)//��������������� ��������� * �� ������
	{
		Matrix New(_leftMat);
		New *= _scalar;
		return New;
	}
}