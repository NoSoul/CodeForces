#include <stdio.h>

int main()
{
    long long n, a, b, c, ans, m, cnt;
    scanf("%I64d %I64d %I64d %I64d", &n, &a, &b, &c);
    if(b - c >= a) {
        ans = n / a;
    } else {
        if(n < b) {
            ans = n / a;
        } else {
            m = n - (b - 1);
            cnt = m / (b - c);
            ans = cnt;
            n -= (b - c) * cnt;
            while(1) {
                cnt = n / b;
                if(cnt == 0) {
                    break;
                }
                ans += cnt;
                n = n + (c - b) * cnt;
            }
            ans += n / a;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
