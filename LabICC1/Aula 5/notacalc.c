#include <stdio.h>
#include <stdlib.h>

int main()
{
    float p1, p2, l1, l2, l3, l4;
    scanf("%f %f %f %f %f %f", &p1, &p2, &l1, &l2, &l3, &l4);
    if((p1+p2+(l1+l2+l3+l4)/4)/3 >= 5 &&  l1+l2+l3+l4 != 0)
         printf("Aprovado\n");
    else
        if((p1+p2+(l1+l2+l3+l4)/4)/3 < 3 || l1+l2+l3+l4 == 0)
            printf("Reprovado\n");
        else
            printf("Recuperacao\n");
    return 0;
}