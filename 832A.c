#include <stdio.h>

int main()
{
    long long n, k;
    scanf("%I64d %I64d", &n, &k);
    puts((n / k) & 1 ? "YES" : "NO");
    return 0;
}
