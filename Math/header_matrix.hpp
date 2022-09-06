#pragma once

#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>

class Matrix
{
	public:
		Matrix(size_t lines, size_t columns, double def_elem = 0);
		Matrix(Matrix const& M);
		~Matrix();

		double operator()(size_t line, size_t colmn) const;
		double& operator()(size_t line, size_t colmn);
		Matrix& operator = (Matrix const& M);
		Matrix& operator - ();
		Matrix operator + (Matrix const& M);
		Matrix operator * (Matrix const& M);
		Matrix T(Matrix const& M);
	
		//double det();
		void print();
	private:
		size_t lines_ = 0;
		size_t columns_;
		size_t size_;
		double** data_;

};
