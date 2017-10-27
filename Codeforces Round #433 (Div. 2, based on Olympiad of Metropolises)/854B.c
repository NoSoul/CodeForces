#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d %I64d\n", k == n ? 0 : (k ? 1 : 0), (long long)3 * k <= n ? (long long)2 * k : n - k);
    return 0;
}
