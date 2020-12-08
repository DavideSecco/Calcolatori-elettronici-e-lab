#include "stdio.h"

// Calcola la media di un vettore

__declspec(naked) int media(int* v, int lunghezza) {

	__asm {
		Push ebp
		Mov ebp, esp
		
		Sub esp, 8
		Push esi 		
		Push edi
		Push ebx
		
		Mov ecx, dword ptr[EBP + 8] // indirizzo
		Mov ebx, dword ptr[EBP + 12] // lunghezza 
		mov eax, 0

		mov edi, 0

		ciclo:
			Cmp ebx, edi
			je divisione

			Add eax, dword ptr[ecx + edi*4]
			inc edi
			jmp ciclo

		divisione:
			cdq				// mette a post edx
			idiv ebx

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

	int v[10] = { 1,2,3,4,5,6,7,8,9,10 };
	
	printf("la media e' %d", media(v, 10));
	
	getchar();
}