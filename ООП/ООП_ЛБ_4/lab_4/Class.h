#include <iostream>

namespace lab_4 
{
	using namespace std;
	class Drob
	{
    private: 
        int Whole;//����� �����
        int Numerator;//���������
        int Denominator;//�����������
		void AutoReduction();//�������������� ���������� �����
	public:
		Drob(int _Numerator, int _Denominator);//����������� ��� ����� �����
        Drob(int _Whole, int _Numerator, int _Denominator);//����������� � ����� ������
        Drob(const Drob& _drob);
        ~Drob();//����������

		int getNumerator();
		int getDenominator();
		void setNumerator(int _Numerator);
		void setDenominator(int _Denominator);

        Drob& operator=(Drob&& _drob);
        Drob& operator+=(const Drob& _drob);
        Drob& operator-=(const Drob& _drob);
        Drob& operator*=(const Drob& _drob);
        Drob& operator/=(const Drob& _drob);

		void Decomposition();//������������

		friend ostream& operator<< (ostream& out, const Drob& PrintDrob);
	};

//**************************************************************************************************************************************************************************************************************
    //����������
    class Polynom {
    private:
        unsigned int Degree; //C������ ��������
        double* Coefficient; //��������� �� ������ ������������� ��������
        void CorrectDegree(); //������������� ������� ��������
    public:
        Polynom(); //����������� �� ���������
        Polynom(unsigned int, const double* new_�oef);//����������� � �����������
        Polynom(const Polynom&); //����������� �����������
        ~Polynom(); //����������

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

