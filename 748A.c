#include <stdio.h>

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    printf("%d %d %c\n", ((k - 1) / 2) / m + 1, ((k - 1) / 2) % m + 1, (k & 1) ? 'L' : 'R');
    return 0;
}
