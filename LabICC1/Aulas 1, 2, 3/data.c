#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dia, mes, ano;

    scanf("%2d %2d %4d", &dia, &mes, &ano);
    printf("%02d/%02d/%04d\n", dia, mes, ano);
}
