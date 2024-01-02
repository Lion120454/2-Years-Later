#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

namespace cl
{
	//Переопределение оператора []
	class DopClass
	{
	public:
		double* line;//Массив строк
		int maxColumns;//Максимум столбцов
		double operator[](int _index)
		{
			return line[_index];
		}
	};

	template <class  T> class Matrix
	{
	private:
		unsigned int lines;//Строки
		unsigned int columns;//Столбцы
		T* date;//Информация
		const int id;
		static int countMatrix;
	public:
		int countMatrix = 0;
		Matrix() :id{ countMatrix++ }//по умолчанию
		{
			cout << "++Конструктор 1++" << endl;
			lines = 0;
			columns = 0;
			date = NULL;
			cout << "++             ++" << endl;
		}
		Matrix(unsigned int _lines, unsigned int _columns, T* _info) :id{ countMatrix++ }//Инициализация квадратной или прямоугольной матрици
		{
			cout << "++Конструктор 2++" << endl;
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

		Matrix(const Matrix& _matrix) :id{ countMatrix++ }//Копирование
		{
			cout << "++Конструктор 3++" << endl;
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
		Matrix(Matrix&& _matrix) :id{ countMatrix++ }//Конструктор перемещения
		{
			cout << "++Конструктор 3++" << endl;
			lines = _matrix.lines;
			columns = _matrix.columns;
			date = _matrix.date;

			_matrix.date = nullptr;
			_matrix.lines = 0;
			_matrix.columns = 0;
			cout << "++             ++" << endl;
			cout << *this;
		}
		~Matrix()//Деструктор
		{
			cout << "++Деструктор++" << endl;
			lines = 0;
			columns = 0;
			delete[] date;
			cout << "++          ++" << endl;
		}

		unsigned int get_Lines()const//Метод получения кол. строк
		{
			return this->lines;
		}
		unsigned int get_Columns()const//Метод получения кол. столбцов
		{
			return this->columns;
		}

		void set_Lines(unsigned int _lines)//Метод ввода строк
		{
			lines = _lines;
		}
		void set_Columns(unsigned int _columns)//Мотод ввода столбцов
		{
			columns = _columns;
		}

		bool Check_Mul(Matrix& _matrix)const //Метод проверки возможности умножения двух матриц
		{
			return (columns == _matrix.get_Lines());
		}
		bool Check_Plus(Matrix& _matrix)const//Метод проверки возможности сложения двух матриц
		{
			return (columns == _matrix.get_Columns()) && (lines == _matrix.get_Lines());
		}

		T Max_Matrix()const//Метод поиска максимального элемента
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
		T Min_Matrix()const//Метод поиска минимального элемента
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
		
		//Переопределение оператора[]
		DopClass operator[](int _index)
		{
			DopClass mat;
			mat.line = &date[_index * columns];
			mat.maxColumns = columns;
			return mat;
		}

		ostream& operator<<(ostream& os, const Matrix& _mat)//Переопределение оператора <<
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

		Matrix& operator=(const Matrix& _mat)//Переопределение оператора =
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
		Matrix& operator+=(const Matrix& _mat)//Переопределение оператора +=
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
		Matrix& operator-=(const Matrix& _mat)//Переопределение оператора -=
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
		Matrix& operator*=(const Matrix& _mat)//Переопределение оператора *=
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
		Matrix& operator*=(T _scalar)//Переопределение оператора *=
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

		Matrix operator+(const Matrix& _leftMat, const Matrix& _rightMat)//Переопределение оператора +
		{
			Matrix New(_leftMat);
			New += _rightMat;
			return New;
		}
		Matrix operator-(const Matrix& _leftMat, const Matrix& _rightMat)//Переопределение оператора -
		{
			Matrix New(_leftMat);
			New -= _rightMat;
			return New;
		}
		Matrix operator*(const Matrix& _leftMat, const Matrix& _rightMat)//Переопределение оператора *
		{
			Matrix New(_leftMat);
			New *= _rightMat;
			return New;
		}
		Matrix operator*(const Matrix& _leftMat, T _scalar)//Переопределение оператора * на скаляр
		{
			Matrix New(_leftMat);
			New *= _scalar;
			return New;
		}
	};
}