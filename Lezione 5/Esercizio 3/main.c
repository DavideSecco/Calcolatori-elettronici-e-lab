#include "stdio.h"

// Trasforma un frase da minuscola a maiuscola

__declspec(naked) void convertmaius(char *p) {

	__asm {
		Push ebp
		Mov ebp, esp

		// SALVATAGGIO REGISTRI CDECL

		Push esi
		Push edi
		Push ebx

		// CORPO della funzione in cui i parametri sono in[EBP + 8] primo parametro[EBP + 12] secondo parametro ecc….

		/*Le variabili locali sono aree di memoria sullo stack accessibili a[EBP - 4] prima variabile[EBP - 8] seconda ecc….E sono grandi 4 BYTE
		%parte finale della funzione recupero e ripristino i registri e ripristino lo stack*/

		mov ecx, dword ptr[EBP + 8]			//salvo *p
		mov esi, -1

		ciclo:

			inc esi
			//controllo di non essere alla fine
			cmp byte ptr[ecx + esi], 0
			je fine

			cmp byte ptr[ecx + esi], ' '
			je ciclo
			
			sub byte ptr[ecx + esi], 32
			jmp ciclo

			fine :



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
	char vet[] = "la mamma di tua mamma e' tua nonna";
	convertmaius(vet);
	printf("%s", vet);
	getchar();
}