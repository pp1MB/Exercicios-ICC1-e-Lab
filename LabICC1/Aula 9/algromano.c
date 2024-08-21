#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inteiroParaRomano(int x);
int main(void){
	int n, verif, numero;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &numero);
		inteiroParaRomano(numero);
	}
	return 0;
}

void inteiroParaRomano(int x){
    int romano[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char *romano2[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	for(int j=0;j<13;j++){
		for(int k=x/romano[j];k>0;k--){
			printf("%s", romano2[j]);
		}
		x%=romano[j];
	}
    printf("\n");
	return;
}