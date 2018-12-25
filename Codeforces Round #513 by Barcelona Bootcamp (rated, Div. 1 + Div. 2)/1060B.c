#include <stdio.h>

int Fun(long long n)
{
    int ret = 0;
    while(n) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main()
{
    long long n, m;
    scanf("%I64d", &n);
    m = n;
    if(m < 10) {
        printf("%I64d\n", m);
    } else {
        long long p = 0, q = 1;
        while(m >= 10) {
            p += 9 * q;
            q *= 10;
            m /= 10;
        }
        p += (m - 1) * q;
        printf("%d\n", Fun(p) + Fun(n - p));
    }
    return 0;
}
