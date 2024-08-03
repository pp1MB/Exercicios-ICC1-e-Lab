#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	int n;
	float r = 0;
	scanf("%d", &n);
	for(int i = 1; i<=n; i++)
	{
		if(i%2 == 1)
			r += 1.0/(i);
		if(i%2 == 0)
			r -= 1.0/(i);
	}
	printf("%.4f", r);
}