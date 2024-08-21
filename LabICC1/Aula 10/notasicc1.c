#include <stdio.h>
#include <stdlib.h>

void sort(float *vetor, int tamanho);

int main(void){
	int linha_aluno, coluna_notas;
	float notas[100][25] = {0}, media_aluno = 0, media_exercicios[25] = {0};
	scanf("%d" "%d", &linha_aluno, &coluna_notas);
	for(int i=0;i<linha_aluno;i++){
		for(int j=0;j<coluna_notas;j++){
			scanf("%f", &notas[i][j]);
			media_aluno+=notas[i][j];
			media_exercicios[j]+=notas[i][j];
		}
		media_aluno/=coluna_notas;
		printf("Media do aluno %d = %.2f : ", i+1, media_aluno);
		if(media_aluno>=5) printf("Aprovado\n");
		else printf("Reprovado\n");
		media_aluno = 0;
	}
    printf("\n");

    // Organizar Média
	for(int i=0;i<coluna_notas;i++) media_exercicios[i]/=linha_aluno;
	sort(media_exercicios, coluna_notas);

	return 0;
}

void sort(float *vetor, int tamanho){
	int sort = 1;
	float temp;
	while(sort){
		sort = 0;
		for(int i=0;i<tamanho;i++){
			if(vetor[i]<vetor[i+1]){
				temp = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = temp;
				sort = 1;
			}
		}
	}
	for(int i=0; i<tamanho; i++){
		printf("%.2f ", vetor[i]);
	}
	printf("\n");
	return;
}
