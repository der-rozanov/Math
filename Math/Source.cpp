#include<iostream>
#include "MathLib.hpp"

int main(void)
{
	Vector V(1, 1, 0, 0, 0, 0);
	
	V.printData();

	V = -V;

	V.printData();

	system("pause");
}