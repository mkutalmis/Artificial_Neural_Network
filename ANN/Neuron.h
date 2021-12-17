#pragma once
#ifndef NEURON_H
#define NEURON_H
ref class Neuron
{
public:
	Neuron();
	void init(int input_count);
	double forward(double* nInput);
	void backward(double nDelta);
	void update(double* dw, double db);
	double* get_weights();
	double* get_deltas();
	void end_of_step();
	double get_bias();
	~Neuron();
private:
	int input_size;
	double* weights;
	double* deltas;
	double bias;
};

#endif // !NEURON_H

