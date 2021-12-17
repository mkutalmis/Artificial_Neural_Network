#pragma once
#include <vector>
#include"Layer.h"
#include"ActivationFunctions.h"
#include"CostFunctions.h"
#include"Optimizer.h"
#ifndef NETWORK_H
#define NETWORK_H

ref class Network
{
public:
	Network(ActivationFunctions^ actFunc, CostFunctions^ costFunc, Optimizer^ opt, int class_count);
	void addLayer(Layer^ nLayer);
	void init();
	double train(std::vector<double*> input_data, std::vector<int*> ticks);
	int feed_forward(double* inp);
	~Network();
private:
	System::Collections::Generic::List<Layer^>^ layers;
	int layer_count;
	int class_count;
	ActivationFunctions^ actFunc;
	CostFunctions^ costFunc;
	Optimizer^ opt;
};

#endif // !NETWORK_H


