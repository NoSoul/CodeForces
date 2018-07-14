#include <stdio.h>

long long GetSum(long long n)
{
    if(n & 1) {
        return n + (n - 1) / 2 * n;
    }
    return n + n / 2 * (n - 1);
}

int main()
{
    int n, m;
    long long ans = 0;
    scanf("%d %d", &n, &m);
    while(m--) {
        int x, d;
        scanf("%d %d", &x, &d);
        if(d >= 0) {
            ans += (long long)x * n + d * GetSum(n - 1);
        } else {
            ans += (long long)x * n + d * (GetSum(n / 2) + GetSum((n - 1) / 2));
        }
    }
    printf("%lf\n", 1.0 * ans / n);
    return 0;
}
