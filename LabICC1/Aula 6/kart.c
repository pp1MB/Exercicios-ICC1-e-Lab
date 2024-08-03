#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N, T;
	float A, B;
	scanf("%d", &N);

	while(N>0){
		scanf("%f %f %d", &A, &B, &T);

		// Checando os pilotos
		if(T==0) printf("A corrida ainda nao comecou\n");
		else{
			if(A==0 && B>0) printf("O piloto A desistiu inesperadamente\n");
			if(A>0 && B==0) printf("O piloto B desistiu inesperadamente\n");
			if(A==0 && B==0) printf("Os dois pilotos nao querem competir\n");

			if(A>0 && B>0){
				// Checando o tempo(T)
				if(T<0) printf("De alguma forma os pilotos voltaram no tempo\n");

				if(T>0){
					if(A>B) printf("O kart A venceu e percorreu %.2fkm a mais que o kart B\n", (A-B)*T);
					if(B>A) printf("O kart B venceu e percorreu %.2fkm a mais que o kart A\n", (B-A)*T);
					if(A==B) printf("Os karts empataram, percorrendo cada %.2fkm\n", A*T);
				}
			}
		}
	N--;
	}
}