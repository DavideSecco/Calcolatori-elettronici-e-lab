#include "stdio.h"

__declspec(naked) int sommavett(int *p, int l) {
	
	__asm {
		Push ebp
		Mov ebp, esp

		// Eventuale dichiarazione di 2 variabili locali
		
		Sub esp, 8

		// SALVATAGGIO REGISTRI CDECL
		
		Push esi 	
		Push edi
		Push ebx
		
		// CORPO della funzione in cui i parametri sono in[EBP + 8] primo parametro[EBP + 12] secondo parametro ecc….

		/*Le variabili locali sono aree di memoria sullo stack accessibili a[EBP - 4] prima variabile[EBP - 8] seconda ecc….E sono grandi 4 BYTE
		%parte finale della funzione recupero e ripristino i registri e ripristino lo stack*/

		mov ecx, dword ptr[EBP + 8]			//salvo *p

		mov esi, 0
		mov eax, 0

		ciclo:
			cmp esi, dword ptr[EBP + 12]	// confronto con l
			je fine
			add eax, dword ptr[ecx + esi*4]
			inc esi
			jmp ciclo

		fine:

		
		
		// Ripristino i registri
		Pop EBX 
		Pop edi
		Pop ESI
		Mov ESP, EBP	// ripristino lo stack
		Pop EBP			// ripristino EBP del Chiamante
		Ret				// recupero EIP dallo stack
	}

}

int main()
{
	int vet[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("la somma di ogni vettore e' %d", sommavett(vet, 10));
	getchar();
}