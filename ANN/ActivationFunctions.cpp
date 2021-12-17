#include "ActivationFunctions.h"
#include<cmath>

ActivationFunctions::ActivationFunctions()
{
}
void ActivationFunctions::set_activation_function(int function)
{
	this->chosen_function = function;
}

double ActivationFunctions::forward(double x)
{
	double ret_value;
	switch (this->chosen_function)
	{
	case SIGMOID:
		ret_value = this->sigmoid(x);
		break;
	default:
		throw("Unexpected ActivationFunctions => forward()");
		break;
	}

	return ret_value;
}

double ActivationFunctions::backward(double x)
{
	double ret_value;
	switch (this->chosen_function)
	{
	case SIGMOID:
		ret_value = this->derivate_sigmoid(x);
		break;
	default:
		throw("Unexpected ActivationFunctions => backward()");
		break;
	}

	return ret_value;
}
System::Collections::Generic::List<System::String^>^ ActivationFunctions::get_names()
{
	System::Collections::Generic::List<System::String^>^ names = gcnew System::Collections::Generic::List<System::String^>();
	names->Add("Sigmoid");
	return names;
}

double ActivationFunctions::sigmoid(double x)
{
	return 1.0 / (1.0 + std::exp(-x));
}

double ActivationFunctions::derivate_sigmoid(double x)
{
	return (this->sigmoid(x)*(1.0 - this->sigmoid(x)));
}
