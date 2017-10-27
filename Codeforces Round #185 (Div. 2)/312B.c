#include <stdio.h>

int main()
{
    int a, b, c, d;
    double p, q;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    p = 1.0 * a / b;
    q = 1.0 * c / d;
    printf("%.6f\n", p / (1 - (1 - p) * (1 - q)));
    return 0;
}
