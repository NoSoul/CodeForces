#include <stdio.h>

int main()
{
    int t, a, b, k;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &a, &b, &k);
        long long cur = (long long)(k / 2) * (a - b);
        if(k & 1) {
            cur += a;
        }
        printf("%I64d\n", cur);
    }
    return 0;
}
