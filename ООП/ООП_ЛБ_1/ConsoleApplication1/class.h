#include <iostream>
#include <cmath> 

namespace cl
{
	class Vectors
	{
		private:
			double x;
			double y;
			double z;
		public:
			Vectors(double valueX, double valueY, double valueZ);//�����������
			Vectors();//������� �����������
			~Vectors();//����������

			double get_X()const;//���������� x
			double get_Y()const;//���������� y
			double get_Z()const;//���������� z
			void Print();//����� �� �����
			void set_X();//������ � x
			void set_Y();//������ � y
			void set_Z();//������ � z
			double Module()const;//������
			void Multiplication_by_scalar(double scalar);//��������� �� ������
			Vectors(const Vectors &q);//�����������
			void Norm(double module);//���������� �������
	};
			Vectors SumVectors(const Vectors& a, const Vectors& b);//�����
			Vectors MinusVectors(const Vectors& a, const Vectors& b);//��������
			Vectors MultiplicationVectors(const Vectors& a, const Vectors& b);//������������
			double Scalar_multiplicationVectors(const Vectors& a, const Vectors& b);//��������� ������������
			double CosVectors(const Vectors& a, const Vectors& b);//�������
			double SinVectors(double cos);//�����
			double CornerVectors(const Vectors& a, const Vectors& b);//����
};