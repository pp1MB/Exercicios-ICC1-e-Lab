#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int a,b;
	scanf("%d %d", &a, &b);

	if(a<2) a=2;

	menor:
		while(a<=b){
			for(int j=2; j<=sqrt(a); j++){
				if (a%j == 0){
					a++;
					goto menor;
				}
			}
			printf("menor primo: %d\n", a);
			break;
		}

	maior:
		while(a<=b){
			for(int j=2; j<=sqrt(b); j++){
				if (b%j == 0){
					b--;
					goto maior;
				}
			}
			printf("maior primo: %d\n", b);
			break;
		}

	if(a>b)
		printf("nenhum primo no intervalo\n");

}