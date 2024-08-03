#include <stdio.h>
#include <stdlib.h>

int main()
{
    float l1, l2, l3 ,l4;
    scanf("%f %f %f %f", &l1, &l2, &l3, &l4);
            if(l1==l2 && l2==l3 && l3==l4 && l1*l2*l3*l4!=0)
                printf("quadrado!\n");
            else
                if(l1==l3 && l2==l4 && l1*l2*l3*l4!=0)
                    printf("retangulo!\n");
                else
                    printf("nenhum!\n");
    return 0;
}