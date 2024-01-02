#include "Class.h"

using namespace lab_4;
using namespace std;

int main()
{
	try
	{
		Drob A1(2, 5);
		Drob A2(3, 7);
		cout << A1 << endl;
		cout << A2 << endl;
		A1 /= A2;
		cout << A1 << endl;

		double Data[11];
		for (int i = 0; i <= 10; i++) 
		{
			if (i < 6)
			{
				Data[i] = i * 2;
			}
			else
			{
				Data[i] = 0;
			}
		}
		Data[2] = 0;
		Polynom Pol1(10, Data);
		cout << Pol1 << endl;
		return 0;
	}
	catch (const char* error_message)
	{
		cout << error_message << std::endl;
		exit(-1);

	}
}