#include <stdio.h>
#include <stdlib.h>

void detetive(int x);
int main(void){
	int n;
	scanf("%d", &n);
	detetive(n);
	return 0;
}

void detetive(int x){
	int valor, vetor[x];
	for(int i=0;i<x-1;i++){
	    scanf("%d", &valor);
		vetor[valor-1]=1;
	}
	for(int j=0;j<x;j++){
		if(vetor[j]==0) printf("Numero desaparecido: %d\n", j+1);
	}
	return;
}
	