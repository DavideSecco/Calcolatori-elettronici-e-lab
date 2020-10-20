#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[255] = "Ingegneria Informatica fa schifo";
	int num = 0;

	char* p;

	p = &str[0];
	
	__asm
	{
			mov eax, p
			mov esi, 0

		ciclo:
			mov bl, byte ptr [eax + esi] // uso bl e byte ptr perchè leggo un solo byte!
			cmp bl, 0
			je fine

			inc esi
			jmp ciclo

		fine:
			mov num, esi
	}

	printf("la lunghezza e' %d", num);
	getchar();
}