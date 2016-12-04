#include <stdio.h>

long long Min(long long a, long long b)
{
    if(a < b) {
        return a;
    }
    return b;
}

int main()
{
    int n, a, b, c;
    long long Ans;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    if(n % 4 == 0) {
        Ans = 0;
    } else if(n % 4 == 1) {
        Ans = Min((long long)a * 3, (long long)c);
        Ans = Min(Ans, (long long)a + (long long)b);
        Ans = Min(Ans, (long long)a + (long long)c * 2);
        Ans = Min(Ans, (long long)b + (long long)c * 3);
    } else if(n % 4 == 2) {
        Ans = Min((long long)a * 2, (long long)b);
        Ans = Min(Ans, (long long)c * 2);
    } else {
        Ans = Min((long long)a, (long long)c * 3);
        Ans = Min(Ans, (long long)b + (long long)c);
    }
    printf("%I64d\n", Ans);
    return 0;
}
