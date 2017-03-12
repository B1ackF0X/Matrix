class Matrix
{
	public:
			Matrix(unsigned m, unsigned n);
			unsigned total_rows();
			unsigned total_columns();
			int get(unsigned row, unsigned column);
			void push(unsigned row, unsigned column, int value);
			void show();

	private:
			unsigned m;
			unsigned n;
			int **Matr;
};

void operator <<(Matrix Matr, int x[]);
Matrix operator *(Matrix mtr_1, Matrix mtr_2);
Matrix operator +(Matrix mtr_1, Matrix mtr_2);
Matrix operator -(Matrix mtr_1, Matrix mtr_2);
Matrix operator *(int a, Matrix mtr);
