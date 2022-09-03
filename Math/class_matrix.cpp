#include "header_matrix.hpp"

Matrix::Matrix(size_t lines, size_t columns, double def_elem) : lines_(lines), columns_(columns) {
	data_ = new double* [lines_];
	data_[0] = new double[lines_ * columns_];
	size_ = lines_ * columns_;

	for (size_t i = 1; i != lines_; ++i)
	{
		data_[i] = data_[i - 1] + columns_;
	}

	for (size_t i = 0; i < lines_; i++)
	{
		for (size_t j = 0; j < columns_; j++)
		{
			data_[i][j] = def_elem;
		}
	}
}

Matrix::Matrix(Matrix const& M) : lines_(M.lines_), columns_(M.columns_), size_(M.size_)
{
	data_ = new double* [M.lines_];
	data_[0] = new double[M.lines_ * M.columns_];

	for (size_t i = 1; i != lines_; ++i)
	{
		data_[i] = data_[i - 1] + columns_;
	}

	for (size_t i = 0; i < lines_; i++)
	{
		for (size_t j = 0; j < columns_; j++)
		{
			data_[i][j] = M.data_[i][j];
		}
	}
}

Matrix::~Matrix()
{
	delete[] data_[0];
	delete[] data_;
}

double Matrix::operator()(size_t line, size_t colmn) const
{
	return data_[line][colmn];
}

double& Matrix::operator()(size_t line, size_t colmn)
{
	return data_[line][colmn];
}

Matrix& Matrix::operator = (Matrix const& M)
{
	if (this != &M)
	{
		delete data_[0];
		delete data_;

		size_ = M.size_;
		lines_ = M.lines_;
		columns_ = M.columns_;

		data_ = new double* [lines_];
		data_[0] = new double[lines_ * columns_];

		for (size_t i = 1; i != lines_; ++i)
		{
			data_[i] = data_[i - 1] + columns_;
		}

		for (size_t i = 0; i < lines_; i++)
		{
			for (size_t j = 0; j < columns_; j++)
			{
				data_[i][j] = M.data_[i][j];
			}
		}
		return *this;
	}
}

Matrix& Matrix::operator - ()
{
	for (size_t i = 0; i < lines_; i++)
	{
		for (size_t j = 0; j < columns_; j++)
		{
			data_[i][j] = -data_[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator + (Matrix const& M)
{
	if (lines_ == M.lines_ && columns_ == M.columns_)
	{
		Matrix N(lines_, columns_);
		for (size_t i = 0; i < lines_; ++i)
		{
			for (size_t j = 0; j < columns_; ++j)
			{
				N(i, j) = data_[i][j] + M.data_[i][j];
			}
		}
		return N;
	}
	else
	{
		throw std::invalid_argument("Matrix dimensions must be the same length");
	}
}

Matrix Matrix::operator * (Matrix const& M)
{
	if (columns_ == M.lines_)
	{
		Matrix N(lines_, M.columns_);
		for (size_t i = 0; i < N.lines_; ++i)
		{
			for (size_t j = 0; j < N.columns_; ++j)
			{
				for (size_t k = 0; k < columns_; ++k)
				{
					N(i, j) += data_[i][k] * M.data_[k][j];
				}
			}
		}
		return N;
	}
	else
	{
		throw std::invalid_argument("Matrix A columns amount must be the same with Matrix B lines amount");
	}
}

Matrix Matrix::T(Matrix const& M)
{
	Matrix N(columns_, lines_);
	for (size_t i = 0; i < lines_; ++i)
	{
		for (size_t j = 0; j < columns_; ++j)
		{
			N(j, i) = M(i, j);
		}
	}
	return N;
}

void Matrix::print()
{
	for (size_t i = 0; i < lines_; i++)
	{
		for (size_t j = 0; j < columns_; j++)
		{
			std::cerr << data_[i][j] << " ";
		}
		std::cerr << std::endl;
	}
}