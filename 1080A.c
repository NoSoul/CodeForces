#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", (2 * n + k - 1) / k + (5 * n + k - 1) / k + (8 * n + k - 1) / k);
    return 0;
}
