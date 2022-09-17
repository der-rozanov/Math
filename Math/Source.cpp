#include<iostream>
#include "MathLib.hpp"

int main(void)
{
	Vector V1(1, 0, 0);
	Vector V2(0, 0, 1);

	Vector V3 = vectorMultiplication(V1, V2);

	Matrix m = V3.getVector();

	m.print();

	system("pause");
}