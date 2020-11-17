#include <stdio.h>

// si realizzi una funzione che mette in b[i] 1 se a[i] è primo 0 altrimenti
// la funzione ritorna quanti numeri prim ci sono nel vettore a
// non c'è mai 1 

int primo(int* a, int *b, int lunghezza);

int main()
{
	int a[10] = { 3,4,5,6,7,8,9,10,11,12 };
	int b[10] = { 0,0,0,0,0,0,0,0,0,0 };

	printf("%d\n", primo(a,b, 10));
	for(int i = 0; i < 10; i++) {
		printf("%d --> %d \n", a[i], b[i]);
	}
	getchar();
}