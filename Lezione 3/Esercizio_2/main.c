#include "stdio.h"

//Prodotto fra due numeri CON SEGNO
// DA FAREEEEE

int f (int a, int b)
{
	int c;
	__asm {
		mov eax, a
		mov ebx, b
		mov ecx, 0
		mov edx, 0

		cmp eax, 0
		jl negate_a			// se eax < 0 --> negalo
		comeback_a :
		cmp ebx, 0
		jl negate_b			// se ebx < 0 --> negalo
		comeback_b :

		// a questo punto mi troverò con i due numeri SICURAMENTE POSITIVI

	start:
			cmp ebx, 0
			je end			// se ebx == 0 --> FINE
			add edx, eax	// altrimenti edx = edx + eax (edx = 0 all'inzio)
			sub ebx, 1		// ebx = ebx - 1
			jmp start

				// Qui avrò calcolcolato il valore assuluto del risultato ( in edx )

			negate_a :
				neg eax			// nego eax
				inc ecx			// ecx = ecx + 1 (serve per il segno finale)
				jmp comeback_a	// torno indietro

			negate_b :
				neg ebx			// nego eax
				inc ecx			// ecx = ecx + 1 (serve per il segno finale)
				jmp comeback_b	// torno indietro

			negate_one_more_time :
				neg edx			// nego edx
				jmp come_here	// vado alla fine

			end :
				cmp ecx, 1
				je negate_one_more_time		// se ecx == 1 --> devo cambiare segno e vado a negare edx
				//cmp ecx, 2				// Da eliminare....
				//je negate_one_more_time

			come_here :
				mov c, edx

		}
	return c;
}

int main()
{
	int a0 = 0, b0 = 7;
	int a1 = 5, b1 = 0;
	int a2 = 0, b2 = 0;
	int a3 = -5, b3 = -7;
	int c;

	
	c = f(a0, b0);
	printf("il prodotto fra %d e %d e' %d\n", a0, b0, c);

	c = f(a1, b1);
	printf("il prodotto fra %d e %d e' %d\n", a1, b1, c);

	c = f(a2, b2);
	printf("il prodotto fra %d e %d e' %d\n", a2, b2, c);

	c = f(a3, b3);
	printf("il prodotto fra %d e %d e' %d\n", a3, b3, c);
}