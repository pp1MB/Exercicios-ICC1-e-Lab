#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int tam;

    scanf("%lld", &tam);
    printf("char: %lld\n", sizeof(char)*tam);
    printf("int: %lld\n", sizeof(int)*tam);
    printf("double: %lld\n", sizeof(double)*tam);
    return 0;
}
