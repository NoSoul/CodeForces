#include <stdio.h>

int main()
{
    long long n, k;
    scanf("%I64d %I64d", &n, &k);
    if(k % n == 0) {
        printf("%I64d\n", k / n);
    } else {
        printf("%I64d\n", k / n + 1);
    }
    return 0;
}
