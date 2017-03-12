#include <iostream>
#include "Matrix.h"

int main(void)
{
	Matrix m(3, 3);
	Matrix n(3, 3);
	
	int a[] = {6, 5, 2,
			   6, 3, 4,
			   2, 0, 1};
	
	m << a;
	m.show();
	
	int b[] = {4, 5, 2,
			   2, 1, 9,
			   3, 4, 2};
	n << b;
	n.show();
	
	(m*n).show();
	(n+m).show();
	(m-n).show();
	(4*m).show();
	
	return 0;
}
