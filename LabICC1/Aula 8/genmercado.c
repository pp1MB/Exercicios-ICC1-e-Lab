#include <stdio.h>
#include <stdlib.h>

int main(void){
	unsigned short int n;
	int qtd_adq, qtd_vend;
	float preco_compra, preco_venda, saldo = 0, produtos[100];

	scanf("%hd", &n);

	if(n==0) printf("Sem atividades registradas hoje\n");
	else{
		for(int i=0;i<n;i++){
			scanf("%f %f %d %d", &preco_compra, &preco_venda, &qtd_adq, &qtd_vend);
			produtos[i] = qtd_vend*preco_venda - qtd_adq*preco_compra;
			saldo += produtos[i];
		}

		if(saldo>=0) printf("lucro: %.2f\n", saldo);
		if(saldo<0) printf("prejuizo: %.2f\n", -saldo);

		int i=0, j=0;
		for(i;i<n;i++){
			for(j;j<n;j++){
				if(produtos[i]<produtos[j]) break;
			}
			if(produtos[i]>produtos[j]) break;
		}
		printf("produto: %d lucro relativo: %.2f\n", i+1, produtos[i]);
	}
}