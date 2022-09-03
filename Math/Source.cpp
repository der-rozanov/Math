#include<iostream>
#include "header_matrix.hpp"

int main(void)
{
	Matrix m(2, 2, 10);

	Matrix n(2, 2, 5);

	Matrix l(2, 2);
	l = m + n;

	l.print();
}