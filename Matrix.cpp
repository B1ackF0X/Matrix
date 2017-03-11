#include <iostream>
#include <iomanip>
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

