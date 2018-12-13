#include <stdio.h>

int main()
{
    long long n, k;
    scanf("%I64d %I64d", &n, &k);
    long long lowBound, highBound;
    if(n + n - 1 < k) {
        puts("0");
    } else {
        if(n >= k - 1) {
            printf("%I64d\n", (k - 1) / 2);
        } else {
            if(n > k - n) {
                printf("%I64d\n", (2 * n - k + 1) / 2);
            } else {
                printf("%I64d\n", (k - n - n + 1) / 2);
            }
        }
    }
    return 0;
}
