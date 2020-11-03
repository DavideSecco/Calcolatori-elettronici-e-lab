#include "stdio.h"

// trasforma una stringa di char in int (funzione "atoi")


__declspec(naked) unsigned int atoi(char* v) {

	__asm {
		Push ebp
		Mov ebp, esp
		
		Sub esp, 8
		Push esi 		
		Push edi
		Push ebx

		mov eax, 1						// uso per le somme singole e per il risultato finalissimo 
		mov ebx, dword ptr[ebp + 8]		// indirizzo del vettore
		mov ecx, 0						// uso per le somme parziali
		mov edi, 0						// contatore della stringa
		mov esi, 0						// per gli esponenti!!!
		
		
		mov edx, 0						// NON USAREEEEE

	// arrivo alla fine della stringa:
	ciclo_1:
		cmp [ebx + edi], 0
		je ciclo_2
		inc edi
		jmp ciclo_1

	ciclo_2: 
		Sub edi, 1
		mov esi, edi
		push edi					// metto edi nello stack [-24]
		push 10 

	singolo_fattore :
		push eax						// metto la potenza del 10 in sullo stack	[-28]
		mov eax, 0
		mov al, byte ptr[ebx + esi]		// metto il numero in eax
		sub al, 48
		Mul dword ptr[ebp - 32]		// moltiplico
		Add ecx, eax
		pop eax

		sub esi, 1					// torno indietro nella stringa
		cmp esi, -1
		mov edi, esi
		je fine

		mov eax, 1
	calcolo_esponente:
		cmp edi, dword ptr[ebp - 24]
		// mov dword ptr[ebp -28], 10
		je singolo_fattore
		mul dword ptr[ebp - 28]
		inc edi
		jmp calcolo_esponente

	fine:
		mov eax, ecx

	
		Pop ebx
		Pop edi
		Pop ESI
		Mov ESP, EBP	// ripristino lo stack
		Pop EBP			// ripristino EBP del Chiamante
		Ret				// recupero EIP dallo stack

	}
}

int main() {

	unsigned char v[10] = "100000";

	printf("%d", atoi(v));

	getchar();
}