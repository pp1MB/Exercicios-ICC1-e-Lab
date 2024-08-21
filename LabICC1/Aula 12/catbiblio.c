#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

void nfreeMat(void **mat, int tam);

int main(void){
    int n;

    scanf("%d", &n);
    char **nomeLivros = (char **) malloc(n * sizeof(char *));
    assert(nomeLivros != NULL);
    char **autorLivros = (char **) malloc(n * sizeof(char *));
    assert(autorLivros != NULL);
    char **anoLivros = (char **) malloc(n * sizeof(char *));
    assert(anoLivros != NULL);
    int *qntLivros = (int *) malloc(n * sizeof(int));
    assert(qntLivros != NULL);

    char input[100];

    for(int i=0; i<n; i++){
        scanf(" %[^\n]s", input);
        char *token = strtok(input, ",");
        
        bool repetido;
        for(int j=0; j<i; j++){
            if(strcmp(nomeLivros[j], token) == 0){
                qntLivros[j] += 1;
                i--;
                n--;
                repetido = true;
                break;
            }
        }

        if(!repetido){
            nomeLivros[i] = (char *) malloc((strlen(token)+1) * sizeof(char));
            assert(nomeLivros[i] != NULL);
            strcpy(nomeLivros[i], token);
            
            token = strtok(NULL, ",");
            autorLivros[i] = (char *) malloc((strlen(token)+1) * sizeof(char));
            assert(autorLivros[i] != NULL);
            strcpy(autorLivros[i], token);

            token = strtok(NULL, ",");
            anoLivros[i] = (char *) malloc((strlen(token)+1) * sizeof(char));
            assert(anoLivros[i] != NULL);
            strcpy(anoLivros[i], token);

            qntLivros[i] = 1;
        }
        repetido = false;
    }

    // Printando
    printf("Catalogo de Livros:\n");
    for(int i=0; i<n; i++){
        printf("Livro %d:\n", i+1);
        printf("Titulo: %s\n", nomeLivros[i]);
        printf("Autor:%s\n", autorLivros[i]);
        printf("Ano:%s\n", anoLivros[i]);
        printf("Quantidade: %d\n", qntLivros[i]);

        if(i+1 != n) printf("\n");
    }

    // Liberando memória
    for(int i=0; i<n; i++){
        free(nomeLivros[i]);
        free(autorLivros[i]);
        free(anoLivros[i]);
        nomeLivros[i] = NULL, autorLivros[i] = NULL, anoLivros[i] = NULL;
    }
    free(nomeLivros);
    free(autorLivros);
    free(anoLivros);
    free(qntLivros);

    nomeLivros = NULL, autorLivros = NULL, anoLivros = NULL, qntLivros = NULL;
}