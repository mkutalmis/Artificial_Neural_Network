#include "Layer.h"

Layer::Layer(int neuron_count)
{
	this->neurons_count = neuron_count;
	this->neurons = gcnew array<Neuron^>(this->neurons_count);
	for (int i = 0; i < this->neurons_count; i++)
	{
		Neuron^ nNeuron = gcnew Neuron();
		this->neurons[i] = nNeuron;
	}
}

void Layer::init(int input_size, ActivationFunctions^ activation_function)
{
	this->input_size = input_size;
	this->func = activation_function;
	for (int i = 0; i < this->neurons_count; i++)
	{
		this->neurons[i]->init(input_size);
	}
	this->outputs = new double[this->neurons_count];
	this->ret_deltas = new double[this->input_size];
}

double* Layer::forward(double* lInputs)
{
	this->copy_inp(lInputs);
	for (int i = 0; i < this->neurons_count; i++)
	{
		double neuron_result = neurons[i]->forward(this->lInputs);
		outputs[i] = this->func->forward(neuron_result);
	}
	return outputs;
}

double* Layer::backward(double* lErrors)
{
	for (int i = 0; i < this->neurons_count; i++)
	{
		double neuron_result = neurons[i]->forward(this->lInputs);
		lErrors[i] = lErrors[i] * this->func->backward(neuron_result);
	}
	this->copy_deltas(lErrors);
	
	for (int i = 0; i < this->input_size; i++)
	{
		ret_deltas[i] = 0;
	}
	for (int i = 0; i < this->neurons_count; i++)
	{
		this->neurons[i]->backward(lErrors[i]);
		double* deltas = this->neurons[i]->get_deltas();
		for (int j = 0; j < this->input_size; j++)
		{
			ret_deltas[j] = ret_deltas[j] + deltas[j];
		}
	}
	return ret_deltas;
}
void Layer::update(MyMatrice^ dw, MyMatrice^ db)
{
	
	for (int i = 0; i < this->neurons_count; i++)
	{
		double* ddw = new double[this->input_size];
		for (int j = 0; j < this->input_size; j++)
		{
			ddw[j] = dw(i, j);
		}
		this->neurons[i]->update(ddw, db(i,0));
		delete ddw;
	}
}

int Layer::get_neurons_count()
{
	return this->neurons_count;
}
void Layer::copy_inp(double* inp)
{
	this->lInputs = new double[this->input_size];
	for (int i = 0; i < this->input_size; i++)
	{
		this->lInputs[i] = inp[i];
	}
}

void Layer::copy_deltas(double* inp)
{
	this->lDeltas = new double[this->neurons_count];
	for (int i = 0; i < this->neurons_count; i++)
	{
		this->lDeltas[i] = inp[i];
	}
}
int Layer::get_input_size()
{
	return this->input_size;
}

MyMatrice^ Layer::get_delta_weights()
{
	MyMatrice^ weights = gcnew MyMatrice(this->neurons_count, this->input_size);
	for (int i = 0; i < this->neurons_count; i++)
	{
		for (int j = 0; j < this->input_size; j++)
		{
			weights(i, j) = this->lDeltas[i];
		}
	}
	return weights;
}
MyMatrice^ Layer::get_delta_biases()
{
	MyMatrice^ biases = gcnew MyMatrice(this->neurons_count, 1);
	for (int i = 0; i < this->neurons_count; i++)
	{
		biases(i, 0) =  this->lDeltas[i];
	}
	return biases;
}
MyMatrice^ Layer::get_layer_inputs()
{
	MyMatrice^ layer_inputs = gcnew MyMatrice(this->input_size, 1);
	for (int i = 0; i < this->input_size; i++)
	{
		layer_inputs(i, 0) = this->lInputs[i];
	}
	return layer_inputs;
}
void Layer::end_of_step()
{
	for (int i = 0; i < this->neurons_count; i++)
	{
		this->neurons[i]->end_of_step();
	}
	delete this->lInputs;
	this->lInputs = '\0';
	delete this->lDeltas;
	this->lDeltas = '\0';
}
Layer::~Layer()
{
	delete this->lInputs;
	delete this->lDeltas;
	delete this->outputs;
	delete this->ret_deltas;
	for (int i = 0; i < this->neurons_count; i++)
	{
		delete this->neurons[i];
	}
}