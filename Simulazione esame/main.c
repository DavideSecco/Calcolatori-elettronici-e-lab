#include <stdio.h>
#include <stdlib.h> 

int cerca_combinazioni_numero(char* str, int num, int* vett);

int cerca_combinazioni_numero_1(char* str, int num, int* vett) { 
	int i = 0;
	char d = num + '0';
	vett[0] = 0;
	vett[1] = 0;
	vett[2] = 0; 
	while (1) {
		if (str[i] == 0)
			break;
		if (d == str[i]) {
			if (str[i + 1] == 0 || str[i + 1] != d) {
				vett[0]++;
				i++;
			} 
			else {
				if (str[i + 2] == 0 || str[i + 2] != d) {
					vett[1]++;
					i = i + 2;
				} 
				else { 
					vett[2]++;
					i = i + 3;
				}
			}
		}
		else
			i++; 
	}    
	return 0; 
} 

int main() {
	char str[255] = "ci1ao 11 com1 e sta111 viva 11";
	int vett[3];
	int vett_2[3];
	int i = 0;

	cerca_combinazioni_numero_1(str, 1, vett);
	cerca_combinazioni_numero(str, 1, vett_2);

	printf("TEST1\n");
	for (i = 0; i < 3; i++) {
		if (vett[i] != vett_2[i]) {
			return(-2);
			printf("aaaaa");
		}
			
	}

	getchar();
	return(0);
}
