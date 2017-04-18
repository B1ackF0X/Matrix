#include <iostream>
#include <iomanip>
#include <cstdlib>

template <typename T> class Matrix
{
	public:
			Matrix(unsigned m, unsigned n);
			unsigned total_rows();
			unsigned total_columns();
			T get(unsigned row, unsigned column);
			void push(unsigned row, unsigned column, T value);
			void show();

	private:
			unsigned m;
			unsigned n;
			T **Matr;
};

template <typename T> Matrix<T>::Matrix(unsigned m, unsigned n)
{
	this->m = m;
	this->n = n;
				
	Matr = new T*[m];
	
	for(int i = 0; i < m; i++)
		Matr[i] = new T[n];
					
	for(int count_row = 0; count_row < m; count_row++)
		for(int count_column = 0; count_column < n; count_column++)
			Matr[count_row][count_column] = 0.0;
}

template <typename T> unsigned Matrix<T>::total_rows()
{
	return m;
}

template <typename T> unsigned Matrix<T>::total_columns()
{
	return n;
}

template <typename T> T Matrix<T>::get(unsigned row, unsigned column)
{
	return Matr[row][column];
}

template <typename T> void Matrix<T>::push(unsigned row, unsigned column, T value)
{
	Matr[row][column] = value;
}

template <typename T> void Matrix<T>::show()
{
	for(int count_row = 0; count_row < m; count_row++)
	{
		std::cout << std::endl;
		for(int count_column = 0; count_column < n; count_column++)
			std::cout << std::setw(3) << Matr[count_row][count_column] << "    ";
	}
	
	std::cout << std::endl;
}

template <typename T> void operator <<(Matrix<T> Matr, T x[])
{
	for(int count_row = 0; count_row < Matr.total_rows(); count_row++)
		for(int count_column = 0; count_column < Matr.total_columns(); count_column++)
			Matr.push(count_row, count_column, x[count_row * Matr.total_columns() + count_column]);
}

template <typename T> void operator <<(Matrix<T> Matr_1, Matrix<T> Matr_2)
{
	if(Matr_1.total_rows() != Matr_2.total_rows() || Matr_1.total_columns() != Matr_2.total_columns())
	{
		std::cout << "Matrix copying is impossible" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	for(int count_row = 0; count_row < Matr_1.total_rows(); count_row++)
		for(int count_column = 0; count_column < Matr_1.total_columns(); count_column++)
			Matr_1.push(count_row, count_column, Matr_2.get(count_row, count_column));
}

template <typename T> Matrix<T> operator *(Matrix<T> mtr_1, Matrix<T> mtr_2)
{
	T s = .0;
	Matrix<T> matr_3(mtr_1.total_rows(), mtr_2.total_columns());
	
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

template <typename T> Matrix<T> operator +(Matrix<T> mtr_1, Matrix<T> mtr_2)
{
	Matrix<T> matr_3(mtr_1.total_rows(), mtr_2.total_columns());
	
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

template <typename T> Matrix<T> operator -(Matrix<T> mtr_1, Matrix<T> mtr_2)
{
	Matrix<T> matr_3(mtr_1.total_rows(), mtr_2.total_columns());
	
	if(mtr_1.total_rows() != mtr_2.total_rows() || mtr_1.total_columns() != mtr_2.total_columns())
	{
		std::cout << "Matrix subtraction is impossible" << std::endl;
		exit(EXIT_FAILURE);
		return matr_3;
	}
	
	for(int m = 0; m < mtr_1.total_rows(); m++)
		for(int n = 0; n < mtr_1.total_columns(); n++)
			matr_3.push(m, n, mtr_1.get(m, n) - mtr_2.get(m, n));
		
	
	return matr_3;
}

template <typename T1, typename T2> Matrix<T1> operator *(T2 a, Matrix<T1> mtr)
{
	Matrix<T1> mtr_out(mtr.total_rows(), mtr.total_columns());
	
	for(int m = 0; m < mtr.total_rows(); m++)
		for(int n = 0; n < mtr.total_columns(); n++)
			mtr_out.push(m, n, a*mtr.get(m, n));
	
	return mtr_out;
}
