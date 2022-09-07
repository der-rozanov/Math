#include<iostream>
#include "MathLib.hpp"

int main(void)
{
	Vector V(1, 2, 0);
	Vector M(4, 8, 0);
	
	std::cerr << scalarMultiplication(V, M);

	system("pause");
}