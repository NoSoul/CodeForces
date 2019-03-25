#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 2; i < n; ++i) {
        ans += i * (i + 1);
    }
    printf("%d\n", ans);
    return 0;
}
