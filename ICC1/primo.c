#include <stdio.h>
#include <stdlib.h>

int main(void){
	int Q, N, cont, numeros[1500001];

	//Todos são primos até que se prove o contrário
	for(int i=0;i<=1500000;i++){
		numeros[i] = 1;
	}

	//Crivo
	for(int i=2;i<=1500000;i++){
		if(numeros[i]==1){
			for(int j=i+i;j<=1500000;j+=i){
				numeros[j]=0;
			}
		}
	}
	///////////////////////////////////////////
	scanf("%d", &Q);
	for(int i=0;i<Q;i++){
		scanf("%d", &N);
		if(numeros[N]==1){
			printf("Sim\n");
		} else printf("Nao\n");
	}
	return 0;
}