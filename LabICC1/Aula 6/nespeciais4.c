#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(void)
{
	int numero = 1000;
	for(numero; numero<9999; numero++)
	{
		if((numero/100)+(numero%100) == sqrt(numero))
		{
			printf("%d \n", numero);
		}
	}
	return 0;
}