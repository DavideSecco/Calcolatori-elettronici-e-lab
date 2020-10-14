#include "stdio.h"

//Prodotto fra due numeri SENZA SEGNO

int main()
{
	unsigned int a=5, b = 7;
	unsigned int c;
	
	__asm {
		mov eax, a
		mov ebx, b

		mov edi, 0 //si può far senza questo registro
		mov ecx, 0

		Ciclo:
		cmp edi, eax
		jae fine
		add ecx, ebx
		add edi, 1
		jmp Ciclo

		fine:
		mov c, ecx
	}

	printf("il prodotto fra %d e %d e' %d", a, b, c);
}