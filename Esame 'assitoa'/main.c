#include <stdio.h>

int assitoa(int src, int sgn, char* stringa);

int main() {
	char src[255];
	int ret;

	ret = assitoa(123, 0, src);

	printf("%s", src);

	getchar();
}