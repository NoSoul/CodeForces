#include <stdio.h>

int main()
{
    int n, a, b, ans = 0;
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 1; i <= n - 1; ++i) {
        if(a >= i && b >= n - i) {
            int cur = a / i;
            if(cur > b / (n - i)) {
                cur = b / (n - i);
            }
            if(ans < cur) {
                ans = cur;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
