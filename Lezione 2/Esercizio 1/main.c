#include <stdio.h>
#include <stdlib.h>

//leggo gli elementi di posizione 0 e 4 del vettore con indirizzamento base + indice*scala

int main()
{
	int *p;
	int somma = 90;
	int vet[5] = { 1,2,3,4,5 };

	p = &vet[0]; //perchè non avresti saputo l'indirizzo di 32

	__asm {
		//passo dalle variabili c ai registri
		mov ebx, p

		mov eax, dword ptr[ebx+4*0]
		add eax, dword ptr[ebx+4*4]

		mov ecx, eax
		//passo dai registri alle varibili c
		mov somma, ecx		
	}

	printf("%d", somma);
	getchar();
}