class Matrix
{
    public:
            Matrix(unsigned m, unsigned n);
            unsigned total_rows();
            unsigned total_columns();
            void push(unsigned row, unsigned column, int value);
            void show();

    private:
            unsigned m;
            unsigned n;
            int **Matr;
};

void operator <<(Matrix Matr, int x[]);
