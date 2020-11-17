// il file .ams può chiamarsi come il file .c

#include <stdio.h>

int sommavett(int* a, int *b, int lunghezza);

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int b[10] = { 1,2,3,4,5,6,7,8,9,10 };

	printf("%d", sommavett(a,b, 10));

}