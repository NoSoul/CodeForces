#include <stdio.h>

int main()
{
    int a, b, c, n, x, ans = 0;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if(x > b && x < c) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
