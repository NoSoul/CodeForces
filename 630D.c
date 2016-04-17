#include <stdio.h>

int main()
{
    int n;
    long long ans;
    scanf("%d", &n);
    if(n == 0) {
        puts("1");
        return 0;
    }
    ans = (long long)n * 3 * (n + 1);
    printf("%I64d\n", ans + 1);
    return 0;
}
