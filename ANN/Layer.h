#pragma once
#include"Neuron.h"
#include"ActivationFunctions.h"
#include "MyMatrice.h"
#include<array>

#ifndef LAYER_H
#define LAYER_H
ref class Layer
{
public:
	Layer(int neuron_count);
	void init(int input_size, ActivationFunctions^ activation_function);
	double* forward(double* lInputs);
	double* backward(double* lErrors);
	void update(MyMatrice^ dw, MyMatrice^ db);
	int get_neurons_count();
	int get_input_size();
	void end_of_step();
	MyMatrice^ get_delta_weights();
	MyMatrice^ get_delta_biases();
	MyMatrice^ get_layer_inputs();
	~Layer();
private:
	int input_size;
	int neurons_count;
	double* lInputs;
	double* lDeltas;
	double* outputs;
	double* ret_deltas;
	array<Neuron^>^ neurons;
	ActivationFunctions^func;
	void copy_inp(double* inp);
	void copy_deltas(double* inp);
};
#endif // !LAYER_H


