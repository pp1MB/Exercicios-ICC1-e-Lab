#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(void){
    char *input;
    char *A, *B, *param;

    input = (char *) malloc(130 * sizeof(char));

    scanf(" %[^\n]s", input);
    A = (char *) malloc(strlen(input)+1 * sizeof(char));
    assert(A != NULL);
    strcpy(A, input);

    scanf(" %[^\n]s", input);
    B = (char *) malloc(strlen(input)+1 * sizeof(char));
    assert(B != NULL);
    strcpy(B, input);

    scanf(" %[^\n]s", input);
    param = (char *) malloc(strlen(input)+1 * sizeof(char));
    assert(param != NULL);
    strcpy(param, input);

    free(input);
    input = NULL;

    // Pega a parte de A
    char *fim = strstr(A, param);

    if(fim != NULL){
        *fim = '\0';
    } else {
        A[strlen(A)-1] = '\0';
        A[strlen(A)] = ' ';
    }

    // Pega a parte de B
    char *comeco = strstr(B, param);
    char *novoB;

    if(comeco != NULL){
        novoB = (char *) malloc(strlen(comeco) + 1);
        assert(novoB != NULL);
        strcpy(novoB, comeco + strlen(param)+1);
    } else
        novoB = "";

    // Concatena os resultados em str_result
    char *str_result;
    str_result = (char *) calloc(strlen(A) + strlen(novoB) + 1, sizeof(char));
    assert(str_result != NULL);

    strcat(str_result, A);
    strcat(str_result, novoB);

    printf("%s", str_result);

    // Liberando memória
    if(comeco != NULL){
        free(novoB);
        novoB = NULL;
    }
    free(A);
    A = NULL;
    free(B);
    B = NULL;
    free(param);
    param = NULL;
    free(str_result);
    str_result = NULL;

    return 0;
}