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
	double* arr = new double[n * m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i * m + j] = (rand() % 10 + 1) * 0.2;
		}
	}

	Matrix mat1(n, m, arr);

	arr = new double[n * m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i * m + j] = (rand() % 10 + 1) * 0.2;
		}
	}

	Matrix mat2(n, m, arr);
	Matrix mat3(mat1);


	cout << "------------------------------------------------------------" << endl;
	double max = mat2.Max_Matrix();
	cout << "Mat2 Max= " << max << endl;
	cout << "------------------------------------------------------------" << endl;
	double min = mat3.Min_Matrix();
	cout << "Mat3 Min= " << min << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "mat2[0][3]=" << mat2[0][3] << endl;
	cout << "mat2[1][3]=" << mat2[1][3] << endl;
	cout << "mat2[2][3]=" << mat2[2][3] << endl;
	cout << "mat2[3][3]=" << mat2[3][3] << endl;
	cout << "------------------------------------------------------------" << endl;
	mat3 = mat2;
	cout << "mat3=" << mat3 << endl;

	mat1 += mat2;
	cout << "mat1+=" << mat1 << endl;

	mat2 -= mat3;
	cout << "mat2-=" << mat2 << endl;

	mat3 *= mat3;
	cout << "mat3*= scalar" << mat3 << endl;

	mat1 *= 5;
	cout << "mat1*=" << mat1 << endl;
	cout << "------------------------------------------------------------" << endl;
	mat3 = mat1 + mat2;
	cout << "mat1 + mat2="  <<mat3<< endl;
	mat3 = mat1 - mat2;
	cout << "mat1 - mat2=" << mat3 << endl;
	mat3 = mat1 * mat2;
	cout << "mat1 * mat2=" << mat3 << endl;
	mat3 = mat1 * 2;
	cout << "mat1 * 2=" << mat3 << endl;
	return 0;
}