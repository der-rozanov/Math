#pragma once
#include "header_matrix.hpp"
#include "header_vector.hpp"
#include "header_statistics.h"

/// <summary>
/// Outputs a vector structure to the stream.
/// </summary>
/// <typeparam name="T">Any type that can be stored in vector</typeparam>
/// <param name="">Vector</param>
/// <param name="">Separator, by default, no separation</param>
/// <param name="">Output method (in line or in column), by default, linear</param>
template <class T>
void printVector(std::vector<T> vct, char separator = ' ', std::string method = "linear")
{
	if (method == "linear") method = "\0";
	if (method == "columnar") method = "\n";
	for (size_t i = 0; i < vct.size(); i++)
	{
		std::cout << vct[i] << separator << method;
	}
}
