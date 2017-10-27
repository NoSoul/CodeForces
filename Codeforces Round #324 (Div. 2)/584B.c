#include <stdio.h>

#define MOD 1000000007

long long ModExp(long long n, long long m, long long p)
{
    long long k = 1;
    n %= p;
    while(m != 1) {
        if(m & 1) {
            k = (k * n) % p;
        }
        n = (n * n) % p;
        m >>= 1;
    }
    return (n * k) % p;
}

int main()
{
    long long n;
    scanf("%I64d", &n);
    printf("%I64d\n", (ModExp(3, n * 3, MOD) - ModExp(7, n, MOD) + MOD) % MOD);
    return 0;
}
