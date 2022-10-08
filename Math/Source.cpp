#include<iostream>
#include "MathLib.hpp"
#include<vector>

int main(void)
{
	std::vector<double> arr = { 70,71,72,74,74,75,76,76,76,77 };
	Selection s(arr);

	s.print();

	std::cout << s.standardDeviation();
	system("pause");
}