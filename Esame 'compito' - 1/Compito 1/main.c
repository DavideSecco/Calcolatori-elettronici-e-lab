#include "stdio.h"

//esercizio molto importante!!! riguardalo!

int togli_dispari(unsigned char* src, int lunghezza);

int main() {
	unsigned char src[6] = { 2,3,4,4,5,8 };
	int ret = togli_dispari(src, 6);
	printf("%d \n", ret);
	for (int i = 0; i < 6; i++)
		printf("%d", src[i]);

	getchar();
}