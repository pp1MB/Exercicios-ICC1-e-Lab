#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long int n, r = 0, five = 5;
    scanf("%llu", &n);

    while(n/five>0){
            r += (n/five);
            five*=5;        
    }
    printf("%llu\n", r);
}
