#include "stdio.h"

int divisione_array(int* src, int divisore, int lunghezza, int* resto);

int main() {
	int v[3] = { 3,3,3 };
	int resto[3];
	int n = divisione_array(v, 3, 3, resto);
	printf("%d \n", n);
	printf("%d %d %d \n", v[0], v[1], v[2]);
	printf("%d %d %d \n", resto[0], resto[1], resto[2]);

	getchar();
}