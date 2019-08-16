#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        long long n, k;
        scanf("%I64d %I64d", &n, &k);
        long long ans = 0;
        while(n) {
            long long r = n % k;
            if(r == 0) {
                n /= k;
                ++ans;
            } else {
                n -= r;
                ans += r;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
