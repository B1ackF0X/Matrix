#include "Matrix.h"

int main(void)
{
	Matrix m(3, 3);
	int a[] = {6, 5, 2,
			   6, 3, 4};
	
	m << a;
	m.show();
	
	return 0;
}
