#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int i;

    scanf("%c %d", &c, &i);
    printf("numero correspondente: %d\ncaracter correspondente: %c\noctal: %o\nhexadecimal: %x\n", c, i, i, i);
    return 0;
}
