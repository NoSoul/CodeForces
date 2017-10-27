#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(n < 3) {
        puts("-1");
        return 0;
    }
    long long m = (long long)n * n;
    if(m & 1) {
        printf("%I64d %I64d\n", (m - 1) / 2, (m + 1) / 2);
    } else {
        printf("%I64d %I64d\n", (m / 2 - 2) / 2, (m / 2 + 2) / 2);
    }
    return 0;
}
