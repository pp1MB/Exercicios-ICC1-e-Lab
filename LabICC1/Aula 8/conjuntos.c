#include <stdio.h>
#include <stdlib.h>

int main(void){
	int tam_a, tam_b, a[10], b[10], int_vazio=1, dif_vazio=1;
	
	// Ler vetor A
	scanf("%d", &tam_a);
	for(int i = 0; i<tam_a; i++){
		scanf("%d", &a[i]);
	}
	
	// Ler vetor B
	scanf("%d", &tam_b);
	for(int i = 0; i<tam_b; i++){
		scanf("%d", &b[i]);
	}
	
	//Intersecao
	printf("intersecao:");
	for(int i = 0; i<tam_a; i++){
		for(int j = 0; j<tam_b; j++){
			if(a[i]==b[j]){
				printf(" %d", a[i]);
				int_vazio = 0;
				
			}
		}
	}
	if(int_vazio) printf(" vazio");
	
	//Diferença
	int i = 0;
	printf("\na - b:");
	diferença:
    	while(i<tam_a){
    		for(int j = 0; j<tam_b; j++){
    			if(a[i]==b[j]){
    			    i++;
    				goto diferença;
    			}
    		}
    	printf(" %d", a[i]);
    	i++;
    	dif_vazio=0;
    	}
    
    if(dif_vazio) printf(" vazio");
    
}