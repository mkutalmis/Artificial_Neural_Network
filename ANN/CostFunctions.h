#pragma once
#ifndef COSTFUNCTIONS_H
#define COSTFUNCTIONS_H

constexpr auto MEAN_SQUARED_ERROR = 0;
ref class CostFunctions
{
public:
	CostFunctions();
	void set_function(int function);
	void set_inp_size(int inp_size);
	double forward(double* x, int* ticks);
	double* backward();
	void set_data_count(int data_count);
	System::Collections::Generic::List<System::String^>^ get_names();
	~CostFunctions();
private:
	int chosen_function;
	double* derivates;
	int inp_size;
	int data_count;
	double mean_squared_error(double* x, int* ticks);
};
#endif // !COSTFUNCTIONS_H


