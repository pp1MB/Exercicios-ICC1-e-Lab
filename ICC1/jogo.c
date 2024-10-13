#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void matrizIO(char **mat, int lin, int col, int acao);
void marcarPosicoes(char **mat, int lin, int col);

int main(void){
    int lin, col;
    char **tabuleiro;;

    scanf("%d %d", &lin, &col);

    // Alocando memória para a matriz tabuleiro
    tabuleiro = (char **) malloc(lin * sizeof(char *));
    assert(tabuleiro != NULL);
    for(int i=0; i<lin; i++){
        tabuleiro[i] = (char *) malloc(col);
        assert(tabuleiro[i] != NULL);
    }

    // Lendo, marcando e imprindo a matriz.
    matrizIO(tabuleiro, lin, col, 0);
    marcarPosicoes(tabuleiro, lin, col);   
    matrizIO(tabuleiro, lin, col, 1);

    // Liberando a memória utilizada.
    for(int i=0; i<lin; i++){
        free(tabuleiro[i]);
        tabuleiro[i] = NULL;
    }
    free(tabuleiro);
    tabuleiro = NULL;

    return 0;
}

/* Essa função é responsável por ler ou printar a matriz, o parâmetro 'acao' é responsável por dizer o que será feito:
- 0: ler a matriz
- qualquer outro número: printar a matriz.
*/
void matrizIO(char **mat, int lin, int col, int acao){
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            if(acao)
                printf("%c", mat[i][j]);
            else
                scanf(" %c", &mat[i][j]);
        }
        if(acao) printf("\n");
    }
    return;
}

/* Essa função verifica cada ponto da matriz e suas vizinhanças, a variável 'cont' serve para
contar quantos vizinhos iguais a 'X' aquele ponto na matriz tem. Verificações são feitas para que não haja
nenhuma invasão de memória.*/
void marcarPosicoes(char **mat, int lin, int col){
    int cont = 0;

    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            if(mat[i][j] == 'X') continue;

            // Verificações de vizinhança
            if(i+1<lin)
                if(mat[i+1][j] == 'X') cont++;
            
            if(i-1>=0)
                if(mat[i-1][j] == 'X') cont++;

            if(j+1<col)
                if(mat[i][j+1] == 'X') cont++;

            if(j-1>=0)
                if(mat[i][j-1] == 'X') cont++;

            // Somente marcar quando a contagem de vizinhos iguais a 'X' for par.
            if(cont%2 == 0) mat[i][j] = '*';
            cont = 0; // reiniciando o contador.
        }
    }
    return;
}