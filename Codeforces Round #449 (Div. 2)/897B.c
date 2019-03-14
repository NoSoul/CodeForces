#include <stdio.h>

long long Fun(long long num)
{
    int digit[7];
    int len = 0;
    long long m = num;
    while(m) {
        digit[len++] = m % 10;
        m /= 10;
    }
    for(int i = 0; i < len; ++i) {
        num *= 10;
        num += digit[i];
    }
    return num;
}

int main()
{
    int k, p, ans = 0;
    scanf("%d %d", &k, &p);
    for(long long i = 1; i <= k; ++i) {
        ans = (ans + Fun(i)) % p;
    }
    printf("%d\n", ans);
    return 0;
}
