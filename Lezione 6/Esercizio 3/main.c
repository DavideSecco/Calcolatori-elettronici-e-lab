#include "stdio.h"

// calcola il fattoriale di un numero

__declspec(naked) int fattoriale(int n) {

	__asm {
		Push ebp
		Mov ebp, esp

		Sub esp, 8
		Push esi
		Push edi
		Push ebx

		mov ecx, dword ptr[ebp + 8]		//numero
		mov edi, 1						// contatore

		ciclo:
		cmp ecx, edi
		je fine

		mul edi
		inc edi
		jmp ciclo

		fine:
		

		Pop EBX			// Ripristino i registri
			Pop edi
			Pop ESI
			Mov ESP, EBP	// ripristino lo stack
			Pop EBP			// ripristino EBP del Chiamante
			Ret				// recupero EIP dallo stack

	}
}

int main() {

	int n = 8;

	printf("il fattoriale e' %d", fattoriale(n));

	getchar();
}
