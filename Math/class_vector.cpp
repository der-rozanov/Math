#include "header_vector.hpp"
#include <cmath>

Vector::Vector(double x2, double y2, double z2, double x1, double y1, double z1) :
	x_(x2-x1), y_(y2-x1), z_(z2-x1)
{
	leng_ = sqrt(std::pow((x_), 2) + std::pow((y_), 2) + std::pow((z_), 2));
	alpha_ = std::acos((x2 - x1) / leng_);
	beta_ = std::acos((y2 - y1) / leng_);
	gamma_ = std::acos((z2 - z1) / leng_);
};

Vector::Vector(double leng, double alpha, double beta, double gamma) : leng_(leng), alpha_(alpha), beta_(beta), gamma_(gamma)
{
	x_ = leng_ * cos(alpha_);
	y_ = leng_ * cos(beta_);
	z_ = leng_ * cos(gamma_);
}

Vector& Vector::operator = (Vector const& V)
{
	leng_ = V.leng_;
	x_ = V.x_; y_ = V.y_; z_ = V.z_;
	alpha_ = V.alpha_; beta_ = V.beta_; gamma_ = V.gamma_;

	return *this;
}

Vector& Vector::operator - ()
{
	x_ = -x_;
	y_ = -y_;
	z_ = -z_;
	alpha_ += pi;
	beta_ += pi;
	gamma_ += pi;

	return *this;
}

void Vector::printData()
{
	std::cerr << x_ << " " << y_ << " " << z_;
}