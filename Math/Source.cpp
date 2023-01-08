#include<iostream>
#include"MathLib.hpp"
#include<vector>

int main()
{
	float delta_l[5] = { 2,4,6,8,10 };
	float D = 10e-3;
	float delta = 1;
	float freq = 10000000;
	double S = pi * D * D / 4;
	double El = 2.5;


	double Cx[10];
	double Sx[10];
	double Xc[10];

	for(size_t i = 0; i < 5; i++)
	{
		Sx[i] = (8.842e-12*200e-4) /(3e-3-1e-3+(1e-3/delta_l[i]));
		Cx[i] = (8.842e-12 * 200e-4 * 1e-3) / (3e-3 - 1e-3 + (1e-3 / delta_l[i]));
		Xc[i] = 1 / (2 * pi * freq *8.842e-12* Sx[i]);  //הה
	}
	
	for (size_t i = 0; i < 5; i++)
	{
		printf(" %.3f ", delta_l[i]);
	}
	std::cout << "\n";
	for (size_t i = 0; i < 10; i++)
	{
		printf(" %.4f ", Cx[i]*1e12);
	}
	std::cout << "\n";
	for (size_t i = 0; i < 5; i++)
	{
		printf(" %.4e ", Sx[i]);
	}
	std::cout << "\n";
	for (size_t i = 0; i < 5; i++)
	{
		printf(" %.2e ", Xc[i]);
	}



	system("pause");
}