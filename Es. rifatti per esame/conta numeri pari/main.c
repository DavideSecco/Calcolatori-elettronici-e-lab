#include "stdio.h"

int numeri_pari(int* v, int size);

int main() {
	int v[] = { 1,2,3 };
	int n = sizeof(v) / sizeof(int);
	printf("i n pari sono: %d", numeri_pari(v,n));
	
	getchar();
}