#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

namespace cl
{
	//��������������� ��������� []
	class DopClass
	{
	public:
		double* line;//������ �����
		int maxColumns;//�������� ��������
		double operator[](int _index)
		{
			return line[_index];
		}
	};

	template <class  T> class Matrix
	{
	private:
		unsigned int lines;//������
		unsigned int columns;//�������
		T* date;//����������
		const int id;
		static int countMatrix;
	public:
		int countMatrix = 0;
		Matrix() :id{ countMatrix++ }//�� ���������
		{
			cout << "++����������� 1++" << endl;
			lines = 0;
			columns = 0;
			date = NULL;
			cout << "++             ++" << endl;
		}
		Matrix(unsigned int _lines, unsigned int _columns, T* _info) :id{ countMatrix++ }//������������� ���������� ��� ������������� �������
		{
			cout << "++����������� 2++" << endl;
			lines = _lines;
			columns = _columns;
			date = new T[lines * columns];
			for (int i = 0; i < lines; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					date[i * columns + j] = _info[i * j + j];
					cout << date[i * columns + j]<<" ";
				}
				cout << endl;
			}
			cout << "++             ++" << endl;
		}

		Matrix(const Matrix& _matrix) :id{ countMatrix++ }//�����������
		{
			cout << "++����������� 3++" << endl;
			lines = _matrix.lines;
			columns = _matrix.columns;

			date = new T[lines * columns];
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
		Matrix(Matrix&& _matrix) :id{ countMatrix++ }//����������� �����������
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
		~Matrix()//����������
		{
			cout << "++����������++" << endl;
			lines = 0;
			columns = 0;
			delete[] date;
			cout << "++          ++" << endl;
		}

		unsigned int get_Lines()const//����� ��������� ���. �����
		{
			return this->lines;
		}
		unsigned int get_Columns()const//����� ��������� ���. ��������
		{
			return this->columns;
		}

		void set_Lines(unsigned int _lines)//����� ����� �����
		{
			lines = _lines;
		}
		void set_Columns(unsigned int _columns)//����� ����� ��������
		{
			columns = _columns;
		}

		bool Check_Mul(Matrix& _matrix)const //����� �������� ����������� ��������� ���� ������
		{
			return (columns == _matrix.get_Lines());
		}
		bool Check_Plus(Matrix& _matrix)const//����� �������� ����������� �������� ���� ������
		{
			return (columns == _matrix.get_Columns()) && (lines == _matrix.get_Lines());
		}

		T Max_Matrix()const//����� ������ ������������� ��������
		{
			T max = 0;
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
		T Min_Matrix()const//����� ������ ������������ ��������
		{
			T min = Max_Matrix();
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
		DopClass operator[](int _index)
		{
			DopClass mat;
			mat.line = &date[_index * columns];
			mat.maxColumns = columns;
			return mat;
		}

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

		Matrix& operator=(const Matrix& _mat)//��������������� ��������� =
		{
			delete[] date;
			Matrix buf(_mat.lines, _mat.columns, _mat.date);
			return buf;
		}
		Matrix& operator=(Matrix&& _mat)
		{
			swap(lines, _mat.lines);
			swap(columns, _mat.columns);
			swap(date, _mat.date);

			return *this;
		}
		Matrix& operator+=(const Matrix& _mat)//��������������� ��������� +=
		{
			Matrix check(_mat.lines, _mat.columns, _mat.date);
			if (Check_Plus(check))
			{
				for (int i = 0; i < lines; i++)
				{
					for (int j = 0; j < columns; j++)
					{
						date[i * columns + j] += _mat.date[i * columns + j];
					}
				}
			}
			else
			{
				throw "Error";
			}
			return *this;
		}
		Matrix& operator-=(const Matrix& _mat)//��������������� ��������� -=
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
		Matrix& operator*=(const Matrix& _mat)//��������������� ��������� *=
		{
			Matrix check(_mat.lines, _mat.columns, _mat.date);
			if (Check_Mul(check))
			{
				T* newDate = new T[lines * columns];
				for (int i = 0; i < lines; i++)
				{
					for (int j = 0; j < _mat.get_Columns(); j++)
					{
						newDate[i * columns + j] = 0;
						for (int k = 0; k < columns; k++)
						{
							newDate[i * columns + j] += (date[i * columns + k] * _mat.date[k * columns + j]);
						}
					}
				}
				delete[] date;
				swap(date, newDate);
				delete[] newDate;
			}
			else
			{
				throw "Error";
			}
			return *this;
		}
		Matrix& operator*=(T _scalar)//��������������� ��������� *=
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
		Matrix operator*(const Matrix& _leftMat, T _scalar)//��������������� ��������� * �� ������
		{
			Matrix New(_leftMat);
			New *= _scalar;
			return New;
		}
	};
}