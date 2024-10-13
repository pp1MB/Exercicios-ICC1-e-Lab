#include <stdio.h>
#include <stdlib.h>

int main()
{
    short unsigned int a,b,c;
    scanf("%hu %hu %hu", &a,&b,&c);
    long long int k = 0;
    k = k | c;
    k = k << 16;
    k = k | b;
    k = k << 16;
    k = k | a;
    printf("%lld \n",  k);
    return 0;
}
