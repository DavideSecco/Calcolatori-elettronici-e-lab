#include "stdio.h"

int moltiplica_con_segno(int a, int b);

int main()
{
	int c, a, b;
	a = 2;
	b = 3;
	c = moltiplica_con_segno(a, b);
	printf("%d * %d = %d\n", a, b, c);

	a = -2;
	b = 3;
	c = moltiplica_con_segno(a, b);
	printf("%d * %d = %d\n", a, b, c);

	a = 2;
	b = -3;
	c = moltiplica_con_segno(a, b);
	printf("%d * %d = %d\n", a, b, c);

	a = -2;
	b = -3;
	c = moltiplica_con_segno(a, b);
	printf("%d * %d = %d\n", a, b, c);

	getchar();
}