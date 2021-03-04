#include <stdio.h>

// La stringa � palindroma? 1 -> � palindroma, 0 -> non � palindroma

int palindromo(char*);

int main()
{
	char str[] = "amggamma";

	printf("la stringa � palindroma %d", palindromo(str));

	return 0;