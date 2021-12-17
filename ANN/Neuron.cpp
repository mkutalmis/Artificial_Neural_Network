#include "Neuron.h"
#include <iostream> // rand() , srand()
#include <time.h> // time()

Neuron::Neuron()
{

}

void Neuron::init(int input_count)
{
	this->input_size = input_count;
	this->weights = new double[input_count];
	srand((unsigned)time(NULL));
	for (int i = 0; i < input_count; i++)
	{
		weights[i] = ((double)rand() / (RAND_MAX));
	}
	this->bias = ((double)rand() / (RAND_MAX));
}

double Neuron::forward(double* nInput)
{
	double result = this->bias;
	for (int i = 0; i < this->input_size; i++)
	{
		result += nInput[i] * this->weights[i];
	}
	return result;
}

void Neuron::backward(double nDelta)
{
	this->deltas = new double[this->input_size];
	for (int i = 0; i < this->input_size; i++)
	{
		this->deltas[i] = this->weights[i] * nDelta;
	}
}

void Neuron::update(double* dw, double db)
{
	this->bias = this->bias - db;
	for (int i = 0; i < this->input_size; i++)
	{
		this->weights[i] = this->weights[i] - dw[i];
	}
}

void Neuron::end_of_step()
{
	delete this->deltas;
	this->deltas = '\0';
}
double* Neuron::get_weights()
{
	return this->weights;
}
double* Neuron::get_deltas()
{
	return this->deltas;
}
double Neuron::get_bias()
{
	return this->bias;
}

Neuron::~Neuron()
{
	delete this->weights;
	delete this->deltas;
}