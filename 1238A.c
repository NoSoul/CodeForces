#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        long long x, y;
        scanf("%I64d %I64d", &x, &y);
        puts(x - y == 1 ? "NO" : "YES");
    }
    return 0;
}
