#include "header_vector.hpp"
#include "header_matrix.hpp"
#include <cmath>

Vector::Vector(double x2, double y2, double z2, double x1, double y1, double z1) :
	x2_(x2), y2_(y2), z2_(z2), x1_(x1), y1_(y1), z1_(z1)
{
	leng_ = sqrt(std::pow(((x2 - x1)), 2) + std::pow((y2 - x1), 2) + std::pow(((z2 - x1)), 2));
	alpha_ = std::acos((x2 - x1) / leng_);
	beta_ = std::acos((y2 - y1) / leng_);
	gamma_ = std::acos((z2 - z1) / leng_);
};

Vector::Vector(double x1, double y1, double z1, double leng, double alpha, double beta, double gamma) : leng_(leng), alpha_(alpha), beta_(beta), gamma_(gamma),
x1_(x1), y1_(y1), z1_(z1)
{
	x2_ = leng_ * cos(alpha_) + x1_;
	y2_ = leng_ * cos(beta_) + y1_;
	z2_ = leng_ * cos(gamma_) + z1_;
}

Vector& Vector::operator = (Vector const& V)
{
	leng_ = V.leng_;
	x1_ = V.x1_; y1_ = V.y1_; z1_ = V.z1_; x2_ = V.x2_; y2_ = V.y2_; z2_ = V.z2_;
	alpha_ = V.alpha_; beta_ = V.beta_; gamma_ = V.gamma_;

	return *this;
}

Vector& Vector::operator - ()
{
	swap(x1_, x2_);
	swap(y1_, y2_);
	swap(z1_, z2_);
	alpha_ += pi;  if(alpha_ >= (2 * pi)) alpha_ = alpha_ - 2 * pi;
	beta_ += pi; if (beta_ >= 2 * pi) beta_ = beta_ - 2 * pi;
	gamma_ += pi; if (gamma_ >= 2 * pi) gamma_ = gamma_ - 2 * pi;

	return *this;
}

Vector& Vector::operator + (Vector const& V1)
{
	Vector Out(x2_ + V1.x2_, y2_ + V1.y2_, z2_ + V1.z2_, x1_ + V1.x1_, y1_ + V1.y1_, z1_ + V1.z1_);
	return Out;
}

Vector& Vector::operator * (double num)
{
	if (num < 0) *this = -*this;

	x2_ = (x2_ - x1_) * num + x1_;
	y2_ = (y2_ - y1_) * num + y1_;
	z2_ = (z2_ - z1_) * num + z1_;


	return *this;
}

void Vector::printData()
{
	std::cerr << "Begin: " << x1_ << " " << y1_ << " " << z1_ << "\n";
	std::cerr << "End: " << x2_ << " " << y2_ << " " << z2_ << "\n";
	std::cerr << "Length: " << leng_ << "\n";
	std::cerr << "Alpha: " << alpha_ << "\nBeta: " << beta_ << "\nGamma: " << gamma_<<"\n";
}

double Vector::getLength()
{
	return leng_;
}

Matrix Vector::getAngles()
{
	Matrix M(1, 3);
	M(0, 0) = alpha_; M(0, 1) = beta_; M(0, 2) = gamma_;

	return M;
}

Matrix Vector::getCoordinates()
{
	Matrix M(2, 3);
	M(0, 0) = x1_; M(0, 1) = y1_; M(0, 2) = z1_;
	M(1, 0) = x2_; M(1, 1) = y2_; M(1, 2) = z2_;
	return M;
}

Matrix Vector::getVector()
{
	Matrix M(1, 3);
	M(0, 0) = x2_ - x1_; M(0, 1) = y2_ - y1_; M(0, 2) = z2_ - z1_;

	return M;
}

void swap(double& a, double& b)
{
	double vsp = a;
	a = b;
	b = vsp;
}

double scalarMultiplication(Vector& v1, Vector& v2)
{
	Matrix m1 = v1.getCoordinates();
	Matrix m2 = v2.getCoordinates();
	double x1 = m1(1, 0) - m1(0, 0); double y1 = m1(1, 1) - m1(0, 1); double z1 = m1(1, 2) - m1(0, 2);
	double x2 = m2(1, 0) - m2(0, 0); double y2 = m2(1, 1) - m2(0, 1); double z2 = m2(1, 2) - m2(0, 2);
	return x1 * x2 + y1 * y2 + z1 * z2;
}

Vector vectorMultiplication(Vector& v1, Vector& v2)
{
	//later
}