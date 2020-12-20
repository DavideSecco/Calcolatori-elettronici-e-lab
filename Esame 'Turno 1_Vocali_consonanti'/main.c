#include "stdio.h"

int conta_vocali_consonanti(unsigned char* src, int* dstV, int* dstC);

int main() {
	char src[255] = "aa";
	int dstV;
	int dstC;
	int ret;

	ret = conta_vocali_consonanti(src, &dstV, &dstC);

	printf("Vocali = %d, Consanti = %d\n ", dstV, dstC);

	getchar();
}