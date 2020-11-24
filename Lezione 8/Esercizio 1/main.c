#include <stdio.h>

// La stringa è palindroma? 1 -> è palindroma, 0 -> non è palindroma

int palindromo(char*);

int main()
{
	char str[] = "amggamma";

	printf("la stringa è palindroma %d", palindromo(str));

	getchar();
}