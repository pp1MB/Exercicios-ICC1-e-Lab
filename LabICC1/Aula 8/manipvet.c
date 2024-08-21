#include <stdio.h>
#include <stdlib.h>

int main(void){
	int vetor[100], tam, n;
	char comando;
	for(tam=0;;tam++){
	    scanf("%d", &n);
	    
	    if(n==1) break;
	    else vetor[tam]=n;
	}
	
	scanf(" %c", &comando);
    switch(comando){
        //Caso a: sort
        case 97:
            printf("vetor ordenado:");
            int temp;
            for(int i=0; i<tam; i++){
                for(int j=1;vetor[i-j]>vetor[i-j+1];j++){
                    temp = vetor[i-j];
                    vetor[i-j] = vetor[i-j+1];
                    vetor[i-j+1] = temp;
                }
            }
            for(int i=0;i<tam;i++){
                printf("%d ", vetor[i]);
            }
            printf("\n");
            break;

        //Caso b: fibonacci
        case 98:
            printf("Numeros de Fibonacci:");
            int seg=1, ante=1;
            for(int i=0;i<tam;i++){
                while(vetor[i]>=seg){
                    if(vetor[i]==seg) printf("%d ", vetor[i]);
                    seg = seg+ante;
                    ante = seg-ante;
                }
                seg=1, ante=1;

            }
            printf("\n");
            break;

        //Caso c: ToUpper
        case 99:
            printf("Vetor maiusculo:");
            for(int i=0; i<tam;i++){
                printf("%c ", (vetor[i])-32);
            }
            printf("\n");
            break;

        default: printf("Comando inexistente\n"); break;
    }
}