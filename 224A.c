#include <stdio.h>

int main()
{
    int A, B, C, D;
    scanf("%d %d %d", &A, &B, &C);
    D = sqrt(1.0 * A * B * C);
    printf("%d\n", 4 * (D / A + D / B + D / C));
    return 0;
}
