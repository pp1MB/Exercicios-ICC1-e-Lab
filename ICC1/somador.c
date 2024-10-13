#include <stdio.h>
#include <stdlib.h>

int
main(void)
{

	int N, M, v1 = 0, v2 = 0;
	scanf("%d", &N);
	scanf("%d", &M);

	for(int i=0; i<N; i++)
	{
		int d = 0;
		scanf("%d", &d);
		v1 = v1|d;
		v1 = v1 << 1;
	}
	v1 = v1 >> 1;

	for(int i=0; i<M; i++)
	{
	 	int d = 0;
		scanf("%d", &d);
		v2 = v2|d;
		v2 = v2 << 1;
	}
	v2 = v2 >> 1;

	printf("%d\n", v1+v2);
}