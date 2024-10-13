#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N, cont, impar=0;
	char palavra[100000], repetida[100000];

	scanf("%d", &N);
	scanf("%s", palavra);

	for(int i=0;i<N;i++){
		cont = 0;
		if(repetida[i]!=1){
			cont = 1;
			for(int j=0;j<N;j++){
				if(palavra[i]==palavra[j] && j!=i){
					repetida[j]=1;
					cont++;
				}
			}
		}

		if(cont%2!=0){
			if(N%2==0){
				printf("Nao\n");
				cont = -1;
				break;
			} else {
				if(impar==0){
					impar=1;
				} else {
					printf("Nao\n");
					cont = -1;
					break;
				}
			}
		}
	}
	if(cont!=-1) printf("Sim\n");

	return 0;
}