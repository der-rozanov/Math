#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

class Selection
{
	public:
		Selection(std::vector<double> input);

		double variance();
		double standardDeviation();

		void print();
	private:
		std::vector<double> select;
		std::vector<double> probab;
		double aver_expec;
};