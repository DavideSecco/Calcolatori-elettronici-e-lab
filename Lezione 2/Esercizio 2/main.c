#include <stdio.h>
#include <stdlib.h>

//riscrivi "Margherita" con una M  e A finale maiuscole

int main()
{
	char vet[11] = "margherita";
	char *p;

	p = &vet[0]; //perchè non avresti saputo l'indirizzo di 32

	__asm {
		mov ebx, p

		mov edi, 0
		sub [ebx+edi * 1], 32

		mov edi, 9
		sub [ebx + edi * 1], 32
		

	}

	printf("%s", vet);
	getchar();
}