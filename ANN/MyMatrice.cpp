#include "MyMatrice.h"

MyMatrice::MyMatrice(int row, int column)
{
	this->data = new double[row * column];
	this->row = row;
	this->column = column;
}
double& MyMatrice::operator() (int row, int column)
{
	return this->data[row * this->column + column];
}
void MyMatrice::add_row(int row, double* nData)
{
	for (int i = 0; i < this->column; i++)
	{
		this->data[row * this->column + i] = nData[i];
	}
}
int MyMatrice::get_row()
{
	return this->row;
}
int MyMatrice::get_column()
{
	return this->column;
}
MyMatrice::~MyMatrice()
{
	delete this->data;
}
