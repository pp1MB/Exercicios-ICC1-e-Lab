#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct{
    char *nome;
    char cpf[12];
    int idade;
    float saldo;
    float credito;
} pessoas;

void *alocarMemoria(int size_vet, int size_type);

int main(void){
    pessoas *clientes;
    int n;
    bool semdivida = 1;

    scanf("%d", &n);

    clientes = (pessoas *) alocarMemoria(n, sizeof(pessoas));

    // Loop for para leitura de N entradas.
    for(int i=0; i < n; i++){
        char nome[31];

        scanf(" %[^,], %[^,], %d, %f, %f", nome, clientes[i].cpf, &clientes[i].idade, &clientes[i].saldo, &clientes[i].credito);

        clientes[i].nome = (char *) alocarMemoria(strlen(nome)+1, sizeof(char));
        strcpy(clientes[i].nome, nome);
        clientes[i].nome[strlen(nome)] = '\0';
    }

    // Loop for para printar os dados dos clientes.
    for(int i=0; i < n; i++){
        printf("Dados da pessoa %d:\n", i+1);
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Idade: %d\n", clientes[i].idade);
        printf("Saldo: %.2f\n", clientes[i].saldo);
        printf("Credito: %.2f\n\n", clientes[i].credito);

        if(clientes[i].credito > clientes[i].saldo) semdivida = 0;
    }

    // Loop for para printar os dados das pessoas endividadas.
    printf("Pessoas endividadas:\n");
    for(int i=0; i < n; i++){
        if(!semdivida)
            if(clientes[i].credito > clientes[i].saldo){
                printf("Nome: %s\n", clientes[i].nome);
                printf("CPF: %s\n", clientes[i].cpf);
                printf("Divida: %.2f\n", clientes[i].credito - clientes[i].saldo);
                if(i == 0) printf("\n");
            }
            if(clientes[i+1].credito > clientes[i+1].saldo && i < n-1 && i > 0) 
                printf("\n");

        // Após a última utilização dos dados de nome, eles são limpados da memória
        free(clientes[i].nome);
        clientes[i].nome = NULL;
        }

    if(semdivida) printf("Nenhuma pessoa endividada encontrada.");

    free(clientes);
    clientes = NULL;

    return 0;
}

void *alocarMemoria(int size_vet, int size_type){
    void *v;
    v = malloc(size_vet * size_type);

    assert(v != NULL);

    return v;
}