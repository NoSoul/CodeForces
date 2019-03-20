#include <stdio.h>

int Min(int a, int b)
{
    return a < b ? a : b;
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, a, b, x, y, ans = 0;
    scanf("%d", &n);
    x = y = 0;
    int pre = -1;
    while(n--) {
        scanf("%d %d", &a, &b);
        int s = Max(x, y);
        int e = Min(a, b);
        if(e >= s) {
            ans += e - s + 1;
            if(s == pre) {
                --ans;
            }
        }
        pre = e;
        x = a;
        y = b;
    }
    printf("%d\n", ans);
    return 0;
}
