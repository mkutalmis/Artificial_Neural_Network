#pragma once
//#include<list>
#ifndef ACTIVATIONFUNCTIONS_H
#define ACTIVATIONFUNCTIONS_H

constexpr auto SIGMOID = 0;

ref class ActivationFunctions
{
public:
	ActivationFunctions();
	void set_activation_function(int function);
	double forward(double x);
	double backward(double x);
	System::Collections::Generic::List<System::String^>^ get_names();
private:
	int chosen_function;
	double sigmoid(double x);
	double derivate_sigmoid(double x);
};
#endif // !ACTIVATEFUNCTIONS_H


