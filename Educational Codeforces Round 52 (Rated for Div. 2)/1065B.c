#include <stdio.h>

int main()
{
    long long n, m;
    scanf("%I64d %I64d", &n, &m);
    long long min = n - 2 * m;
    if(min < 0) {
        min = 0;
    }
    if(m == 0) {
        printf("%I64d %I64d\n", min, n);
    } else {
        for(long long max = 0; max <= n; ++max) {
            long long cmp = 0;
            if(max & 1) {
                cmp = (max - 1) / 2 * max;
            } else {
                cmp = max / 2 * (max - 1);
            }
            if(m <= cmp) {
                printf("%I64d %I64d\n", min, n - max);
                break;
            }
        }
    }
    return 0;
}
