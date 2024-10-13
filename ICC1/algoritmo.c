#include <stdio.h>
#include <stdlib.h>

int main()
{
    int case_var;
    char nome1, nome2, char_var;

    scanf("%d", &case_var);
    scanf(" %c", &nome1);
    scanf(" %c", &nome2);
    scanf(" %c", &char_var);

    int resposta;
    resposta = case_var;

    printf("a resposta eh ");
    printf("%d", resposta);
    return 0;
}
