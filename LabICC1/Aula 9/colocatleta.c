#include <stdio.h>
#include <stdlib.h>

void bubble(int n, int *vetor);
void resultados(int n, int *corredores, int *colocacao);

int main(void){
	int corredores[100] = {0}, colocacao[100] = {0}, cont, n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &corredores[i]);
		for(cont=0;cont<n;cont++){
			if(corredores[i]==colocacao[cont]) 
				break;
		}
		if(corredores[i]!=colocacao[cont]){
			colocacao[i]=corredores[i];
		}
	}
	bubble(n, colocacao);
	resultados(n, corredores, colocacao);
	return 0;
}

void bubble(int n, int *vetor){
	int temp, troca = 1;
	while(troca){
		troca = 0;
		for(int i=0;i<n;i++){
			if(vetor[i]<vetor[i+1]){
				temp = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = temp;
				troca = 1;
			}
		}
	}
}
//teste
void resultados(int n, int *corredores, int *colocacao){
	for(int i=0;i<n;i++){
		for(int j=0;colocacao[j]!=0;j++){
			if(corredores[i]==colocacao[j]){
				printf("%dº Atleta, %d Pontos, %dº Colocado\n", i+1, corredores[i],j+1);
				break;
			}
		}
	}
}