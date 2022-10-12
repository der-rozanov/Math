#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

class Selection
{
	public:
		/// <summary>
		/// Accepts a double vector of random sequence and repeatability of elements.
		/// </summary>
		/// <param name="input">std::vector</param>
		Selection(std::vector<double> input);

		/// <summary>
		/// Returns mathematical expectation
		/// </summary>
		/// <returns>math expect</returns>
		double getAverage();

		/// <summary>
		/// Find selection variance.
		/// </summary>
		/// <returns name="variance">variance</returns>
		double variance();

		/// <summary>
		/// Find standard deviation of the selection.
		/// </summary>
		/// <returns>standard deviation</returns>
		double standardDeviation();

		/// <summary>
		/// Searches for the relative error, considering the selection as the result of measurements and the parameter as the normalizing value.
		/// </summary>
		/// <param name="normalizing value"></param>
		/// <returns name="relative error"></returns>
		double relativeError(double norm_value);

		/// <summary>
		/// Returns a sorted selection
		/// </summary>
		/// <returns>sorted selection</returns>
		std::vector<double> getSelection();

		/// <summary>
		/// Returns a set of probabilities of occurrence of the corresponding original elements from the selection
		/// </summary>
		/// <returns>set of probabilities</returns>
		std::vector<double> getProbability();

		/// <summary>
		/// Returns maximum element of selection
		/// </summary>
		/// <returns>max</returns>
		double getMaxElement();

		/// <summary>
		/// Returns minimum element of selection
		/// </summary>
		/// <returns>min</returns>
		double getMinElement();

		/// <summary>
		/// Returns a most common element of selection, if he is not alone, then among them returns the rightmost
		/// </summary>
		/// <returns>common</returns>
		double getComElement();

		/// <summary>
		/// Returns a most rare element of selection, if he is not alone, then among them returns the rightmost
		/// </summary>
		/// <returns>rare</returns>
		double getRareElement();

		/// <summary>
		/// Outputs a sorted selection and the probability of occurrence of each original element to the stream.
		/// </summary>
		void print();
	private:
		std::vector<double> select;
		std::vector<double> probab;
		double aver_expec;
		double input_size;
};