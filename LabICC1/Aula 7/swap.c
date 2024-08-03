#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int a, b, c, *p, *q;
	scanf("%d %d", &a, &b);
	p = &a;
    c = *p;
    q = &b;
    *p = *q;
    *q = c;

	printf("%d %d", a, b);
    return 0;

}
