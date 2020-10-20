#include <stdio.h>
#include <stdlib.h>

// Esercizio: nella stringa cambia le consonanti minuscole con maiuscole

int main()
{
	char str[255] = "ingegneria informatica fa schifo";
	int num = 0;

	char* p;

	p = &str[0];

	__asm
	{
		mov eax, p // Riferimento alla stringa
		mov esi, -1 

		ciclo:
			inc esi
			mov bl, byte ptr[eax + esi] // uso bl e byte ptr perchè leggo un solo byte!
			cmp bl, 0
			je fine

			cmp bl, 97
			jl ciclo

			cmp bl, 122
			jg ciclo

			cmp bl, 'a'
			je ciclo
			cmp bl, 'e'
			je ciclo
			cmp bl, 'i'
			je ciclo
			cmp bl, 'o'
			je ciclo
			cmp bl, 'u'
			je ciclo

		cambia:
			Sub bl, 32
			mov byte ptr[eax + esi], bl
			jmp ciclo

		fine :
			mov num, edi
	}

	printf("%s", str);
	getchar();
}