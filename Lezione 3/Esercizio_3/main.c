#include "stdio.h"

// confronta a[i] e b[i]:
// se a[i]>=b[i] -> c[i]=1
// se a[i]<b[i] -> non fai nulla

int main() {
	int a[5] = { 1,2,3,4,5 };
	int b[5] = { 1, -10, 128, -5, 4 };
	int c[5] = { 0,0,0,0,0 };

	int* p1, p2, p3;
	p1 = &a[0];
	p2 = &b[0];
	p3 = &c[0];

	__asm {
			mov eax, p1
			mov ebx, p2
			mov ecx, p3
			
			mov edi, 0
		
		inizio:
			mov edx, dword ptr[eax + edi * 4]
			cmp edx, dword ptr[ebx + edi * 4]
			jge metti_a_1
		incremento_e_confronto:
			add edi, 1
			cmp edi, 4
			jg fine
			jmp inizio 
			

		metti_a_1:
			mov dword ptr[ecx + edi * 4], 1
			jmp incremento_e_confronto

		fine:

	}

	for (int i = 0; i < 5; i++)
		printf("a = %d b = %d -> c = %d \n", a[i], b[i], c[i]);
}