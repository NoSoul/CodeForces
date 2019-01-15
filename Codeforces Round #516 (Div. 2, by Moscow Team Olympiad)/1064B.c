#include <stdio.h>

int Fun(long long n)
{
    int ret = 0;
    while(n) {
        ret += n & 1;
        n /= 2;
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        long long a;
        scanf("%I64d", &a);
        printf("%I64d\n", 1LL << Fun(a));
    }
    return 0;
}
