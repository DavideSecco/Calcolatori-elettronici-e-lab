#include <stdio.h>
#include <stdlib.h>

// Esercizio: conta le vocali di una stringa

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
		mov edi, 0

		ciclo:
			mov bl, byte ptr[eax + esi] // uso bl e byte ptr perchè leggo un solo byte!
			cmp bl, 0
			je fine
			cmp bl, 'a'
			je incrementa
			cmp bl, 'e'
			je incrementa
			cmp bl, 'i'
			je incrementa
			cmp bl, 'o'
			je incrementa
			cmp bl, 'u'
			je incrementa
			cmp bl, 'A'
			je incrementa
			cmp bl, 'E'
			je incrementa
			cmp bl, 'I'
			je incrementa
			cmp bl, 'O'
			je incrementa
			cmp bl, 'U'
			je incrementa

			inc esi
			jmp ciclo
		
		incrementa:
			inc esi
			inc edi
			jmp ciclo

		fine:
			mov num, edi
	}

	printf("Le vocali sono: %d", num);
	getchar();
}