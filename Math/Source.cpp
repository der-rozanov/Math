#include<iostream>
#include "MathLib.hpp"
#include<vector>

int main(void)
{
	std::vector<double> arr = { 3.15,3.08,3.05,3.05,3.02,2.99,2.97,3.04,3.05,3.07 };
	Selection s(arr);

	std::cout << s.relativeError(3)<<"\n";

	s.print();

	system("pause");
}