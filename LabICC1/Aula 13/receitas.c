#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct{
    char *nome;
    int farinha;
    int ovos;
    int oleo;
    int acucar;
    int chocolate;
} receitatype;

receitatype registrarReceita(void);
void compraIngredientes(receitatype *i);
void fazerReceita(receitatype *r, receitatype *i, int n_receita);

int main(void){
    int n_receita = 0;
    char comand;
    receitatype *receita, ingredientes;
    receita = (receitatype *) malloc(50 * sizeof(receitatype));
    assert(receita != NULL);
    // memset(&ingredientes, 0, sizeof(receitatype));

    do{
        scanf(" %c", &comand);
        switch(comand){
            case 'R': 
                receita[n_receita] = registrarReceita();
                n_receita++;
                break;
            case 'C':
                compraIngredientes(&ingredientes);
                break;
            case 'F':
                fazerReceita(receita, &ingredientes, n_receita);
                break;
            case 'S':
                printf("Quantidade no estoque:\n");
                printf("Acucar: %d\n", ingredientes.acucar);
                printf("Chocolate: %d\n", ingredientes.chocolate);
                printf("Farinha: %d\n", ingredientes.farinha);
                printf("Oleo: %d\n", ingredientes.oleo);
                printf("Ovos: %d\n", ingredientes.ovos);
                printf("Receitas cadastradas: %d", n_receita);
                break;
            default: 
                printf("Codigo invalido\n");
                break;
        }
    } while(comand != 'S');

    for(int i=0; i<n_receita; i++){
        free(receita[i].nome);
        receita[i].nome = NULL;
    }
    free(receita);
    return 0;
}

receitatype registrarReceita(void){
    receitatype r;
    char input[20];

    scanf("%s", input);
    r.nome = (char *) malloc(strlen(input) + 1);
    assert(r.nome != NULL);
    strcpy(r.nome, input);

    scanf("%d %d %d %d %d", &r.farinha, &r.ovos, &r.oleo, &r.acucar, &r.chocolate);

    return r;
}

void compraIngredientes(receitatype *i){
    receitatype new_i;
    scanf("%d %d %d %d %d", &new_i.farinha, &new_i.ovos, &new_i.oleo, &new_i.acucar, &new_i.chocolate);

    (*i).farinha += new_i.farinha;
    (*i).ovos += new_i.ovos;
    (*i).oleo += new_i.oleo;
    (*i).acucar += new_i.acucar;
    (*i).chocolate += new_i.chocolate;

    return;
}

void fazerReceita(receitatype *r, receitatype *i, int n_receita){
    int cod;
    scanf("%d", &cod);

    if(cod < n_receita){
        if((*i).farinha >= r[cod].farinha){
            if((*i).ovos >= r[cod].ovos){
                if((*i).oleo >= r[cod].oleo){
                    if((*i).acucar >= r[cod].acucar){
                        if((*i).chocolate >= r[cod].chocolate){
                            (*i).farinha -= r[cod].farinha;
                            (*i).ovos -= r[cod].ovos;
                            (*i).oleo -= r[cod].oleo;
                            (*i).acucar -= r[cod].acucar;
                            (*i).chocolate -= r[cod].chocolate;
                            printf("%s feita com sucesso!\n", r[cod].nome);
                        }
                        else printf("Chocolate insuficiente\n");
                    }
                    else printf("Acucar insuficiente\n");
                }
                else printf("Oleo insuficiente\n");
            }
            else printf("Ovos insuficientes\n");
        }
        else printf("Farinha insuficiente\n");
    }
    else printf("Receita nao encontrada!\n");
    return;
}