#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 1;
    for(int i = 2; i <= n; ++i) {
        ans += (i - 1) * 4;
    }
    printf("%d\n", ans);
    return 0;
}
