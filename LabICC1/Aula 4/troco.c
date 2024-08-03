#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dinheiro;
    scanf("%d", &dinheiro);

    printf("%d nota(s) de R$ 200\n", dinheiro/200);
    if(dinheiro/200 >= 1){
        dinheiro -= (dinheiro/200)*200;
    }

    printf("%d nota(s) de R$ 100\n", dinheiro/100);
    if(dinheiro/100 >= 1){
        dinheiro -= (dinheiro/100)*100;
    }

    printf("%d nota(s) de R$ 50\n", dinheiro/50);
    if(dinheiro/50 >= 1){
        dinheiro -= (dinheiro/50)*50;
    }

    printf("%d nota(s) de R$ 20\n", dinheiro/20);
    if(dinheiro/20 >= 1){
        dinheiro -= (dinheiro/20)*20;
    }

    printf("%d nota(s) de R$ 10\n", dinheiro/10);
    if(dinheiro/10 >= 1){
        dinheiro -= (dinheiro/10)*10;
    }

    printf("%d nota(s) de R$ 5\n", dinheiro/5);
    if(dinheiro/5 >= 1){
        dinheiro -= (dinheiro/5)*5;
    }

    printf("%d nota(s) de R$ 2\n", dinheiro/2);
    if(dinheiro/2 >= 1){
        dinheiro -= (dinheiro/2)*2;
    }

    printf("%d moeda(s) de R$ 1\n", dinheiro);
}
