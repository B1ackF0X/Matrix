#include <iostream>
#include "Matrix.h"

int main(void)
{
	Matrix<double> m(3, 3);
	Matrix<double> n(3, 3);
	
	double a[] = {6, 5.23, 2.45,
		      6,    3,    4,
		      2, 0.14,    1};
	
	m << a;
	m.show();
	
	double b[] = {4,    5,    2,
		      2.99, 1, 9.32,
		      3, 4.23,    2};
	n << b;
	n.show();
	
	(m*n).show();
	(n+m).show();
	(m-n).show();
	(4.5*m).show();
	
	m << n;
	m.show();
	
	return 0;
}
