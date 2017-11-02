#include <stdio.h>
#include <math.h>

double Exp(double n, int m)
{
    if(m == 0) {
        return 1;
    }
    double k = 1;
    while(m != 1) {
        if(m & 1) {
            k = k * n;
        }
        n = n * n;
        m >>= 1;
    }
    return n * k;
}

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    printf("%lf\n", n * Exp(1.000000011, t));
    return 0;
}
