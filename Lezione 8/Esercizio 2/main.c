#include <stdio.h>
/*
conta quante volta c'� una parola
1. non � mai la prima
2. non � mai lultima
3. il separatore � uno spazio
caccacacca non vale
*/
int conta_occorrenze(char* str, char* parola);


int main()

{
	char str2[256] = "w la cacca per la cacca caccacacca noi siamo automobili";
	char parola[256] = "cacca";



	printf("il numero di occorrenze � %d", conta_occorrenze(str2, parola));
	getchar();
}
	
