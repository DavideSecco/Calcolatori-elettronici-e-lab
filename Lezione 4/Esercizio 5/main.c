#include <stdio.h>
#include <stdlib.h>

// Esercizio: conta le parole (ci possono essere due spazi fra una parola e l'altra)

void f(char* s) {
	int num = 0;
	char* p;
	p = &s[0];
	
	__asm
	{
		mov eax, p		// Riferimento alla stringa
		mov esi, 0		// indice stringa
		mov edi, 0		// Conta parole

		mov bl, byte ptr[eax]	// uso bl e byte ptr perchè leggo un solo byte!
		cmp bl, 0				
		je fine					// controllo che la stringa non sia null

		// scorro tutti gli spazi finchè non incotro una lettera
		salta_spazi :			
			cmp bl, ' '
			jne incremento					// se non è uno spazio --> incremento il contatore delle parole e sono in una parola altrimenti rimango qui
			inc esi
			mov bl, byte ptr[eax + esi]		// mi muovo nella stringa
			cmp bl, 0			
			je fine							// controllo di non essere in fondo e ricomicio
			jmp salta_spazi

		incremento :						// funzione a cui salto dopo che da uno spazio trovo un carattere --> incremento il contatore
			inc edi

		// funzione che scorre la parola
		parola :
			cmp bl, ' '
			je salta_spazi					// trovo uno spazio --> salto alla funzione funzione salta_spazi
			inc esi
			mov bl, byte ptr[eax + esi]		// scorro la stringa
			cmp bl, 0						
			je fine							// controllo di non essere arrivato in fondo e ricomicio
			jmp parola

		fine :
			mov num, edi

	}

	printf(" frase: '%s' \n parole: %d\n", s, num);
}

int main()
{
	char str0[255] = "ingegneria informatica fa schifo";
	char str1[255] = " ingegneria  informatica fa schifo";
	char str2[255] = " ingegneria  informatica fa schifo ";
	char str3[255] = "   ingegneria    informatica   fa   schifo     ";
	char str4[255] = "ingegneria";
	char str5[255] = " ingegneria ";
	char str6[255] = "";
	
	f(str0);
	f(str1);
	f(str2);
	f(str3);
	f(str4);
	f(str5);
	f(str6);

	getchar();
}