#include<iostream>
#include "MathLib.hpp"
#include<vector>

int main(void)
{
	std::vector<double> arr = { 3.15,3.08,3.05,3.05,3.02,2.99,2.97,3.04,3.05,3.07 };
	Selection s(arr);

	arr = s.getSelection();

	std::cout << s.getAverage();

	system("pause");
}