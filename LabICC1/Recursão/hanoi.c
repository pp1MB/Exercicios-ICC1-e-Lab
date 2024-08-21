#include <stdio.h>
#include <stdlib.h>

void hanoi(int d, char origem, char aux, char dest);

int main(void){
    int d;
    scanf("%d", &d);
    hanoi(d, 'A', 'B', 'C');

    return 0;
}

void hanoi(int d, char origem, char aux, char dest){
   if(d == 1){
        printf("Move disco %d da pilha %c para a pilha %c\n", d, origem, dest);
        return;
    }
    
    hanoi(d-1, origem, dest, aux);

    printf("Move disco %d da pilha %c para a pilha %c\n", d, origem, dest);

    hanoi(d-1, aux, origem, dest);
}