#include <stdio.h>
#include <stdlib.h>

void lerMatriz(int *linha, int *coluna, char matriz[*linha][*coluna], int *cosplay_linha, int *cosplay_coluna);
void printMatriz(int *linha, int *coluna, char matriz[*linha][*coluna], int *cosplay_linha, int *cosplay_coluna);

int main(void){
	char plateia[20][20];
	int cosplay_linha[20] = {0}, cosplay_coluna[20] = {0};
	int N, M;
	scanf("%d %d", &N, &M);
	lerMatriz(&N, &M, plateia, cosplay_linha, cosplay_coluna);
	printMatriz(&N, &M, plateia, cosplay_linha, cosplay_coluna);

	return 0;
}

void lerMatriz(int *linha, int *coluna, char matriz[*linha][*coluna], int *cosplay_linha, int *cosplay_coluna){
	for(int i=0;i<*linha;i++){
		for(int j=0;j<*coluna;j++){
			scanf(" %c", &matriz[i][j]);

			// Marcar Linhas e Colunas de Cosplayers
			if(matriz[i][j]=='c'){
				cosplay_linha[i]=1;
				cosplay_coluna[j]=1;
			}
		}
	}
	return;
}

void printMatriz(int *linha, int *coluna, char matriz[*linha][*coluna], int *cosplay_linha, int *cosplay_coluna){
	int sem_lugar = 1;

	// Mudar a matriz mostrando os lugares disponíveis
	for(int i=0;i<*linha;i++){
		for(int j=0;j<*coluna;j++){
			if(matriz[i][j]=='v' && cosplay_linha[i]==0 && cosplay_coluna[j]==0){
				//Checando para Cosplayers na linha e/ou coluna
				matriz[i][j]='o';
				sem_lugar = 0;
			}
			else {
				matriz[i][j]='x';
			}
		}
	}

	// Printar a matriz somente se houver pelo menos um lugar disponível
	if(sem_lugar){
		printf("Eh um dia triste para os mono Yasuo\n");
	} else {
		for(int i=0;i<*linha;i++){
			for(int j=0;j<*coluna;j++){
				printf("%c ", matriz[i][j]);
			}
			printf("\n");
		}
	}
	return;
}