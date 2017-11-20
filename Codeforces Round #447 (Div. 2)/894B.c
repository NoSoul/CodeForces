#include <stdio.h>

int ExpMod(int a, long long n, int mod)
{
    int ans = 1;
    a %= mod;
    while(n) {
        if(n & 1) {
            ans = ((long long)ans  * a) % mod;
        }
        a = ((long long)a * a) % mod;
        n >>= 1;
    }
    return ans;
}

int main()
{
    long long n, m, k;
    scanf("%I64d %I64d %I64d", &n, &m, &k);
    if(((n + m) & 1) && k == -1) {
        puts("0");
    } else {
        int a = ExpMod(2, n - 1, 1000000007);
        printf("%d\n", ExpMod(a, m - 1, 1000000007));
    }
    return 0;
}
