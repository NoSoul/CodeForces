#include <stdio.h>

int Min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int ans = 0;
        int cur = Min(b, c / 2);
        ans += cur * 3;
        b -= cur;
        cur = Min(a, b / 2);
        ans += cur * 3;
        printf("%d\n", ans);
    }
    return 0;
}
