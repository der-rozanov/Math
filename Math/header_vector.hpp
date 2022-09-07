#pragma once
#include "header_matrix.hpp"
#include <iostream>
#define pi 3.14159265358979323846

class Vector
{
	public:
		/// <summary>
		/// Constructor by coordinates
		/// </summary>
		Vector(double x2, double y2, double z2, double x1 = 0 , double y1 = 0 , double z1 = 0);
		/// <summary>
		/// Constructor by length and angles
		/// </summary>
		/// <param name="leng">lenght</param>
		/// <param name="alpha">angle between vector and X asix</param>
		/// <param name="beta">angle between vector and Y asix</param>
		/// <param name="gamma">angle between vector and Z asix</param>
		Vector(double x1, double y1, double z1, double leng, double alpha, double beta, double gamma);

		Vector& operator = (Vector const& V);
		Vector& operator - ();
		Vector& operator + (Vector const& V1); //решить проблему с некорректными значениями углов
		Vector& operator * (double num); //решить проблему с некорректными значениями углов

		Matrix getCoordinates();
		double getLength();
		Matrix getAngles();

		void printData();
		
	private:
		double x1_,x2_, y1_,y2_, z1_,z2_;
		double leng_;
		double alpha_, beta_, gamma_;
};

void swap(double& a, double& b);

double scalarMultiplication(Vector v1, Vector v2);