#include "Class.h"
#include <iostream>

using namespace std;

namespace lab_4
{
	Drob::Drob(int _numerator, int _denominator)//Конструктор без целой части
	{
		Numerator = _numerator;
		Whole = 0;
        if (_denominator != 0) 
        {
            Denominator = _denominator;
        }
        else
        {
            throw "Division by zero! Denominator cannot be equal zero! Stupid user!!!";
        }
		AutoReduction();
	}
    Drob::Drob(int _whole,int _numerator, int _denominator)//Конструктор с целой частью
    {
        Numerator = _numerator;
        Whole = _whole;
        if (_denominator != 0)
        {
            Denominator = _denominator;
        }
        else
        {
            throw "Division by zero! Denominator cannot be equal zero! Stupid user!!!";
        }
        AutoReduction();
    }
    Drob::Drob(const Drob& _drob)
    {
        Whole = _drob.Whole;
        Numerator = _drob.Numerator;
        Denominator = _drob.Denominator;
    }
	Drob::~Drob()
	{
		Numerator = 0;
		Denominator = 0;
	}

	int Drob::getNumerator() 
    {
		return(Numerator);
	}
	int Drob::getDenominator() 
    {
		return(Denominator);
	}

	void Drob::setNumerator(int _A) 
    {
		Numerator = _A;
	}
	void Drob::setDenominator(int _B) 
    {
		Denominator = _B;
	}

    Drob& Drob::operator=(Drob&& _drob)
    {
        swap(Whole, _drob.Whole);
        swap(Numerator, _drob.Numerator);
        swap(Denominator, _drob.Denominator);
        return *this;
    }
    Drob& Drob::operator+=(const Drob& _drob)
    {
        Drob buf(_drob.Whole,_drob.Numerator, _drob.Denominator);
        if (Whole != 0)
        {
            Numerator = (Whole * Denominator) + Numerator;
        }
        if (_drob.Whole != 0)
        {
            buf.Numerator = (buf.Whole * buf.Denominator) + buf.Numerator;
        }
        Denominator *= buf.Denominator;
        Numerator = (Numerator* buf.Denominator) + (Denominator* buf.Numerator);
        AutoReduction();
        return *this;
    }
    Drob& Drob::operator-=(const Drob& _drob)
    {
        Drob buf(_drob.Whole, _drob.Numerator, _drob.Denominator);
        if (Whole != 0)
        {
            Numerator = Whole * Denominator + Numerator;
        }
        if (_drob.Whole != 0)
        {
            buf.Numerator = buf.Whole * buf.Denominator + buf.Numerator;
        }
        Denominator *= buf.Denominator;
        Numerator = (Numerator * buf.Denominator) - (Denominator * buf.Numerator);
        AutoReduction();
        return *this;
    }
    Drob& Drob::operator*=(const Drob& _drob)
    {
        Drob buf(_drob.Whole, _drob.Numerator, _drob.Denominator);
        if (Whole != 0)
        {
            Numerator = Whole * Denominator + Numerator;
        }
        if (_drob.Whole != 0)
        {
            buf.Numerator = buf.Whole * buf.Denominator + buf.Numerator;
        }
        Numerator *= buf.Numerator;
        Denominator *= buf.Denominator;
        AutoReduction();
        return *this;
    }
    Drob& Drob::operator/=(const Drob& _drob)
    {
        Drob buf(_drob.Whole, _drob.Numerator, _drob.Denominator);
        if (Whole != 0)
        {
            Numerator = Whole * Denominator + Numerator;
        }
        if (_drob.Whole != 0)
        {
            buf.Numerator = buf.Whole * buf.Denominator + buf.Numerator;
        }
        swap(buf.Numerator, buf.Denominator);
        Numerator *= buf.Numerator;
        Denominator *= buf.Denominator;
        AutoReduction();
        return *this;
    }

    Drob operator+(const Drob& _leftDrob, const Drob& _rightDrob)
    {
        Drob New(_leftDrob);
        New += _rightDrob;
        return New;
    }
    Drob operator-(const Drob& _leftDrob, const Drob& _rightDrob)
    {
        Drob New(_leftDrob);
        New -= _rightDrob;
        return New;
    }
    Drob operator*(const Drob& _leftDrob, const Drob& _rightDrob)
    {
        Drob New(_leftDrob);
        New *= _rightDrob;
        return New;
    }
    Drob operator/(const Drob& _leftDrob, const Drob& _rightDrob)
    {
        Drob New(_leftDrob);
        New /= _rightDrob;
        return New;
    }

    ostream& operator<< (ostream& os, const Drob& _drob)
    {
        if ((_drob.Denominator == NULL) && (_drob.Numerator == NULL))
        {
            os << _drob.Whole;
        }
        else
        {
            os << "  " << _drob.Numerator << endl;
            os << _drob.Whole << "---"<<endl;
            os << "  " << _drob.Denominator<<endl;
        }
        return os;
    }

	void Drob::AutoReduction() {
		if ((Numerator % Denominator) == 0) 
        { 
            Numerator = Numerator / Denominator; Denominator = 1;  return; 
        }
		for (int i = 2; i <= (Denominator / 2); i++) 
        {
			while ((Denominator % i == 0) && (Numerator % i == 0)) 
            {
				Denominator = Denominator / i;
				Numerator = Numerator / i;

			}
		}

	}
	void Drob::Decomposition() {
		if (Numerator - Denominator >= 0) 
        {
			if (Numerator % Denominator == 0) 
            {
                Whole = Numerator / Denominator; Denominator = NULL;  Numerator = NULL; return; 
            }
			Whole = Numerator / Denominator;
			Numerator = Numerator - Denominator * Whole;
		}


	}

//**********************************************************************************************************************************
   
    Polynom::Polynom(): Polynom(0, new double[Degree + 1]) 
    {
        Coefficient[0] = 0.0;
    }
    Polynom::Polynom(unsigned int new_degree, const double* new_сoef) 
    {
        Degree = 0;
        for (int i = 0; i <= new_degree; i++) 
        {
            if (new_сoef[i] != 0) Degree = i;

        }
        Coefficient = new double[Degree + 1];
        for (int i = 0; i <= Degree; i++) 
        {
            Coefficient[i] = new_сoef[i];
        }
    }
    Polynom::Polynom(const Polynom& f) 
    {
        Degree = f.Degree;
        Coefficient = new double[Degree + 1];
        for (int i = 0; i <= Degree; i++) 
        {
            Coefficient[i] = f.Coefficient[i];
        }
    }
    Polynom::~Polynom() {
        delete[] Coefficient;
    }
    
    unsigned int Polynom::GetDegree() const{
        return Degree;
    }
    double Polynom::GetCoefficient(unsigned int i) const{
        if (i <= Degree)
            return Coefficient[i];
        else
            return 0.0;
    }
    unsigned int Polynom::SetCoefficient(double new_сoef, unsigned int i){
        if (i <= Degree) Coefficient[i] = new_сoef;
        else return Degree;
        CorrectDegree();
        return Degree;
    }

    Polynom& Polynom::operator = (Polynom&& _pol)
    {
        Degree = _pol.Degree;
        delete[] Coefficient;
        Coefficient = new double[Degree + 1];
        for (int i = 0; i <= Degree; i++) 
        {
            Coefficient[i] = _pol.Coefficient[i];
        }
        return *this;
    }
    Polynom& Polynom::operator += (const Polynom& _pol)
    {
        int i;
        Polynom* result;
        if (Degree >= _pol.Degree)
        {
            result = new Polynom(Degree, Coefficient);
            for (i = 0; i <= _pol.Degree; i++)
            {
                result->Coefficient[i] = result->Coefficient[i] + _pol.Coefficient[i];
            }
        }
        else 
        {
            result = new Polynom(_pol.Degree, _pol.Coefficient);
            for (i = 0; i <= Degree; i++) 
            {
                result->Coefficient[i] = result->Coefficient[i] + Coefficient[i];
            }
        }
        result->CorrectDegree();
        return *result;
    }
    Polynom& Polynom::operator -= (const Polynom& _pol)
    {
        int i;
        Polynom* result;
        if (Degree >= _pol.Degree)
        {
            result = new Polynom(Degree, Coefficient);
            for (i = 0; i <= _pol.Degree; i++)
            {
                result->Coefficient[i] = result->Coefficient[i] - _pol.Coefficient[i];
            }
        }
        else
        {
            result = new Polynom(_pol.Degree, _pol.Coefficient);
            for (i = 0; i <= Degree; i++)
            {
                result->Coefficient[i] = result->Coefficient[i] - Coefficient[i];
            }
        }
        result->CorrectDegree();
        return *result;
    }
    Polynom& Polynom::operator *= (const Polynom& _pol)
    {
        int i;
        Polynom* result;
        if (Degree >= _pol.Degree)
        {
            result = new Polynom(Degree, Coefficient);
            for (i = 0; i <= _pol.Degree; i++)
            {
                result->Coefficient[i] = result->Coefficient[i] * _pol.Coefficient[i];
            }
        }
        else
        {
            result = new Polynom(_pol.Degree, _pol.Coefficient);
            for (i = 0; i <= Degree; i++)
            {
                result->Coefficient[i] = result->Coefficient[i] * Coefficient[i];
            }
        }
        result->CorrectDegree();
        return *result;
    }
    Polynom& Polynom::operator /(Polynom& _pol)
    {
        Polynom temp;
        Polynom ob_1;
        Polynom ob_2;
        Polynom ob_4;

        temp.Degree = Degree - _pol.Degree;
        temp.Coefficient = new double[temp.Degree + 1];
        memset(temp.Coefficient, 0, (temp.Degree + 1) * sizeof(double));

        ob_1.Degree = Degree;
        ob_1.Coefficient = new double[Degree + 1];
        for (int i = Degree; i >= 0; i--)
            ob_1.Coefficient[i] = Coefficient[i];


        ob_2.Degree = _pol.Degree;
        ob_2.Coefficient = new double[_pol.Degree + 1];
        for (int i = _pol.Degree; i >= 0; i--)
            ob_2.Coefficient[i] = _pol.Coefficient[i];

        ob_4.Degree = _pol.Degree;
        ob_4.Coefficient = new double[ob_1.Degree + 1];

        int u = 0;
        int j = 0;
        int k = ob_1.Degree;
        while (u == 0)
        {
            if (ob_1.Degree >= ob_2.Degree)
            {
                j = ob_2.Degree;
                for (int i = ob_1.Degree; i >= 0; i--)
                {
                    if (j >= 0)
                    {
                        ob_4.Coefficient[i] = ob_2.Coefficient[j];
                        j--;
                    }
                    else ob_4.Coefficient[i] = 0;
                }
                for (int i = 0; i <= ob_1.Degree; i++) 
                {
                    ob_4.Coefficient[i] *= ob_1.Coefficient[k];
                }
                temp.Coefficient[ob_1.Degree - 1] = ob_1.Coefficient[k];
                for (int i = 0; i <= ob_1.Degree; i++) 
                {
                    ob_1.Coefficient[i] -= ob_4.Coefficient[i];
                }
            }
            else 
            { 
                u = 1;
            }
            k--;
            ob_1.Degree--;
        }
        return temp;
    }

    Polynom operator+(const Polynom& _leftPol, const Polynom& _rightPol)
    {
        Polynom New(_leftPol);
        New += _rightPol;
        return New;
    }
    Polynom operator-(const Polynom& _leftPol, const Polynom& _rightPol)
    {
        Polynom New(_leftPol);
        New -= _rightPol;
        return New;
    }
    Polynom operator*(const Polynom& _leftPol, const Polynom& _rightPol)
    {
        Polynom New(_leftPol);
        New *= _rightPol;
        return New;
    }
    Polynom operator*(double _scalar, const Polynom& _pol)
    {
        if (_scalar == 0) 
        {
            Polynom result;
            return result;
        }
        int degree = _pol.GetDegree();
        double* tmp_сoef = new double[degree + 1];
        for (int i = 0; i <= degree; i++) 
        {
            tmp_сoef[i] = _scalar * _pol.GetCoefficient(i);
        }
        Polynom result(degree, tmp_сoef);
        delete[] tmp_сoef;
        return result;
    }

    void Polynom::CorrectDegree() 
    {
        if (Coefficient[Degree] == 0) 
        {
            do 
            {
                Degree--;
            } while (Degree && Coefficient[Degree] == 0);
        }
    }

    Polynom& Polynom::operator()(const Polynom& value)
    {
        Polynom thisValue;
        Polynom result;
        for (size_t i = 0; i < 10; ++i) 
        {
            result += Coefficient[i]*thisValue;
            thisValue *= value;
        }
        return result;
    }
    ostream& operator<< (ostream& out, const Polynom& Pol)
    {
        Pol.GetCoefficient(Pol.GetDegree());
        if (Pol.GetCoefficient(Pol.GetDegree()) == 1)
            out << "X^" << Pol.GetDegree();
        else if (Pol.GetCoefficient(Pol.GetDegree()) == -1)
            out << "-X^" << Pol.GetDegree();
        else
            out << Pol.GetCoefficient(Pol.GetDegree()) << "X^" << Pol.GetDegree();

        for (int i = Pol.GetDegree() - 1; i > 0; i--) {
            if (Pol.GetCoefficient(i) > 0) {
                if (Pol.GetCoefficient(i) == 1)
                    out << " + " << "X^" << i;
                else
                    out << " + " << Pol.GetCoefficient(i) << "X^" << i;
            }
            else if (Pol.GetCoefficient(i) < 0)
                if (Pol.GetCoefficient(i) == -1)
                    out << " - " << "X^" << i;
                else
                    out << " - " << (-1) * Pol.GetCoefficient(i) << "X^" << i;
        }

        if (Pol.GetCoefficient(0) > 0)
            cout << " + " << Pol.GetCoefficient(0);
        else if (Pol.GetCoefficient(0) < 0) cout << " - " << (-1) * Pol.GetCoefficient(0);
        
        return out;
    }
}