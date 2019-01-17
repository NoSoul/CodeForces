#include <stdio.h>

int main()
{
    long long n;
    char seat[2];
    scanf("%I64d%s", &n, seat);
    int table[] = {4, 5, 6, 3, 2, 1};
    long long ans = (n - 1) / 4 * (6 + 1 + 6 + 3);
    if(!(n & 1)) {
        ans += 6 + 1;
    }
    ans += table[seat[0] - 'a'];
    printf("%I64d\n", ans);
    return 0;
}
