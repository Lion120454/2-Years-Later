#include "stdafx.h"
#include "locale.h"
#include "iostream"
#include "cmath"
#include "class.h"
using namespace std;
using namespace cl;

int main()
{
	setlocale(LC_ALL, "ru");
	Vectors V1(0, 0, 0), V2(2, 3, 7), V3(7, 5, 9);
	//���� ��������� � ������ ������ � ��� �����
	cout << "������� X" << endl;
	V1.set_X();
	cout << "������� Y" << endl;
	V1.set_Y();
	cout << "������� Z" << endl;
	V1.set_Z();
	V1.Print();
	//���������� ������ ������� �������
	double module;
	module=V1.Module();
	cout << "������ V1= " << module << endl;
	//��������� ������� ������� �� ������
	double scalar;
	cout << "������� ������" << endl;
	cin >> scalar;
	V1.Multiplication_by_scalar(scalar);
	V1.Print();
	//����������� ������� ������� � ������
	cout << "����������� V1" << endl;
	V1.get_X();
	V1.get_Y();
	V1.get_Z();
	V1.Print();
	//���������� ������� ������� �������
	V1.Norm(V1.Module());
	V1.Print();
	//����� ������� � �������� �������
	V1 = SumVectors(V2, V3);
	V1.Print();
	//�������� ������� � ������� �������
	V3 = MinusVectors(V1, V2);
	V3.Print();
	//������������ �������� � ������� �������
	V2 = MultiplicationVectors(V3, V1);
	V2.Print();
	//��������� ������������ ������� � ������� �������
	double scalar_m;
	scalar_m = Scalar_multiplicationVectors(V1, V3);
	cout <<"��������� ������������= "<<scalar_m<< endl;
	//������� � ����� ���� ����� ������ � ������ ��������
	double cosinus, sinus;
	cosinus = CosVectors(V2, V3);
	cout << "�������= " << cosinus << endl;
	sinus = SinVectors(cosinus);
	cout << "�����= " << sinus << endl;
	//�������� ���� � �������� ����� ���������
	double c = CornerVectors(V1, V2);
	cout << "���� ����� V1 � V3= " << c << endl;
	return 0;
}