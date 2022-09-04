#pragma once
#include <iostream>
#define pi 3.14159265358979323846

class Vector
{
	public:
		/// <summary>
		/// Constructor by coordinates
		/// </summary>
		Vector(double x2, double y2, double z2, double x1 , double y1 , double z1 );
		/// <summary>
		/// Constructor by length and angles
		/// </summary>
		/// <param name="leng">lenght</param>
		/// <param name="alpha">angle between vector and X asix</param>
		/// <param name="beta">angle between vector and Y asix</param>
		/// <param name="gamma">angle between vector and Z asix</param>
		Vector(double leng, double alpha, double beta, double gamma);

		Vector& operator = (Vector const& V);
		Vector& operator - ();

		void printData();
	private:
		double x_, y_, z_;
		double leng_;
		double alpha_, beta_, gamma_;
};
