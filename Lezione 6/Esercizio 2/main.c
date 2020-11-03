#include "stdio.h"

// contare quanti numeri pari ci sono nel vettore


__declspec(naked) int num_pari(char* v, int lunghezza) {

	__asm {
		Push ebp
		Mov ebp, esp
		
		Sub esp, 8
		Push esi 		
		Push edi
		Push ebx

		Mov ebx, dword ptr [ebp + 8] //indirizzo
		mov dl, 2					// = 2
		mov edi, 0					// contatore del ciclo
		mov eax, 0							
		mov ecx, 0					

		ciclo:
			Cmp ecx, dword ptr[EBP + 12]
			je fine
			mov al, byte ptr[ebx + ecx]

		divisione:
			cbw						// mette a post edx
			idiv dl
			Cmp edx, 0
			je incrementa
		
		ritorno:
			inc ecx
			jmp ciclo

		incrementa: 
			inc edi
			jmp ritorno
			
		mov eax, edx
			fine :

		Pop EBX			// Ripristino i registri
			Pop edi
			Pop ESI
			Mov ESP, EBP	// ripristino lo stack
			Pop EBP			// ripristino EBP del Chiamante
			Ret				// recupero EIP dallo stack

	}
}

int main() {

	unsigned char v[10] = { 1,2,3,4,5,6,7,8,9,10 };

	printf("Il numero di numeri pari e' %d", num_pari(v, 10));

	getchar();
}