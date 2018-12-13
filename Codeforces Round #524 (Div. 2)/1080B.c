#include <stdio.h>

long long GetSum(long long a1, long long n)
{
    if(a1 < 0) {
        return a1 * n - n * (n - 1);
    }
    return a1 * n + n * (n - 1);
}

int main()
{
    int q;
    scanf("%d", &q);
    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int len = r - l + 1;
        printf("%I64d\n", GetSum(l * ((l & 1) ? -1 : 1), (len + 1) / 2) + GetSum((l + 1) * ((l & 1) ? 1 : -1), len / 2));
    }
    return 0;
}
