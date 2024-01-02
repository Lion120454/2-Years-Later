#include "locale.h"
#include "iostream"
#include "cmath"
#include "class.h"
using namespace std;
using namespace cl;


int main()
{
	setlocale(LC_ALL, "Ru");
	//m=lines
	//n=columns
	int m = 4, n = 5;
	int* arrInt = new int[n * m];
	double* arrDouble = new double[n * m];
	short* arrShort = new short[n * m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arrInt[i * m + j] = (rand() % 10 + 1);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arrDouble[i * m + j] = (rand() % 10 + 1)*0.2;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arrShort[i * m + j] = (rand() % 17 + 5);
		}
	}
	cout << "---INT---" << endl;
	Matrix<int> matInt(n, m, arrInt);
	cout << "---DOUBLE---" << endl;
	Matrix<double> matDouble(n, m, arrDouble);
	cout << "---SHORT---" << endl;
	Matrix<short> matShort(n, m, arrShort);
	
	return 0;
}