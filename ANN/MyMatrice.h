#pragma once
#ifndef  MYMATRICE_H
#define MYMATRICE_H
ref class MyMatrice
{
public:
	MyMatrice(int row, int column);
	double& operator() (int row, int column);
	void add_row(int row, double* nData);
	int get_row();
	int get_column();
	~MyMatrice();
private:
	double* data;
	int row;
	int column;
};
#endif // ! MYMATRICE_H


