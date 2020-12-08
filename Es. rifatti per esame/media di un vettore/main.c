#include "stdio.h"

int media_vettore(int* v, int size);

int main() {
	int v[] = { 1,2,3,4 };
	int size = sizeof(v) / sizeof(int);
	printf("media: %d", media_vettore(v, size));
	getchar();
}