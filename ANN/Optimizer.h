#pragma once
#include <string>
#include "MyMatrice.h"
#include "Layer.h"
#include "CostFunctions.h"
#include <vector>
#ifndef OPTIMIZER_H
#define OPTIMIZER_H


constexpr auto BATCH_GRADIENT_DESCENT = 0;
constexpr auto STOCHASTIC_GRADIENT_DESCENT = 1;
constexpr auto MOMENTUM = 2;
constexpr auto RMS_PROP = 3;
constexpr auto ADAM = 4;


ref class Optimizer
{
public:
	Optimizer();
	void set_optimizer(int opt);
	void set_learning_rate(double learning_rate);
	double get_learning_rate();
	double forward(int index, int layer_count, int class_count, 
				CostFunctions^ cf, double* output_of_network, int* tick);
	System::Collections::Generic::List<System::String^>^ get_names();
	void set_layers(System::Collections::Generic::List<Layer^>^ layers);
	void set_moments(int layer_count);
	void set_square_moments(int layer_count);
	void clear_moments(int layer_count);
	void clear_square_moments(int layer_count);
	void set_data_count(int data_count);
private:
	int chosen_opt;
	int data_count;
	double learning_rate;
	System::Collections::Generic::List<System::Collections::Generic::List<MyMatrice^>^>^ dws;
	System::Collections::Generic::List<System::Collections::Generic::List<MyMatrice^>^>^ dbs;
	System::Collections::Generic::List<Layer^>^ layers;
	System::Collections::Generic::List<MyMatrice^>^ mts;
	System::Collections::Generic::List<MyMatrice^>^ vts;
	System::Collections::Generic::List<MyMatrice^>^ bias_mts;
	System::Collections::Generic::List<MyMatrice^>^ bias_vts;
};
#endif // !OPTIMIZER_H

