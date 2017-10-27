#include <stdio.h>

__int64 C(int m, int n)
{
    int i;
    __int64 ans = 1;
    if(m > n) {
        return 0;
    }
    if(m >= n / 2) {
        m = n - m;
    }
    for(i = 1; i <= m; ++i, --n) {
        ans = ans * n / i;
    }
    return ans;
}

int main()
{
    int n, m, t, i;
    __int64 Ans;
    scanf("%d %d %d", &n, &m, &t);
    for(Ans = 0, i = 4; i <= n && t - i > 0; ++i) {
        Ans += C(i, n) * C(t - i, m);
    }
    printf("%I64d\n", Ans);
    return 0;
}
