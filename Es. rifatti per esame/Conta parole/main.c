#include "stdio.h"

int conta_parole(char* frase);

int main(){
	char* frase;
	int n;

	frase = "  ciao come va    ";
	n = conta_parole(frase);
	printf("la frase: %s ha %d parole", frase, n);

	getchar();
}