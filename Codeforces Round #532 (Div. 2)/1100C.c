#include <stdio.h>
#include <math.h>

#define PI acos(-1)

int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    double a = sin(PI / n);
    printf("%.6f\n", a * r / (1 - a));
    return 0;
}
