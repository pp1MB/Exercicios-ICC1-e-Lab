#include <stdio.h>
#include <stdlib.h>

int soma(int n, int m);

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", soma(n, m));
    return 0;
}

int soma(int n, int m){
    if(m == 0)
        return n;

    return soma(n+1, m-1);
}