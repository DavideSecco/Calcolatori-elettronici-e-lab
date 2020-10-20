#include <stdio.h>
#include <stdlib.h>

// Esercizio: conta le consonanti (minuscole) di una stringa

int main()
{
	char str[255] = "ingegneria&$ []informatica fa schifo";
	int num = 0;

	char* p;

	p = &str[0];

	__asm
	{
			mov eax, p // Riferimento alla stringa
			mov esi, -1
			mov edi, 0 // conta le consonanti

		ciclo:
			inc esi
			mov bl, byte ptr[eax + esi] // uso bl e byte ptr perchè leggo un solo byte!
			cmp bl, 0
			je fine

			cmp bl, 65
			jl ciclo

			cmp bl, 122
			jg ciclo 
		
		in_mezzo:				/*piuttossto che fare così ricopia il pezzo per le minuscole (e l'intervallo) e lo ricopio mettendo a posto intervallo e lettere*/
			cmp bl, 96
			jg confronti
			cmp bl, 91
			jl confronti
			jmp ciclo

		confronti:
			cmp bl, 'a'
			je incrementa
			cmp bl, 'e'
			je incrementa
			cmp bl, 'i'
			je incrementa
			cmp bl, 'o'
			je incrementa
			cmp bl, 'u'
			je incrementa
			
			cmp bl, 'A'
			je incrementa
			cmp bl, 'E'
			je incrementa
			cmp bl, 'I'
			je incrementa
			cmp bl, 'O'
			je incrementa
			cmp bl, 'U'
			je incrementa
			cmp bl, ' '
			je incrementa

			inc edi
			jmp ciclo

		incrementa :
			jmp ciclo

		fine :
			mov num, edi
	}

	printf("Le consonanti sono: %d", num);
	getchar();
}