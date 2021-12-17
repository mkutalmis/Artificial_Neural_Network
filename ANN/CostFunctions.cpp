#include "CostFunctions.h"
#include<cmath>

CostFunctions::CostFunctions()
{
}
void CostFunctions::set_function(int function)
{
	this->chosen_function = function;
}
void CostFunctions::set_inp_size(int inp_size)
{
	this->derivates = new double[inp_size];
	this->inp_size = inp_size;
}
void CostFunctions::set_data_count(int data_count)
{
	this->data_count = data_count;
}

double CostFunctions::forward(double* x, int* ticks)
{
	double ret_value;
	switch (this->chosen_function)
	{
	case MEAN_SQUARED_ERROR:
		ret_value = this->mean_squared_error(x, ticks);
		break;
	default:
		throw("Unexpected CostFunctions => forward()");
		break;
	}

	return ret_value;
}

double* CostFunctions::backward()
{
	return this->derivates;
}

System::Collections::Generic::List<System::String^>^ CostFunctions::get_names()
{
	System::Collections::Generic::List<System::String^>^ names = gcnew System::Collections::Generic::List<System::String^>();
	names->Add("Mean Squared Error");
	return names;
}
double CostFunctions::mean_squared_error(double* x, int* ticks)
{
	double err = 0;
	for (int i = 0; i < this->inp_size; i++)
	{
		this->derivates[i] = (ticks[i] - x[i]) * -1.0;
		err += std::pow((ticks[i] - x[i]), 2);
	}
	err *= 1.0 / 2.0;
	return err;
}

CostFunctions::~CostFunctions()
{
	delete this->derivates;
}
