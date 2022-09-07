#include<iostream>
#include "MathLib.hpp"

int main(void)
{
	Vector V(1, 1, 0, 0, 0, 0);
	
	V.printData();

	V = V * 10;

	V.printData();

	system("pause");
}