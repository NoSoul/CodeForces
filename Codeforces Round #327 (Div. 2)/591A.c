#include <stdio.h>

int main()
{
    int l, p, q;
    double t;
    scanf("%d %d %d", &l, &p, &q);
    t = 1.0 * l / (p + q);
    printf("%lf\n", p * t);
    return 0;
}
