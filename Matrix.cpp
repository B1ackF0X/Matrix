#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Matrix.h"


Matrix::Matrix(unsigned m, unsigned n)
{
	this->m = m;
	this->n = n;
				
	Matr = new int*[m];
	
	for(int i = 0; i < m; i++)
		Matr[i] = new int[n];
					
	for(int count_row = 0; count_row < m; count_row++)
		for(int count_column = 0; count_column < n; count_column++)
			Matr[count_row][count_column] = 0.0;
}

unsigned Matrix::total_rows()
{
	return m;
}

unsigned Matrix::total_columns()
{
	return n;
}

int Matrix::get(unsigned row, unsigned column)
{
	return Matr[row][column];
}

void Matrix::push(unsigned row, unsigned column, int value)
{
	Matr[row][column] = value;
}

void Matrix::show()
{
	for(int count_row = 0; count_row < m; count_row++)
	{
		std::cout << std::endl;
		for(int count_column = 0; count_column < n; count_column++)
			std::cout << std::setw(3) << Matr[count_row][count_column] << "    ";
	}
	
	std::cout << std::endl;
}

void operator <<(Matrix Matr, int x[])
{
	for(int count_row = 0; count_row < Matr.total_rows(); count_row++)
		for(int count_column = 0; count_column < Matr.total_columns(); count_column++)
			Matr.push(count_row, count_column, x[count_row * Matr.total_columns() + count_column]);
}

Matrix operator *(Matrix mtr_1, Matrix mtr_2)
{
	int s = 0;
	Matrix matr_3(mtr_1.total_rows(), mtr_2.total_columns());
	
	if(mtr_1.total_columns() != mtr_2.total_rows())
	{
		std::cout << "Matrix multiplication is impossible" << std::endl;
		exit(EXIT_FAILURE);
		return matr_3;
	}
	
	for(int m = 0; m < mtr_1.total_rows(); m++)
	{    
		for(int n = 0; n < mtr_2.total_columns(); n++)    
		{    
			for(int i = 0; i < mtr_1.total_columns(); i++)
				s += mtr_1.get(m, i)*mtr_2.get(i, n);
			matr_3.push(m, n, s);
			s = 0;
		}
	}
	
	return matr_3;
}

Matrix operator +(Matrix mtr_1, Matrix mtr_2)
{
	Matrix matr_3(mtr_1.total_rows(), mtr_2.total_columns());
	
	if(mtr_1.total_rows() != mtr_2.total_rows() || mtr_1.total_columns() != mtr_2.total_columns())
	{
		std::cout << "Matrix addition is impossible" << std::endl;
		exit(EXIT_FAILURE);
		return matr_3;
	}
	
	for(int m = 0; m < mtr_1.total_rows(); m++)
		for(int n = 0; n < mtr_1.total_columns(); n++)
			matr_3.push(m, n, mtr_1.get(m, n) + mtr_2.get(m, n));
		
	
	return matr_3;
}

Matrix operator -(Matrix mtr_1, Matrix mtr_2)
{
	Matrix matr_3(mtr_1.total_rows(), mtr_2.total_columns());
	
	if(mtr_1.total_rows() != mtr_2.total_rows() || mtr_1.total_columns() != mtr_2.total_columns())
	{
		std::cout << "Matrix addition is impossible" << std::endl;
		exit(EXIT_FAILURE);
		return matr_3;
	}
	
	for(int m = 0; m < mtr_1.total_rows(); m++)
		for(int n = 0; n < mtr_1.total_columns(); n++)
			matr_3.push(m, n, mtr_1.get(m, n) - mtr_2.get(m, n));
		
	
	return matr_3;
}

Matrix operator *(int a, Matrix mtr)
{
	Matrix mtr_out(mtr.total_rows(), mtr.total_columns());
	
	for(int m = 0; m < mtr.total_rows(); m++)
		for(int n = 0; n < mtr.total_columns(); n++)
			mtr_out.push(m, n, a*mtr.get(m, n));
	
	return mtr_out;
}
