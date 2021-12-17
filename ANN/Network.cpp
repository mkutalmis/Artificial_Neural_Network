#include "Network.h"
#include "MyMatrice.h"
Network::Network(ActivationFunctions^ actFunc, CostFunctions^ costFunc, Optimizer^ opt, int class_count)
{
	this->actFunc = actFunc;
	this->costFunc = costFunc;
	this->opt = opt;
	this->layer_count = 0;
	this->class_count = class_count;
	this->layers = gcnew System::Collections::Generic::List<Layer^>();
}

void Network::addLayer(Layer^ nLayer)
{
	this->layers->Add(nLayer);
	this->layer_count++;
}

double Network::train(std::vector<double*> input_data, std::vector<int*> ticks)
{
	double total_err = 0; 
	int data_count = input_data.size();
	this->opt->set_layers(this->layers);
	this->opt->set_data_count(data_count);
	for (int data = 0; data < data_count; data++)
	{
		std::vector<double*> res_layers;
		res_layers.push_back((this->layers[0]->forward(input_data[data])));
		/* Forward Propagation */
		for (int layer = 1; layer < this->layer_count; layer++)
		{
			res_layers.push_back(this->layers[layer]->forward(res_layers[layer - 1]));
		}
		/* Backward Propagation */
		total_err += this->opt->forward(data, this->layer_count, this->class_count,
			this->costFunc, res_layers[this->layer_count - 1], ticks[data]);

		/* Free Memory */
		res_layers.clear();
	}
	return total_err;
}

int Network::feed_forward(double* inp)
{
	std::vector<double*> res_layers;
	res_layers.push_back((this->layers[0]->forward(inp)));
	/* Forward Propagation */
	for (int layer = 1; layer < this->layer_count; layer++)
	{
		res_layers.push_back(this->layers[layer]->forward(res_layers[layer - 1]));
	}
	int maks_indeks = 0;
	double maks = res_layers[this->layer_count - 1][maks_indeks];
	for (int i = 1; i < this->class_count; i++)
	{
		if (res_layers[this->layer_count - 1][i] > maks)
		{
			maks_indeks = i;
			maks = res_layers[this->layer_count - 1][i];
		}
	}

	return maks_indeks;
}
void Network::init()
{
	this->layers[0]->init(10, this->actFunc);
	for (int layer = 1; layer < this->layer_count; layer++)
	{
		this->layers[layer]->init(this->layers[layer - 1]->get_neurons_count(), this->actFunc);
	}
}
Network::~Network()
{
	for (int layer = 0; layer < this->layer_count; layer++)
	{
		delete this->layers[layer];
	}
}