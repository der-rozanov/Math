#include "header_vector.hpp"
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

void Vector::printData()
{
	std::cerr << "Begin: " << x1_ << " " << y1_ << " " << z1_ << "\n";
	std::cerr << "End: " << x2_ << " " << y2_ << " " << z2_ << "\n";
	std::cerr << "Length: " << leng_ << "\n";
	std::cerr << "Alpha: " << alpha_ << "\nBeta: " << beta_ << "\nGamma: " << gamma_<<"\n";
}

void swap(double& a, double& b)
{
	double vsp = a;
	a = b;
	b = vsp;
}