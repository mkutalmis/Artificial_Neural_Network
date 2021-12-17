#include "Optimizer.h"

Optimizer::Optimizer()
{
	this->dws = gcnew System::Collections::Generic::List<System::Collections::Generic::List<MyMatrice^>^>();
	this->dbs = gcnew System::Collections::Generic::List<System::Collections::Generic::List<MyMatrice^>^>();
	this->learning_rate = 0.01;
}
void Optimizer::set_optimizer(int opt)
{
	this->chosen_opt = opt;
}
void Optimizer::set_learning_rate(double learning_rate)
{
	this->learning_rate = learning_rate;
}
void Optimizer::set_layers(System::Collections::Generic::List<Layer^>^ layers)
{
	this->layers = layers;
}
void Optimizer::set_moments(int layer_count)
{
	this->mts = gcnew System::Collections::Generic::List<MyMatrice^>();
	this->bias_mts = gcnew System::Collections::Generic::List<MyMatrice^>();
	for (int i = 0; i < layer_count; i++)
	{
		int row = layers[i]->get_neurons_count();
		int column = layers[i]->get_input_size();
		MyMatrice^ mt = gcnew MyMatrice(row, column);
		MyMatrice^ bias_mt = gcnew MyMatrice(row, 1);
		for (int j = 0; j < row; j++)
		{
			bias_mt(j, 0) = 0;
			for (int k = 0; k < column; k++)
			{
				mt(j, k) = 0;
			}
		}
		this->mts->Add(mt);
		this->bias_mts->Add(bias_mt);
	}
}
void Optimizer::set_square_moments(int layer_count)
{
	this->vts = gcnew System::Collections::Generic::List<MyMatrice^>();
	this->bias_vts = gcnew System::Collections::Generic::List<MyMatrice^>();
	for (int i = 0; i < layer_count; i++)
	{
		int row = layers[i]->get_neurons_count();
		int column = layers[i]->get_input_size();
		MyMatrice^ vt = gcnew MyMatrice(row, column);
		MyMatrice^ bias_vt = gcnew MyMatrice(row, 1);
		for (int j = 0; j < row; j++)
		{
			bias_vt(j, 0) = 0;
			for (int k = 0; k < column; k++)
			{
				vt(j, k) = 0;
			}
		}
		this->vts->Add(vt);
		this->bias_vts->Add(bias_vt);
	}

}
void Optimizer::set_data_count(int data_count)
{
	this->data_count = data_count;
}
double Optimizer::forward(int index, int layer_count, int class_count,
	CostFunctions^ cf, double* output_of_network, int* tick)
{
	double err = cf->forward(output_of_network, tick);
	double* back_cost_func = cf->backward();
	if (this->chosen_opt == BATCH_GRADIENT_DESCENT)
	{
		std::vector<double*> backward_res_layers;
		backward_res_layers.push_back(back_cost_func);
		int indeks = 0;
		for (int layer = layer_count - 1; layer >= 0; layer--)
		{
			backward_res_layers.push_back(layers[layer]->backward(backward_res_layers[indeks]));
			indeks++;
		}
		System::Collections::Generic::List<MyMatrice^>^ dw = gcnew System::Collections::Generic::List<MyMatrice^>();
		System::Collections::Generic::List<MyMatrice^>^ db = gcnew System::Collections::Generic::List<MyMatrice^>();
		for (int i = 0; i < layer_count; i++)
		{
			MyMatrice^ ddw = layers[i]->get_delta_weights();
			MyMatrice^ ddb = layers[i]->get_delta_biases();
			MyMatrice^ lInput = layers[i]->get_layer_inputs();
			for (int j = 0; j < ddw->get_row(); j++)
			{
				for (int k = 0; k < ddw->get_column(); k++)
				{
					ddw(j, k) = ddw(j, k) * lInput(k, 0) * this->learning_rate;
				}
			}
			dw->Add(ddw);
			for (int j = 0; j < ddb->get_row(); j++)
			{
				for (int k = 0; k < ddb->get_column(); k++)
				{
					ddb(j, k) = ddb(j, k) * this->learning_rate;
				}
			}
			db->Add(ddb);
			delete lInput;
		}
		this->dws->Add(dw);
		this->dbs->Add(db);
		if (index == this->data_count - 1)
		{
			for (int i = 0; i < this->dws->Count; i++)
			{
				for (int j = 0; j < layer_count; j++)
				{
					System::Collections::Generic::List<MyMatrice^>^ w = this->dws[i];
					System::Collections::Generic::List<MyMatrice^>^ b = this->dbs[i];
					layers[j]->update(w[j], b[j]);
					delete w[j];
					delete b[j];
				}
			}
			this->dws->Clear();
			this->dbs->Clear();
		}
		/* Free Memory */
		for (int layer = 0; layer < layer_count; layer++)
		{
			layers[layer]->end_of_step();
		}
		backward_res_layers.clear();

	}
	else if (this->chosen_opt == STOCHASTIC_GRADIENT_DESCENT)
	{
		std::vector<double*> backward_res_layers;
		backward_res_layers.push_back(back_cost_func);
		int indeks = 0;
		for (int layer = layer_count - 1; layer >= 0; layer--)
		{
			backward_res_layers.push_back(layers[layer]->backward(backward_res_layers[indeks]));
			indeks++;
		}
		for (int i = 0; i < layer_count; i++)
		{
			MyMatrice^ ddw = layers[i]->get_delta_weights();
			MyMatrice^ ddb = layers[i]->get_delta_biases();
			MyMatrice^ lInput = layers[i]->get_layer_inputs();
			for (int j = 0; j < ddw->get_row(); j++)
			{
				for (int k = 0; k < ddw->get_column(); k++)
				{
					ddw(j, k) = ddw(j, k)* lInput(k, 0) * this->learning_rate;
				}
			}
			for (int j = 0; j < ddb->get_row(); j++)
			{
				for (int k = 0; k < ddb->get_column(); k++)
				{
					ddb(j, k) = ddb(j, k) * this->learning_rate;
				}
			}
			layers[i]->update(ddw, ddb);
			delete lInput;
			delete ddw;
			delete ddb;
		}
		/* Free Memory */
		for (int layer = 0; layer < layer_count; layer++)
		{
			layers[layer]->end_of_step();
		}
		backward_res_layers.clear();
	}
	else if (this->chosen_opt == MOMENTUM)
	{
		std::vector<double*> backward_res_layers;
		backward_res_layers.push_back(back_cost_func);
		int indeks = 0;
		for (int layer = layer_count - 1; layer >= 0; layer--)
		{
			backward_res_layers.push_back(layers[layer]->backward(backward_res_layers[indeks]));
			indeks++;
		}
		System::Collections::Generic::List<MyMatrice^>^ dw = gcnew System::Collections::Generic::List<MyMatrice^>();
		System::Collections::Generic::List<MyMatrice^>^ db = gcnew System::Collections::Generic::List<MyMatrice^>();
		for (int i = 0; i < layer_count; i++)
		{
			MyMatrice^ ddw = layers[i]->get_delta_weights();
			MyMatrice^ ddb = layers[i]->get_delta_biases();
			MyMatrice^ lInput = layers[i]->get_layer_inputs();
			for (int j = 0; j < ddw->get_row(); j++)
			{
				for (int k = 0; k < ddw->get_column(); k++)
				{
					ddw(j, k) = ddw(j, k) * lInput(k, 0);
				}
			}
			dw->Add(ddw);
			for (int j = 0; j < ddb->get_row(); j++)
			{
				for (int k = 0; k < ddb->get_column(); k++)
				{
					ddb(j, k) = ddb(j, k);
				}
			}
			db->Add(ddb);
			delete lInput;
		}
		this->dws->Add(dw);
		this->dbs->Add(db);
		if (index == this->data_count - 1)
		{
			this->set_moments(layer_count);
			double beta = 0.9;
			for (int p = 0; p < this->dws->Count; p++)
			{
				for (int l = 0; l < layer_count; l++)
				{
					System::Collections::Generic::List<MyMatrice^>^ w = this->dws[p];
					System::Collections::Generic::List<MyMatrice^>^ b = this->dbs[p];
					MyMatrice^ ddw = w[l];
					MyMatrice^ ddb = b[l];
					for (int j = 0; j < ddw->get_row(); j++)
					{
						for (int k = 0; k < ddw->get_column(); k++)
						{
							this->mts[l](j, k) = this->mts[l](j, k) * beta + this->learning_rate * ddw(j, k);
							ddw(j, k) = this->mts[l](j, k);
						}
					}
					for (int j = 0; j < ddb->get_row(); j++)
					{
						for (int k = 0; k < ddb->get_column(); k++)
						{
							this->bias_mts[l](j, k) = this->bias_mts[l](j, k) * beta + this->learning_rate * ddb(j, k);
							ddb(j, k) = this->bias_mts[l](j, k);
						}
					}
					layers[l]->update(ddw, ddb);
					delete ddw;
					delete ddb;
				}
			}
			this->clear_moments(layer_count);
			this->dws->Clear();
			this->dbs->Clear();
		}
		/* Free Memory */
		for (int layer = 0; layer < layer_count; layer++)
		{
			layers[layer]->end_of_step();
		}
		backward_res_layers.clear();

	}
	else if (this->chosen_opt == RMS_PROP)
	{
		std::vector<double*> backward_res_layers;
		backward_res_layers.push_back(back_cost_func);
		int indeks = 0;
		for (int layer = layer_count - 1; layer >= 0; layer--)
		{
			backward_res_layers.push_back(layers[layer]->backward(backward_res_layers[indeks]));
			indeks++;
		}
		System::Collections::Generic::List<MyMatrice^>^ dw = gcnew System::Collections::Generic::List<MyMatrice^>();
		System::Collections::Generic::List<MyMatrice^>^ db = gcnew System::Collections::Generic::List<MyMatrice^>();
		for (int i = 0; i < layer_count; i++)
		{
			MyMatrice^ ddw = layers[i]->get_delta_weights();
			MyMatrice^ ddb = layers[i]->get_delta_biases();
			MyMatrice^ lInput = layers[i]->get_layer_inputs();
			for (int j = 0; j < ddw->get_row(); j++)
			{
				for (int k = 0; k < ddw->get_column(); k++)
				{
					ddw(j, k) = ddw(j, k) * lInput(k, 0);
				}
			}
			dw->Add(ddw);
			for (int j = 0; j < ddb->get_row(); j++)
			{
				for (int k = 0; k < ddb->get_column(); k++)
				{
					ddb(j, k) = ddb(j, k);
				}
			}
			db->Add(ddb);
			delete lInput;
		}
		this->dws->Add(dw);
		this->dbs->Add(db);
		if (index == this->data_count - 1)
		{
			this->set_square_moments(layer_count);
			double eps = 1E-8;
			double beta = 0.9;
			for (int p = 0; p < this->dws->Count; p++)
			{
				for (int l = 0; l < layer_count; l++)
				{
					System::Collections::Generic::List<MyMatrice^>^ w = this->dws[p];
					System::Collections::Generic::List<MyMatrice^>^ b = this->dbs[p];
					MyMatrice^ ddw = w[l];
					MyMatrice^ ddb = b[l];
					for (int j = 0; j < ddw->get_row(); j++)
					{
						for (int k = 0; k < ddw->get_column(); k++)
						{
							this->vts[l](j, k) = this->vts[l](j, k) * beta + (1.0 - beta) * pow(ddw(j, k), 2.0);
							ddw(j, k) = ddw(j, k) * (this->learning_rate / (sqrt(this->vts[l](j, k) + eps)));
						}
					}
					for (int j = 0; j < ddb->get_row(); j++)
					{
						for (int k = 0; k < ddb->get_column(); k++)
						{
							this->bias_vts[l](j, k) = this->bias_vts[l](j, k) * beta + (1.0 - beta) * pow(ddb(j, k), 2.0);
							ddb(j, k) = ddb(j, k) * (this->learning_rate / (sqrt(this->bias_vts[l](j, k) + eps)));
						}
					}
					layers[l]->update(ddw, ddb);
					delete ddw;
					delete ddb;
				}
			}
			this->clear_square_moments(layer_count);
			this->dws->Clear();
			this->dbs->Clear();
		}
		/* Free Memory */
		for (int layer = 0; layer < layer_count; layer++)
		{
			layers[layer]->end_of_step();
		}
		backward_res_layers.clear();
	}
	else if (this->chosen_opt == ADAM)
	{
		std::vector<double*> backward_res_layers;
		backward_res_layers.push_back(back_cost_func);
		int indeks = 0;
		for (int layer = layer_count - 1; layer >= 0; layer--)
		{
			backward_res_layers.push_back(layers[layer]->backward(backward_res_layers[indeks]));
			indeks++;
		}
		System::Collections::Generic::List<MyMatrice^>^ dw = gcnew System::Collections::Generic::List<MyMatrice^>();
		System::Collections::Generic::List<MyMatrice^>^ db = gcnew System::Collections::Generic::List<MyMatrice^>();
		for (int i = 0; i < layer_count; i++)
		{
			MyMatrice^ ddw = layers[i]->get_delta_weights();
			MyMatrice^ ddb = layers[i]->get_delta_biases();
			MyMatrice^ lInput = layers[i]->get_layer_inputs();
			for (int j = 0; j < ddw->get_row(); j++)
			{
				for (int k = 0; k < ddw->get_column(); k++)
				{
					ddw(j, k) = ddw(j, k) * lInput(k, 0);
				}
			}
			dw->Add(ddw);
			for (int j = 0; j < ddb->get_row(); j++)
			{
				for (int k = 0; k < ddb->get_column(); k++)
				{
					ddb(j, k) = ddb(j, k);
				}
			}
			db->Add(ddb);
			delete lInput;
		}
		this->dws->Add(dw);
		this->dbs->Add(db);
		if (index == this->data_count - 1)
		{
			this->set_moments(layer_count);
			this->set_square_moments(layer_count);
			double eps = 1E-8;
			double beta1 = 0.9;
			double beta2 = 0.999;
			for (int p = 0; p < this->dws->Count; p++)
			{
				for (int l = 0; l < layer_count; l++)
				{
					System::Collections::Generic::List<MyMatrice^>^ w = this->dws[p];
					System::Collections::Generic::List<MyMatrice^>^ b = this->dbs[p];
					MyMatrice^ ddw = w[l];
					MyMatrice^ ddb = b[l];
					for (int j = 0; j < ddw->get_row(); j++)
					{
						for (int k = 0; k < ddw->get_column(); k++)
						{
							this->mts[l](j, k) = this->mts[l](j, k) * beta1 + (1.0 - beta1) * ddw(j, k);
							this->vts[l](j, k) = this->vts[l](j, k) * beta2 + (1.0 - beta2) * pow(ddw(j, k), 2.0);
							double mtt = this->mts[l](j, k) / (1.0 - pow(beta1, 1));
							double vtt = this->vts[l](j, k) / (1.0 - pow(beta2, 1));
							ddw(j, k) = (mtt / (sqrt(vtt) + eps)) * this->learning_rate;
						}
					}
					for (int j = 0; j < ddb->get_row(); j++)
					{
						for (int k = 0; k < ddb->get_column(); k++)
						{
							this->bias_mts[l](j, k) = this->bias_mts[l](j, k) * beta1 + (1.0 - beta1) * ddb(j, k);
							this->bias_vts[l](j, k) = this->bias_vts[l](j, k) * beta2 + (1.0 - beta2) * pow(ddb(j, k), 2.0);
							double mtt = this->bias_mts[l](j, k) / (1.0 - pow(beta1, 1));
							double vtt = this->bias_vts[l](j, k) / (1.0 - pow(beta2, 1));
							ddb(j, k) = (mtt / (sqrt(vtt) + eps)) * this->learning_rate;
						}
					}
					layers[l]->update(ddw, ddb);
					delete ddw;
					delete ddb;
				}
			}
			this->clear_moments(layer_count);
			this->clear_square_moments(layer_count);
			this->dws->Clear();
			this->dbs->Clear();
		}
		/* Free Memory */
		for (int layer = 0; layer < layer_count; layer++)
		{
			layers[layer]->end_of_step();
		}
		backward_res_layers.clear();

	}
	return err;
}
System::Collections::Generic::List<System::String^>^ Optimizer::get_names()
{
	System::Collections::Generic::List<System::String^>^ names = gcnew System::Collections::Generic::List<System::String^>();
	names->Add("Batch Gradient Descent");
	names->Add("Stochastic Gradient Descent");
	names->Add("Momentum");
	names->Add("RMSProp");
	names->Add("Adam");
	return names;
}
void Optimizer::clear_moments(int layer_count)
{
	for (int i = 0; i < layer_count; i++)
	{
		delete this->mts[i];
		delete this->bias_mts[i];
	}
	this->mts->Clear();
	this->bias_mts->Clear();
}
void Optimizer::clear_square_moments(int layer_count)
{
	for (int i = 0; i < layer_count; i++)
	{
		delete this->vts[i];
		delete this->bias_vts[i];
	}
	this->vts->Clear();
	this->bias_vts->Clear();
}
double Optimizer::get_learning_rate()
{
	return this->learning_rate;
}