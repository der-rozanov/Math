#include "header_statistics.h"
Selection::Selection(std::vector<double> input)
{
	aver_expec = 0;
	std::sort(input.begin(), input.end());
	std::vector<double>::iterator it;
	for (it = input.begin(); it < input.end(); it++)
	{
		std::vector<double>::iterator fnd = std::find(select.begin(), select.end(), *it);
		
		if (fnd == select.end())
		{
			select.push_back(*it);
			probab.push_back(1);
		}
		else
		{
			probab[fnd-select.begin()]++;
		}
	}

	for (size_t i = 0; i < probab.size(); i++)
	{
		probab[i] /= input.size();
	}

	for (size_t i = 0; i < input.size(); i++)
		aver_expec += input[i];
	aver_expec = aver_expec / input.size();
}

double Selection::variance()
{
	double var = 0;
	for (size_t i = 0; i < select.size(); i++)
	{
		var += pow(select[i] - aver_expec, 2) * probab[i];
	}
	return var;
}

double Selection::standardDeviation()
{
	return sqrt(variance());
}

void Selection::print()
{
	for (size_t i = 0; i < select.size(); i++)
	{
		std::cout <<select[i] << " " ;
	}
	std::cout << std::endl;
	for (size_t i = 0; i < select.size(); i++)
	{
		std::cout << probab[i] << " ";
	}
	std::cout << std::endl << aver_expec<<std::endl;;
}