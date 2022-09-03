#pragma once

class Vector
{
	public:
		Vector(double x2, double y2, double z2, double x1 , double y1 , double z1 );
		Vector(double leng, double alpha, double beta, double gamma);
	private:
		double x_, y_, z_;
		double leng_;
		double alpha_, beta_, gamma_;
};
