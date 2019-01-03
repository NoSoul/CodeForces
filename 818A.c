#include <stdio.h>

int main()
{
    long long n, k;
    scanf("%I64d %I64d", &n, &k);
    long long a = n / 2 / (k + 1);
    printf("%I64d %I64d %I64d\n", a, k * a, n - (k + 1)*a);
    return 0;
}
