#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

void crivo(bool *vet);
int fatorar(bool *primos, int numero);
void nfree(void *vetor);

int main(void){
	bool *primos;
	int n, IP, *codigo;
	char **conteudo;

	// Aqui todos os números primos de 2 a 8000 são selecionados em um vetor para posterior fatoração.
	primos = (bool *) malloc(8000 * sizeof(bool));
	assert(primos!=NULL);
	crivo(primos);

	// Leitura do número de entradas
	scanf("%d", &n);

	// Reservando espaço para 'conteudo' sendo um vetor de strings e 'codigo' sendo um vetor de inteiros.
	conteudo = (char **) malloc(n * sizeof(char *));
	assert(conteudo!=NULL);
	codigo = (int *) malloc(n * sizeof(int));
	assert(codigo!=NULL);

	//IP serve para dar a ordem para printar as strings
	for(int i=0;i<n;i++){
		scanf("%d", &IP);;
		scanf("%d", &codigo[IP]);
		conteudo[IP] = (char *) malloc((fatorar(primos, codigo[IP])+1) * sizeof(char)); // Cada string recebe espaço de soma dos fatores de codigo e +1 para garantir o \0
		scanf("%s", conteudo[IP]);
	}

	// Printa cada string ao lado de seu código baseado na importância
	for(int i=n-1;i>=0;i--){
		printf("%s ", conteudo[i]);
		printf("%d\n", codigo[i]);
	}

	if(n==0) printf("Sem produtos a serem cadastrados\n");

	// Liberando memória
	nfree(primos);
	nfree(codigo);

	for(int i=0;i<n;i++) nfree(conteudo[i]);
	nfree(conteudo);

	return 0;
}

// Um código que aplica o Crivo de Eratostenes, marcando primos como 0 e não primos como 1.
void crivo(bool *vet){
	for(int i=2;i<8000;i++){
		if(vet[i]) continue;
		for(int j=i+i;j<8000;j+=i){
			vet[j]=1;
		}
	}
	return;
}

// Um código que retorna a soma dos fatores de um número baseado no conjunto dos números primos criado anteriormente;
int fatorar(bool *primos, int numero){
	int sum_divisor = 0;
	for(int i=2;i<=numero;i++){
		if(primos[i]) continue;
		if(numero%i==0) sum_divisor+=i;
		while(numero%i==0){
			numero/=i;
		}
	}
	return sum_divisor;
}

void nfree(void *vetor){
	free(vetor);
	vetor = NULL;
	return;
}