#include <stdio.h>
#include <stdlib.h>

void lerMatriz(int dimensao, int matriz[dimensao][dimensao]);
void printarMatriz(int dimensao, int matriz[dimensao][dimensao]);
void diagonal(int dimensao, int matriz[dimensao][dimensao], int numero);
void multiplicar(int dimensao1, int matriz1[dimensao1][dimensao1], int matriz2[dimensao1][dimensao1]);

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    int matriz1[N][N], matriz2[M][M];
    lerMatriz(N, matriz1);
    lerMatriz(M, matriz2);
    printf("Matrizes:\n");
    printarMatriz(N, matriz1);
    printarMatriz(M, matriz2);
    diagonal(N, matriz1, 1);
    diagonal(M, matriz2, 2);
    if(N==M) multiplicar(N, matriz1, matriz2);
    else printf("Matrizes de tamanho incompativel\n");
    return 0;
}

void lerMatriz(int dimensao, int matriz[dimensao][dimensao]){
    for(int i=0; i<dimensao;i++){
        for(int j=0; j<dimensao;j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    return;
}

void printarMatriz(int dimensao, int matriz[dimensao][dimensao]){
    for(int i=0; i<dimensao;i++){
        for(int j=0; j<dimensao;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return;
}

void diagonal(int dimensao, int matriz[dimensao][dimensao], int numero){
    int diagonal = 1;
    for(int i=0;i<dimensao;i++){
        for(int j=0;j<dimensao;j++)
            if(i!=j && matriz[i][j]!=0){
                diagonal = 0;
                break;
            }
        if(diagonal==0){
            printf("A matriz %d nao eh diagonal\n", numero);
            break;
        }
    }
    if(diagonal)
            printf("A matriz %d eh diagonal\n", numero);
    return;
}

void multiplicar(int dimensao1, int matriz1[dimensao1][dimensao1], int matriz2[dimensao1][dimensao1]){
    int matrizResultado[dimensao1][dimensao1];
    //Zerar matriz
    for(int i=0;i<dimensao1;i++){
        for(int j=0;j<dimensao1;j++){
            matrizResultado[i][j]=0;
        }
    }
    for(int i=0;i<dimensao1;i++){
        for(int j=0;j<dimensao1;j++){
            for(int k=0;k<dimensao1;k++){
                 matrizResultado[i][j]+=(matriz1[i][k]*matriz2[k][j]);
            }
        }
    }
    printf("Matriz multiplicada:\n");
    printarMatriz(dimensao1, matrizResultado);
    return;
}