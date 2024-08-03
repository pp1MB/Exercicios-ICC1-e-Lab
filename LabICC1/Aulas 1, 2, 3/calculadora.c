#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2;

    scanf("%d", &n1);
    scanf("%d", &n2);
    printf("Soma: %d\n", n1+n2);
    printf("Subtracao: %d\n", n1-n2);
    printf("Multiplicacao: %d\n", n1*n2);
    printf("Divisao Inteira: %d\n", n1/n2);
    printf("Divisao Racional: %.3f\n", (float)n1/n2);
    return 0;
}
