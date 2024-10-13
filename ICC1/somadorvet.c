#include <stdio.h>
#include <stdlib.h>

// Não entendi sobre a questão de não poder usar [i], então utilizei a forma de lidar com o vetor como se tivesse lidando com um ponteiro. 
int
main(void)
{

	int N, M, pot2=1, v1 = 0, v2 = 0, a[31];
	scanf("%d", &N);
	scanf("%d", &M);

	for(int i=N-1; i>=0; i--)
	{	
		scanf("%d", a+i);
		if(*(a+i)==0) continue;
		pot2=1;
		for(int j=0;j<i;j++){
			pot2*=2;
		}
		v1+=pot2;
	}

	for(int i=M-1; i>=0; i--)
	{	
		scanf("%d", a+i);
		if(*(a+i)==0) continue;
		pot2=1;
		for(int j=0;j<i;j++){
			pot2*=2;
		}
		v2+=pot2;
	}

	printf("%d\n", v1+v2);
}