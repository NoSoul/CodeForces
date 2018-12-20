#include <stdio.h>

int main()
{
    long long n, m, a, b;
    scanf("%I64d %I64d %I64d %I64d", &n, &m, &a, &b);
    if(n % m == 0) {
        puts("0");
    } else {
        a *= m - n % m;
        b *= n % m;
        printf("%I64d\n", a < b ? a : b);
    }
    return 0;
}
