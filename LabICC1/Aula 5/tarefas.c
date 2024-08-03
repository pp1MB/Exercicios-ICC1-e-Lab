#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dia, bool;
    scanf("%d %d", &dia, &bool);
    switch(dia){
        case 1:
        printf("Segunda: Aula de computacao\n");
        if(bool)
            break;
        
        case 2:
        printf("Terca: Treino de volei\n");
        if(bool)
            break;
        
        case 3:
        printf("Quarta: Aula de calculo\n");
        if(bool)
            break;
        
        case 4:
        printf("Quinta: Lista de GA\n");
        if(bool)
            break;
        
        case 5:
        printf("Sexta: Festa da Sacim\n");
        if(bool)
            break;
        
        case 6:
        printf("Sabado: Jantar em familia\n");
        if(bool)
            break;
        
        case 7:
        printf("Domingo: Depressao pos final de semana\n");
        break;
        
        case 8:
        printf("Dia nao registrado\n");
        }
    return 0;
}