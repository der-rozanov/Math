#include<iostream>
#include"MathLib.hpp"
#include<vector>

int main()
{
	Matrix m(3, 3, 1);
	Matrix n(3, 3, 5);

	Matrix sum = m + n;
	sum.print();
	system("pause");
}