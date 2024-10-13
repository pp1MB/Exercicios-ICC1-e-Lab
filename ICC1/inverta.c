#include <stdio.h>
#include <stdlib.h>

// Não entendi sobre a questão de não poder usar [i], então utilizei a forma de lidar com o vetor como se tivesse lidando com um ponteiro. 
int main(void){
	int vetor[100000], n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", (vetor+i));
	}
	for(int i=n-1;i>=0;i--){
		printf("%d ", *(vetor+i));
	}
	printf("\n");

	return 0;
}