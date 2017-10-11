#include <stdio.h>

int main()
{
    int r, d, n, x, y, rprime, ans = 0;
    scanf("%d %d %d\n", &r, &d, &n);
    while(n--) {
        scanf("%d %d %d", &x, &y, &rprime);
        int a = x * x + y * y;
        int b = (r - d + rprime) * (r - d + rprime);
        int c = (r - rprime) * (r - rprime);
        if(a >= b && a <= c) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
