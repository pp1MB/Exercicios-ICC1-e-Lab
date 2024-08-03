#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    double l;
    double pi = 3.14159265358979323846;
    scanf("%d %lf", &n, &l);
    double ap = l/(2*tan(pi/n));
    double semip = (l*n)/2;
    printf("%lf\n", (semip*ap));
}
