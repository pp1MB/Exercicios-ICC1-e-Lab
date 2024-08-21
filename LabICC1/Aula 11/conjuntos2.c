#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void *alocaMemoria(int size_vet, int size_type);
void nfree(void *vet);
void bubbleSort(int *vet, int size);
void lerConjunto(int *con, int size);
void escreverConjunto(int *con, int size);
int *uniaoConjuntos(int *con_A, int *con_B, int **con_Intersec, int tam_A, int tam_B, int *tam_Intersec);
int *diferencaConjuntos(int *con_Uniao, int *con_Intersec, int tam_A, int tam_B, int n_intersec);

int main(void){
    int tam_A, tam_B, tam_Intersec = 0, *con_A, *con_B, *con_Uniao, *con_Intersec, *con_Diferenca;

    scanf("%d", &tam_A);
    con_A = (int *) alocaMemoria(tam_A, sizeof(int));
    lerConjunto(con_A, tam_A);
    
    scanf("%d", &tam_B);
    con_B = (int *) alocaMemoria(tam_B, sizeof(int));
    lerConjunto(con_B, tam_B);
    
    printf("conjunto A: ");
    bubbleSort(con_A, tam_A);
    escreverConjunto(con_A, tam_A);
    printf("\n");

    printf("conjunto B: ");
    bubbleSort(con_B, tam_B);
    escreverConjunto(con_B, tam_B);
    printf("\n");

    con_Uniao = uniaoConjuntos(con_A, con_B, &con_Intersec, tam_A, tam_B, &tam_Intersec);
    printf("A uniao B: ");
    escreverConjunto(con_Uniao, tam_A + tam_B - tam_Intersec);
    printf("\n");

    con_Diferenca = diferencaConjuntos(con_Uniao, con_Intersec, tam_A, tam_B, tam_Intersec);
    printf("(A uniao B) - (A interseccao B): ");
    escreverConjunto(con_Diferenca, tam_A + tam_B - 2*tam_Intersec);

    nfree(con_A);
    nfree(con_B);
    nfree(con_Uniao);
    nfree(con_Intersec);
    nfree(con_Diferenca);

    return 0;
}


void *alocaMemoria(int size_vet, int size_type){
    void *vet;
    vet = malloc(size_vet * size_type);
    assert(vet != NULL);

    return vet;
}

void nfree(void *vet){
    free(vet);
    vet = NULL;
    
    return;
}

void bubbleSort(int *vet, int size){
    int troca = 1, temp;
    while(troca){
        troca = 0;
        for(int i=0; i+1<size; i++){
            if(vet[i]>vet[i+1]){
                temp = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = temp;
                troca = 1;
            }
        }
    }

    return;
}

void lerConjunto(int *con, int size){
    for(int i=0; i<size; i++)
        scanf("%d", &con[i]);

    return;
}

void escreverConjunto(int *con, int size){
    for(int i=0; i<size; i++)
        printf("%d ", con[i]);
    if(size==0) printf("vazio");

    return;
}

int *uniaoConjuntos(int *con_A, int *con_B, int **con_Intersec, int tam_A, int tam_B, int *tam_Intersec){
    int *con_Uniao;

    con_Uniao = (int *) alocaMemoria(tam_A + tam_B, sizeof(int));
    *con_Intersec = (int *) alocaMemoria(tam_A + tam_B, sizeof(int));

    for(int i=0; i < (tam_A + tam_B); i++){

        if(i < tam_A)
            con_Uniao[i] = con_A[i];

        else {
            int cont;

            for(cont=0; cont<tam_A; cont++)
                if(con_Uniao[cont] == con_B[i-tam_A]){
                    (*con_Intersec)[*tam_Intersec] = con_B[i-tam_A];
                    break;
                }

            if(con_Uniao[cont] != con_B[i-tam_A])
                con_Uniao[i-*tam_Intersec] = con_B[i-tam_A];
            else
                (*tam_Intersec)++;
        }
    }   
    con_Uniao = realloc(con_Uniao, ((tam_A + tam_B - *tam_Intersec) * sizeof(int)));
    bubbleSort(con_Uniao, tam_A + tam_B - *tam_Intersec);

    return con_Uniao;
}

int *diferencaConjuntos(int *con_Uniao, int *con_Intersec, int tam_A, int tam_B, int tam_Intersec){
    int *con_Diferenca, n_diferenca = tam_A + tam_B - 2*tam_Intersec, cont = 0;
    con_Diferenca = (int *) alocaMemoria(n_diferenca, sizeof(int));

    for(int i=0, j; i < tam_A + tam_B - tam_Intersec; i++){
        for(j=0; j < tam_Intersec; j++){
            if(con_Uniao[i] == con_Intersec[j])
                break;
        }
        if(con_Uniao[i] != con_Intersec[j]){
            con_Diferenca[cont] = con_Uniao[i];
            cont++;
        }
    }
    bubbleSort(con_Diferenca, n_diferenca);

    return con_Diferenca;
}
