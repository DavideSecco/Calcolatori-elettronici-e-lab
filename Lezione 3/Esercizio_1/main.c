#include "stdio.h"

//Prodotto fra due numeri SENZA SEGNO

int main()
{
	unsigned int a=5, b = 7;
	unsigned int c;
	
	__asm {
		mov eax, a
		mov ebx, b

		mov edi, 0 //si pu� far senza questo registro
		mov ecx, 0

		Ciclo:
		cmp eax, 0
		je fine
		add ecx, ebx
		dec eax
		jmp Ciclo

		fine:
		mov c, ecx
	}

	printf("il prodotto fra %d e %d e' %d", a, b, c);
	getchar();
}