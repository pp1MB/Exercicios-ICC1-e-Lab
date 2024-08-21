
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int **alocarMemoria(int dimensao);
void inserirMatriz(int **matriz, int dimensao);

int main(void){
    int **matriz, dimensao;
    scanf("%d", &dimensao);
    
    dimensao = sqrt(dimensao);
    matriz = alocarMemoria(dimensao);
    inserirMatriz(matriz, dimensao);
    
    for(int i=0;i<dimensao;i++){
        for(int j=0;j<dimensao;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    // Limpando memória
    for(int i=0;i<dimensao;i++){
        free(matriz[i]);
        matriz[i] = NULL;
    }
    free(matriz);
    matriz = NULL;
    return 0;
}

int **alocarMemoria(int dimensao){
    int **matriz = (int **)malloc(dimensao * sizeof(int *));
    
    for(int i=0;i<dimensao;i++)
        matriz[i] = (int *)malloc(dimensao * sizeof(int));
    
    return matriz;
}

void inserirMatriz(int **matriz, int dimensao){
    for(int i=0;i<dimensao;i++){
        for(int j=0;j<dimensao;j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    return;
}


