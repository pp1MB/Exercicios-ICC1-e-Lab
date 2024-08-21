#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void lerMatriz(int dimensao, char matriz[dimensao][dimensao]);
void bombardeio(int dimensao, char matriz[dimensao][dimensao]);
void printMatriz(int dimensao, char matriz[dimensao][dimensao]);

int main(void){
	char tabuleiro[26][26];
	int N;
	scanf("%d", &N);
	lerMatriz(N, tabuleiro);
	bombardeio(N, tabuleiro);
	printMatriz(N, tabuleiro);
}

void lerMatriz(int dimensao, char matriz[dimensao][dimensao]){
	for(int i=0;i<dimensao;i++){
		for(int j=0;j<dimensao;j++){
			scanf(" %c", &matriz[i][j]);
		}
	}
}

void bombardeio(int dimensao, char matriz[dimensao][dimensao]){
	char cord_char;
	int cord_numero, qtd;
	scanf("%d", &qtd);

	for(int bombas=0;bombas<qtd;bombas++){
		scanf(" %c %d", &cord_char, &cord_numero);

		if(matriz[cord_char-'A'][cord_numero-1]=='N'){
			printf("acerto!\n");
			matriz[cord_char-'A'][cord_numero-1]='X';
		} else {
			printf("erro!\n");
		}
	}
}

void printMatriz(int dimensao, char matriz[dimensao][dimensao]){
	for(int i=0;i<dimensao;i++){
		for(int j=0;j<dimensao;j++){
			printf("%c ", matriz[i][j]);
		}
		printf("\n");
	}
}