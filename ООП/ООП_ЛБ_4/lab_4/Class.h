#include <iostream>

namespace lab_4 
{
	using namespace std;
	class Drob
	{
    private: 
        int Whole;//Целая часть
        int Numerator;//Числитель
        int Denominator;//Знаменатель
		void AutoReduction();//Автоматическое сокращение дроби
	public:
		Drob(int _Numerator, int _Denominator);//Конструктор без целой части
        Drob(int _Whole, int _Numerator, int _Denominator);//Конструктор с целой частью
        Drob(const Drob& _drob);
        ~Drob();//Деструктор

		int getNumerator();
		int getDenominator();
		void setNumerator(int _Numerator);
		void setDenominator(int _Denominator);

        Drob& operator=(Drob&& _drob);
        Drob& operator+=(const Drob& _drob);
        Drob& operator-=(const Drob& _drob);
        Drob& operator*=(const Drob& _drob);
        Drob& operator/=(const Drob& _drob);

		void Decomposition();//Декомпозиция

		friend ostream& operator<< (ostream& out, const Drob& PrintDrob);
	};

//**************************************************************************************************************************************************************************************************************
    //Полинооомы
    class Polynom {
    private:
        unsigned int Degree; //Cтепень полинома
        double* Coefficient; //Указатель на массив коэффициентов полинома
        void CorrectDegree(); //Корректировка степени полинома
    public:
        Polynom(); //Конструктор по умолчанию
        Polynom(unsigned int, const double* new_сoef);//Конструктор с параметрами
        Polynom(const Polynom&); //Конструктор копирования
        ~Polynom(); //Деструктор

        unsigned int GetDegree() const;
        double GetCoefficient(unsigned int) const;
        unsigned int SetDegree() const;
        unsigned int SetCoefficient(double, unsigned int);



        Polynom& operator = (Polynom&& _pol);
        Polynom& operator += (const Polynom& _pol);
        Polynom& operator -= (const Polynom& _pol);
        Polynom& operator *= (const Polynom& _pol);
        Polynom& operator /(Polynom& _pol);

		friend ostream& operator<< (ostream& out, const Polynom& Pol);

        Polynom& operator()(const Polynom& value);
    };
    Drob operator+(const Drob& _leftDrob, const Drob& _rightDrob);
    Drob operator-(const Drob& _leftDrob, const Drob& _rightDrob);
    Drob operator-(const Drob& _leftDrob, const Drob& _rightDrob);
    Drob operator-(const Drob& _leftDrob, const Drob& _rightDrob);

    Polynom operator+(const Polynom& _leftPol, const Polynom& _rightPol);
    Polynom operator-(const Polynom& _leftPol, const Polynom& _rightPol);
    Polynom operator*(const Polynom& _leftPol, const Polynom& _rightPol);
    Polynom operator*(double K, Polynom& t);
};

