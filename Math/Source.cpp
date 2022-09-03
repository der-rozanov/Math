#include<iostream>
#include "MathLib.hpp"

int main(void)
{
	Matrix m(2, 2, 10);

	Matrix n(2, 2, 5);

	Matrix l(2, 2);
	l = m + n;

	l.print();

	Vector V(10, 1.57, 1.57, 0);

	system("pause");
}