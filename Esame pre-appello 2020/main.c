#include <stdio.h>

int elimina_doppie(char* str, char lettera);

int main() {
	char str[255] = "l lll ll ll llllll aa aaa llll ";
	int ret;
	ret = elimina_doppie(str, 'l');

	printf("%s", str);

	getchar();
}