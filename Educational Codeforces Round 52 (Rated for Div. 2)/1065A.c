#include <stdio.h>

int main()
{
    int t, s, a, b, c;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d %d", &s, &a, &b, &c);
        long long ans = s / c;
        ans += ans / a * b;
        printf("%I64d\n", ans);
    }
    return 0;
}
