#include <stdio.h>

int main()
{
    int q, a, b;
    long long n;
    scanf("%d", &q);
    while(q--) {
        scanf("%I64d %d %d", &n, &a, &b);
        long long ans = 0;
        if(n & 1) {
            --n;
            ans += a;
        }
        if(a + a < b) {
            b = a + a;
        }
        ans += n / 2 * b;
        printf("%I64d\n", ans);
    }
    return 0;
}
