#include <stdio.h>

int main()
{
    int k, n, s, p;
    scanf("%d %d %d %d", &k, &n, &s, &p);
    int sheets = (n + s - 1) / s;
    sheets *= k;
    printf("%d\n", (sheets + p - 1) / p);
    return 0;
}
