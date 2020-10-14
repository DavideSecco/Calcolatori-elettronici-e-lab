#include "stdio.h"

//Prodotto fra due numeri CON SEGNO
// DA FAREEEEE

int main()
{
	int a = -5, b = 7;
	int c;

	__asm {
		mov eax, a
		mov ebx, b

		mov edi, 0  //si può far senza questo registro
		mov ecx, 0

		Ciclo:
		je edi, 0
		cmp edi, eax
		jge fine
		neg eax
		cmp edi, eax
		jge fine
		add ecx, ebx
		add edi, 1
		jmp Ciclo

		fine :
		mov c, ecx
	}

	printf("il prodotto fra %d e %d e' %d", a, b, c);
}